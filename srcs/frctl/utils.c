/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:22:28 by lgaudino          #+#    #+#             */
/*   Updated: 2023/04/17 23:30:41 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	get_xmove_pos(int x, double zoom, double move_x)
{
	return (1.5 * (x - WINDOW_WIDTH / 2)
		/ (0.7 * zoom * WINDOW_WIDTH) + move_x);
}

double	get_ymove_pos(int y, double zoom, double move_y)
{
	return ((y - WINDOW_HEIGHT / 2)
		/ (0.5 * zoom * WINDOW_HEIGHT) + move_y);
}

void	mouse_update_julia(t_vars *vars)
{
	vars->frctl->julia_mx = (get_xmove_pos(
				vars->w_info->mouse_x, vars->w_info->zoom, vars->w_info->m_x)
			/ vars->w_info->zoom) * 1.5;
	vars->frctl->julia_my = get_ymove_pos(
			vars->w_info->mouse_y, vars->w_info->zoom, vars->w_info->m_y)
		/ vars->w_info->zoom;
}

int	check_radius(t_vars *vars, t_frctl_info info, int x, int y)
{
	double	mag;

	mag = info.newre * info.newre + info.newim * info.newim;
	if (mag > vars->frctl->radius)
	{
		ft_mlx_pixel_put(vars->img, x, y,
			get_color(vars, info.i, sqrt(mag)));
		return (1);
	}
	return (0);
}

#include <stdio.h>
int	set_frctl_type(t_frctl *frctl, t_winfo *w_info, int argc, char **argv)
{
	t_ftype	ftype;

	if (argc < 3)
		return (0);
	if (!ft_isstrdigit(argv[2]))
		return (0);
	if (!ft_strncmp(argv[1], MANDELBROT_STR, 11))
		ftype = MANDELBROT;
	else if (!ft_strncmp(argv[1], JULIA_STR, 6))
		ftype = JULIA;
	else
		return (0);
	if (ftype == MANDELBROT && argc != 3)
		return (0);
	if (ftype == JULIA)
	{
		if (argc == 5)
		{
			if (!ft_isstrdouble(argv[3]) || !ft_isstrdouble(argv[4]))
				return (0);
			frctl->julia_mx = ft_atodb(argv[3]);
			frctl->julia_my = ft_atodb(argv[4]);
			w_info->track_mouse = 0;
		}
		else if (argc == 3)
		{
			frctl->julia_mx = 0;
			frctl->julia_my = 0;
			w_info->track_mouse = 1;
		}
		else
			return (0);
	}
	frctl->type = ftype;
	frctl->maxiter = ft_atoi(argv[2]);
	return (1);
}
