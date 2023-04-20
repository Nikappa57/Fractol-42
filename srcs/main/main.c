/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:11:01 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/04/20 17:18:01 by lorenzogaud      ###   ########.fr       */
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
	mlx_mouse_hook(vars->win, mouse_hook, vars);
	show_frctl(vars);
	mlx_loop(vars->mlx);
	return (0);
}

// TODO: mouse zoom
// TODO: controllare leaks