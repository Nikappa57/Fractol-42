/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:53:19 by lgaudino          #+#    #+#             */
/*   Updated: 2023/04/21 13:13:40 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	mandelbrot(t_vars *vars, t_frctl_info info, int x, int y)
{
	info.pr = get_xmove_pos(x, vars->w_info->zoom, vars->w_info->m_x);
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

static void	julia(t_vars *vars, t_frctl_info info, int x, int y)
{
	info.newre = get_xmove_pos(x, vars->w_info->zoom, vars->w_info->m_x);
	info.ore = 0;
	info.oim = 0;
	info.i = 0;
	while (info.i++ < vars->frctl->maxiter)
	{
		info.ore = info.newre;
		info.oim = info.newim;
		info.newre = info.ore * info.ore - info.oim * info.oim
			+ vars->frctl->julia_mx;
		info.newim = vars->frctl->inc * info.ore * info.oim
			+ vars->frctl->julia_my;
		if (check_radius(vars, info, x, y))
			break ;
	}
}

static void	newton(t_vars *vars, t_frctl_info info, int x, int y)
{
	double	saved_mag;
	int		saved_iter;

	saved_mag = 0;
	info.nwtn_incx = -vars->w_info->zoom + 2 * vars->w_info->zoom
		/ WINDOW_WIDTH * x;
	info.ore = info.nwtn_incx + vars->w_info->m_x;
	info.oim = info.nwtn_incy + vars->w_info->m_y;
	info.i = 0;
	while (info.i++ < vars->frctl->maxiter)
	{
		info.newre = newton_re(info);
		info.newim = newton_im(info);
		info.ore = info.newre * vars->frctl->inc;
		info.oim = info.newim * vars->frctl->inc;
		newton_check_radius(info, vars->frctl->radius, &saved_mag, &saved_iter);
	}
	if (saved_mag)
		ft_mlx_pixel_put(vars->img, x, y,
			get_color(vars, saved_iter, sqrt(saved_mag)));
}

static void	set_y_info(t_vars *vars, t_frctl_info *info, t_ftype f_type, int y)
{
	if (f_type == MANDELBROT)
		info->pi = get_ymove_pos(y, vars->w_info->zoom, vars->w_info->m_y);
	else if (f_type == JULIA)
		info->newim = get_ymove_pos(y, vars->w_info->zoom, vars->w_info->m_y);
	else
		info->nwtn_incy = -vars->w_info->zoom + 2 * vars->w_info->zoom
			/ WINDOW_HEIGHT * y;
}

void	show_frctl(t_vars *vars)
{
	int				x;
	int				y;
	t_ftype			f_type;
	t_frctl_info	info;

	f_type = vars->frctl->type;
	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		set_y_info(vars, &info, f_type, y);
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			if (f_type == MANDELBROT)
				mandelbrot(vars, info, x++, y);
			else if (f_type == JULIA)
				julia(vars, info, x++, y);
			else if (f_type == NEWTON)
				newton(vars, info, x++, y);
		}
		y++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img_ptr, 0, 0);
	set_info(vars);
}
