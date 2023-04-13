/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 23:41:48 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/04/13 23:53:01 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mlx_pixel_put(t_imgdata *img, int x, int y, int color)
{
	char	*dst;
	int		offset;

	offset = (y * img->line_length + x * (img->bits_per_pixel / 8));
	dst = img->addr + offset;
	*(unsigned int *)dst = color;
}

// TODO: controllare leaks prendo la x
int	ft_mlx_close(int keycode, t_vars *vars)
{
	if (keycode == KEY_ERROR)
		ft_printf("Usage: ./fractol [...]\n");
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
	free(vars);
	exit(EXIT_SUCCESS);
	return (0);
}

int	ft_mlx_destroy(void *data)
{
	(void)data;
	exit(0);
}

// TODO
void	ft_mlx_loading(t_vars *vars, int show)
{
	int			x;
	int			y;
	t_imgdata	*img;

	img = vars->img;
	if (show)
	{
		img->loading_img_ptr = mlx_new_image(
				vars->win, LOADING_WIDTH, LOADING_HEIGHT);
		img->loading_addr = mlx_get_data_addr(img->loading_img_ptr,
				&img->bits_per_pixel, &img->line_length, &img->endian);
		y = 0;
		while (y < LOADING_HEIGHT)
		{
			x = 0;
			while (x < LOADING_WIDTH)
				ft_mlx_pixel_put(img->loading_img_ptr, x++, y, 0x00FF0000);
			y++;
		}
		mlx_put_image_to_window(
			vars->mlx, vars->win, img->loading_img_ptr, 0, 0);
	}
	else
		mlx_destroy_image(vars->mlx, img->loading_img_ptr);
}

void	ft_mlx_window_reload(t_vars *vars)
{
	t_imgdata	*img;

	img = vars->img;
	mlx_destroy_image(vars->mlx, img->img_ptr);
	img->img_ptr = mlx_new_image(vars->win, WINDOW_WIDTH, WINDOW_HEIGHT);
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	// ft_mlx_loading(vars, 1);
	show_frctl(vars);
	// ft_mlx_loading(vars, 0);
}
