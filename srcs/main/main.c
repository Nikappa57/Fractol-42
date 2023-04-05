/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:11:01 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/04/06 01:08:30 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_data	img;
	t_vars	vars;

	argc += 1;
	argv += 1;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(
			vars.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
	img.img = mlx_new_image(vars.win, WINDOW_WIDTH, WINDOW_HEIGHT);
	img.addr = mlx_get_data_addr(
			img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	ft_mlx_pixel_put(&img, 10, 10, 0x00FF0000);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_key_hook(vars.win, ft_mlx_key_hook, &vars);
	mlx_hook(vars.win, ON_DESTROY, 0, ft_mlx_close, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
