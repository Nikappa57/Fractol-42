/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:53:19 by lgaudino          #+#    #+#             */
/*   Updated: 2023/04/13 22:59:51 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#define RADIUS 4

void	mandelbrot_helper(t_vars *vars, int x, int y)
{
	int				i;
	t_mandel_info	info;

	info.pr = 1.5 * (x - WINDOW_WIDTH / 2)
		/ (0.7 * vars->w_info->zoom * WINDOW_WIDTH) + vars->w_info->m_x;
	info.pi = (y - WINDOW_HEIGHT / 2)
		/ (0.5 * vars->w_info->zoom * WINDOW_HEIGHT) + vars->w_info->m_y;
	info.newre = 0;
	info.newim = 0;
	info.ore = 0;
	info.oim = 0;
	i = 0;
	while (i++ < vars->frctl->maxiter)
	{
		info.ore = info.newre;
		info.oim = info.newim;
		info.newre = info.ore * info.ore - info.oim * info.oim + info.pr;
		info.newim = vars->frctl->inc * info.ore * info.oim + info.pi;
		if ((info.newre * info.newre + info.newim * info.newim) > RADIUS)
		{
			ft_mlx_pixel_put(vars->img, x, y, 0x00FF0000);
			break ;
		}
	}
}

void	mandelbrot(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
			mandelbrot_helper(vars, x++, y);
		y++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img_ptr, 0, 0);
}
