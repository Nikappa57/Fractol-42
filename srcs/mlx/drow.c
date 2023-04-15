/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 23:41:48 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/04/16 01:17:19 by lorenzogaud      ###   ########.fr       */
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

void	ft_mlx_window_reload(t_vars *vars)
{
	t_imgdata	*img;

	img = vars->img;
	mlx_destroy_image(vars->mlx, img->img_ptr);
	img->img_ptr = mlx_new_image(vars->win, WINDOW_WIDTH, WINDOW_HEIGHT);
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	show_frctl(vars);
}
