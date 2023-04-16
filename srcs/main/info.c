/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 01:35:08 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/04/16 19:53:35 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_info(t_vars *vars)
{
	t_info	info;

	info.iter = ft_itoa(vars->frctl->maxiter);
	if (vars->frctl->maxiter >= MAX_ITER)
		info.iter = ft_strjoin_gnl(info.iter, " [MAX]");
	info.inc = ft_strjoin_gnl(ft_itoa(vars->frctl->inc * 100), "/100");
	info.radius = ft_itoa(sqrt(vars->frctl->radius));
	info.color = ft_itoa(vars->frctl->color + 1);
	info.zoom = ft_strjoin_gnl(ft_itoa(vars->w_info->zoom * 100), "/100");
	mlx_string_put(vars->mlx, vars->win, 15, 15, WHITE, "Max iter:");
	mlx_string_put(vars->mlx, vars->win, 15, 30, WHITE, "Zoom:");
	mlx_string_put(vars->mlx, vars->win, 15, 45, WHITE, "Inc:");
	mlx_string_put(vars->mlx, vars->win, 15, 60, WHITE, "Radius:");
	mlx_string_put(vars->mlx, vars->win, 15, 75, WHITE, "Palette:");
	mlx_string_put(vars->mlx, vars->win, 80, 15, WHITE, info.iter);
	mlx_string_put(vars->mlx, vars->win, 80, 30, WHITE, info.zoom);
	mlx_string_put(vars->mlx, vars->win, 80, 45, WHITE, info.inc);
	mlx_string_put(vars->mlx, vars->win, 80, 60, WHITE, info.radius);
	mlx_string_put(vars->mlx, vars->win, 80, 75, WHITE, info.color);
	free(info.iter);
	free(info.inc);
	free(info.radius);
	free(info.zoom);
	free(info.color);
}
