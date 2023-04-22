/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudino <lgaudino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:22:28 by lgaudino          #+#    #+#             */
/*   Updated: 2023/04/22 15:54:03 by lgaudino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	get_xmove_pos(int x, t_winfo *w_info)
{
	return (1.5 * (x - WINDOW_WIDTH / 2)
		/ (0.7 * w_info->zoom * WINDOW_WIDTH) + w_info->m_x);
}

double	get_ymove_pos(int y, t_winfo *w_info)
{
	return ((y - WINDOW_HEIGHT / 2)
		/ (0.5 * w_info->zoom * WINDOW_HEIGHT) + w_info->m_y);
}

void	mouse_update_julia(t_vars *vars)
{
	vars->frctl->julia_mx = (get_xmove_pos(
				vars->w_info->mouse_x, vars->w_info)
			/ vars->w_info->zoom) * 1.5;
	vars->frctl->julia_my = get_ymove_pos(
			vars->w_info->mouse_y, vars->w_info)
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
