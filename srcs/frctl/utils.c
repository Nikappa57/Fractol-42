/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:22:28 by lgaudino          #+#    #+#             */
/*   Updated: 2023/04/16 19:38:33 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_xmove_pos(int x, double zoom, double move_x)
{
	return (1.5 * (x - WINDOW_WIDTH / 2)
		/ (0.7 * zoom * WINDOW_WIDTH) + move_x);
}

int	get_ymove_pos(int y, double zoom, double move_y)
{
	return ((y - WINDOW_HEIGHT / 2)
		/ (0.5 * zoom * WINDOW_HEIGHT) + move_y);
}

int	check_radius(t_vars *vars, t_mandel_info info, int x, int y)
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

int	set_frctl_type(t_frctl *frctl, int argc, char **argv)
{
	t_ftype	ftype;

	if (argc != 3)
		return (0);
	if (!ft_isstrdigit(argv[2]))
		return (0);
	if (!ft_strncmp(argv[1], MANDELBROT_STR, 11))
		ftype = MANDELBROT;
	else if (!ft_strncmp(argv[1], JULIA_STR, 6))
		ftype = JULIA;
	else
		return (0);
	frctl->type = ftype;
	frctl->maxiter = ft_atoi(argv[2]);
	return (1);
}
