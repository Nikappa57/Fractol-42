/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 23:48:52 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/04/20 17:17:51 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_mlx_close(int keycode, t_vars *vars)
{
	if (keycode == KEY_ERROR)
		print_usage();
	if (keycode == KEY_ESCAPE)
	{
		mlx_destroy_window(vars->mlx, vars->win);
	}
	if (vars->frctl)
		free(vars->frctl);
	if (vars->img)
		free(vars->img);
	if (vars->w_info)
		free(vars->w_info);
	if (vars->palette)
		free(vars->palette);
	free(vars);
	exit(EXIT_SUCCESS);
	return (0);
}

int	ft_mlx_destroy(void *data)
{
	(void)data;
	exit(0);
}
