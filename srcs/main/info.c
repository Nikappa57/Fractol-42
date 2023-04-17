/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudino <lgaudino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 01:35:08 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/04/17 12:52:48 by lgaudino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	drow_info(t_vars *vars, t_info info)
{
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
}

void	set_info(t_vars *vars)
{
	t_info	info;

	info.iter = ft_itoa(vars->frctl->maxiter);
	if (vars->frctl->maxiter == MAX_ITER)
		info.iter = ft_strjoin_gnl(info.iter, " [MAX]");
	else if (vars->frctl->maxiter > MAX_ITER)
		info.iter = ft_strjoin_gnl(info.iter, " [> MAX]");
	if (vars->frctl->maxiter == MIN_ITER)
		info.iter = ft_strjoin_gnl(info.iter, " [MIN]");
	else if (vars->frctl->maxiter < MIN_ITER)
		info.iter = ft_strjoin_gnl(info.iter, " [< MAX]");
	info.inc = ft_strjoin_gnl(ft_itoa(vars->frctl->inc * 100), "/100");
	info.radius = ft_itoa(sqrt(vars->frctl->radius));
	info.color = ft_itoa(vars->frctl->color + 1);
	info.zoom = ft_strjoin_gnl(ft_itoa(vars->w_info->zoom * 100), "/100");
	drow_info(vars, info);
	free(info.iter);
	free(info.inc);
	free(info.radius);
	free(info.zoom);
	free(info.color);
}

int	set_loading(t_vars *vars)
{
	if (!vars->w_info->loading)
	{
		mlx_string_put(vars->mlx, vars->win, 15, 100, WHITE, "LOADING...");
		vars->w_info->loading = 0;
	}
	return (0);
}
