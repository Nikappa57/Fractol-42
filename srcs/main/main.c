/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:11:01 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/04/06 00:30:50 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_data	img;
	t_vars	mlx;

	argc += 1;
	argv += 1;
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(
			mlx.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
	img.img = mlx_new_image(mlx.win, WINDOW_WIDTH, WINDOW_HEIGHT);
	img.addr = mlx_get_data_addr(
			img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	ft_mlx_pixel_put(&img, 10, 10, 0x00FF0000);
	mlx_put_image_to_window(mlx.mlx, mlx.win, img.img, 0, 0);
	mlx_hook(mlx.win, 2, 1L << 0, ft_mlx_key_hook, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
