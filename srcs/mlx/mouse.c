/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudino <lgaudino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 21:31:17 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/04/22 15:54:13 by lgaudino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	get_xmove_pos_mouse(int x, t_winfo *w_info)
{
	return (1.5 * (x - WINDOW_WIDTH / 2)
		/ (1.7 * w_info->zoom * WINDOW_WIDTH));
}

static double	get_ymove_pos_mouse(int y, t_winfo *w_info)
{
	return ((y - WINDOW_HEIGHT / 2)
		/ (1.5 * w_info->zoom * WINDOW_HEIGHT));
}

int	mouse_hook(int keycode, int x, int y, t_vars *vars)
{
	if ((keycode == SCROLL_UP) || (keycode == SCROLL_DOWN))
	{
		zoom(vars->w_info, vars->frctl->type, keycode == SCROLL_DOWN);
		vars->w_info->m_x += get_xmove_pos_mouse(x, vars->w_info);
		vars->w_info->m_y += get_ymove_pos_mouse(y, vars->w_info);
		ft_mlx_window_reload(vars);
	}
	return (0);
}

int	mousemove_hook(int x, int y, t_vars *vars)
{
	if (((vars->w_info->mouse_x != x) || (vars->w_info->mouse_y != y))
		&& x < WINDOW_WIDTH && x > 0 && y < WINDOW_HEIGHT && y > 0)
	{
		vars->w_info->mouse_x = x;
		vars->w_info->mouse_y = y;
		if (vars->w_info->track_mouse)
			mouse_update_julia(vars);
		ft_mlx_window_reload(vars);
	}
	return (0);
}
