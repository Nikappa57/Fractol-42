/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:53:19 by lgaudino          #+#    #+#             */
/*   Updated: 2023/04/16 22:45:12 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	mandelbrot(t_vars *vars, int x, int y)
{
	t_frctl_info	info;

	info.pr = get_xmove_pos(x, vars->w_info->zoom, vars->w_info->m_x);
	info.pi = get_ymove_pos(y, vars->w_info->zoom, vars->w_info->m_y);
	info.newre = 0;
	info.newim = 0;
	info.ore = 0;
	info.oim = 0;
	info.i = 0;
	while (info.i++ < vars->frctl->maxiter)
	{
		info.ore = info.newre;
		info.oim = info.newim;
		info.newre = info.ore * info.ore - info.oim * info.oim + info.pr;
		info.newim = vars->frctl->inc * info.ore * info.oim + info.pi;
		if (check_radius(vars, info, x, y))
			break ;
	}
}

static void	julia(t_vars *vars, int x, int y)
{
	t_frctl_info	info;

	info.newre = get_xmove_pos(x, vars->w_info->zoom, vars->w_info->m_x);
	info.newim = get_ymove_pos(y, vars->w_info->zoom, vars->w_info->m_y);
	info.ore = 0;
	info.oim = 0;
	info.i = 0;
	while (info.i++ < vars->frctl->maxiter)
	{
		info.ore = info.newre;
		info.oim = info.newim;
		info.newre = info.ore * info.ore - info.oim * info.oim + vars->frctl->julia_mx;
		info.newim = vars->frctl->inc * info.ore * info.oim + vars->frctl->julia_my;
		if (check_radius(vars, info, x, y))
			break ;
	}
}

void	show_frctl(t_vars *vars)
{
	int		x;
	int		y;
	t_ftype	f_type;

	f_type = vars->frctl->type;
	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			if (f_type == MANDELBROT)
				mandelbrot(vars, x++, y);
			else if (f_type == JULIA)
				julia(vars, x++, y);
		}
		y++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img_ptr, 0, 0);
	set_info(vars);
}
