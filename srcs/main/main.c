/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudino <lgaudino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:11:01 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/04/17 12:47:20 by lgaudino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_vars	*vars;

	vars = init_vars(argc, argv);
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_hook(vars->win, ON_DESTROY, 0, ft_mlx_destroy, vars);
	mlx_hook(vars->win, ON_MOUSEMOVE, 0, mousemove_hook, vars);
	mlx_loop_hook(vars->mlx, set_loading, vars);
	show_frctl(vars);
	mlx_loop(vars->mlx);
	return (0);
}

// TODO: mouse zoom
// TODO: loading
// TODO: max value