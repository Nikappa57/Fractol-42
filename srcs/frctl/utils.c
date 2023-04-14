/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:22:28 by lgaudino          #+#    #+#             */
/*   Updated: 2023/04/14 20:04:15 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	show_frctl(t_vars *vars)
{
	// TODO
	// mlx_string_put(vars->mlx, vars->win, 200, 30, WHITE, "LOADING...");
	vars->w_info->loading = 1;
	if (vars->frctl->type == MANDELBROT)
		mandelbrot(vars);
	vars->w_info->loading = 0;
	set_info(vars);
}
