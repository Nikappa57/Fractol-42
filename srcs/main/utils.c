/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudino <lgaudino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 23:41:48 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/04/12 19:15:47 by lgaudino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;
	int		offset;

	offset = (y * img->line_length + x * (img->bits_per_pixel / 8));
	dst = img->addr + offset;
	*(unsigned int *)dst = color;
}

int	ft_mlx_create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	ft_mlx_close(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESCAPE)
		mlx_destroy_window(vars->mlx, vars->win);
	free(vars->frctl);
	free(vars->img);
	free(vars->w_info);
	exit(EXIT_SUCCESS);
	return (0);
}

int	ft_mlx_key_hook(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESCAPE)
		ft_mlx_close(KEY_ESCAPE, vars);
	return (0);
}
