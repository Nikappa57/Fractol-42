/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 23:27:18 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/04/16 20:25:56 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	hook_actions(int keycode, t_vars *vars)
{
	if ((keycode == KEY_PAD_ADD) || (keycode == KEY_MINUS))
		zoom(vars->w_info, keycode == KEY_PAD_ADD);
	else if ((keycode == KEY_UP) || (keycode == KEY_W))
		move(vars->w_info, 0, -1);
	else if ((keycode == KEY_LEFT) || (keycode == KEY_A))
		move(vars->w_info, -1, 0);
	else if ((keycode == KEY_DOWN) || (keycode == KEY_S))
		move(vars->w_info, 0, 1);
	else if ((keycode == KEY_RIGHT) || (keycode == KEY_D))
		move(vars->w_info, 1, 0);
	else
		return (0);
	return (1);
}

static int	hook_settings(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESCAPE)
		ft_mlx_close(KEY_ESCAPE, vars);
	else if (keycode == KEY_I)
		return (increase_iterations(vars->frctl));
	else if (keycode == KEY_O)
		return (decrease_iterations(vars->frctl));
	else if (keycode == KEY_C)
		shift_color(vars->frctl);
	else if (keycode == KEY_R)
	{
		init_winfo(vars->w_info, vars->frctl->type);
		init_frctl(vars->frctl);
	}
	else
		return (0);
	return (1);
}

static int	hook_frctl_actions(int keycode, t_vars *vars)
{
	if ((keycode == KEY_K) || (keycode == KEY_L))
	{
		if ((vars->frctl->type == MANDELBROT)
			|| (vars->frctl->type == JULIA))
			mandel_inc(vars->frctl, keycode == KEY_K);
		else
			return (0);
	}
	else if ((keycode == KEY_N) || (keycode == KEY_M))
	{
		if ((vars->frctl->type == MANDELBROT)
			|| (vars->frctl->type == JULIA))
			mandel_radius(vars->frctl, keycode == KEY_N);
		else
			return (0);
	}
	else
		return (0);
	return (1);
}

int	ft_mlx_key_hook(int keycode, t_vars *vars)
{
	if (!hook_actions(keycode, vars)
		&& !hook_settings(keycode, vars)
		&& !hook_frctl_actions(keycode, vars))
		return (-1);
	ft_mlx_window_reload(vars);
	return (0);
}
