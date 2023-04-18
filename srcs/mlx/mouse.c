/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudino <lgaudino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 21:31:17 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/04/18 13:19:26 by lgaudino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_hook(int keycode, int x, int y, t_vars *vars)
{
	x = y;
	ft_printf("CODE: %d\n", keycode);
	if ((keycode == SCROLL_UP) || (keycode == SCROLL_DOWN))
	{
		zoom(vars->w_info, keycode == SCROLL_DOWN);
		ft_mlx_window_reload(vars);
	}
	return (0);
}

int	mousemove_hook(int x, int y, t_vars *vars)
{
	if (vars->frctl->type == JULIA && vars->w_info->track_mouse
		&& ((vars->w_info->mouse_x != x) || (vars->w_info->mouse_y != y))
		&& x < WINDOW_WIDTH && x > 0 && y < WINDOW_HEIGHT && y > 0)
	{
		vars->w_info->mouse_x = x;
		vars->w_info->mouse_y = y;
		mouse_update_julia(vars);
		ft_mlx_window_reload(vars);
	}
	return (0);
}
