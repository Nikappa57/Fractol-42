/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudino <lgaudino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:11:01 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/04/12 19:12:51 by lgaudino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_vars	*init(void)
{
	t_vars	*vars;
	t_data	*img;

	vars = (t_vars *) malloc(sizeof(t_vars) + 1);
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(
			vars->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
	img = (t_data *) malloc(sizeof(t_data) + 1);
	img->img_ptr = mlx_new_image(vars->win, WINDOW_WIDTH, WINDOW_HEIGHT);
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	vars->img = img;
	return (vars);
}

int	main(int argc, char **argv)
{
	t_vars	*vars;

	argc += 1;
	(void)argv;
	vars = init();
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img_ptr, 0, 0);
	mlx_key_hook(vars->win, ft_mlx_key_hook, vars);
	mlx_hook(vars->win, ON_DESTROY, 0, ft_mlx_close, vars);
	mlx_loop(vars->mlx);
	return (0);
}
