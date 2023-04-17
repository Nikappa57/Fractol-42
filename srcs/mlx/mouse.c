/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 21:31:17 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/04/16 22:51:23 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mousemove_hook(int x, int y, t_vars *vars)
{
	if (vars->frctl->type == JULIA
		&& ((vars->w_info->mouse_x != x) || (vars->w_info->mouse_y != y))
		&& x < WINDOW_WIDTH && x > 0 && y < WINDOW_HEIGHT && y > 0)
	{
		vars->w_info->mouse_x = x;
		vars->w_info->mouse_y = y;
		mouse_update_julia(vars);
		ft_mlx_window_reload(vars);
		ft_printf("x: %d, y: %d\n", x, y);
	}
	return (0);
}
