/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudino <lgaudino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 00:25:42 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/04/17 12:45:10 by lgaudino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_winfo(t_winfo *w_info, t_ftype f_type)
{
	w_info->loading = 0;
	if (f_type == MANDELBROT)
	{
		w_info->zoom = 0.68;
		w_info->m_x = -0.65;
		w_info->m_y = 0;
		w_info->mouse_x = 0;
		w_info->mouse_y = 0;
		w_info->track_mouse = 0;
	}
	else if (f_type == JULIA)
	{
		w_info->zoom = 0.6;
		w_info->m_x = 0;
		w_info->m_y = 0;
		w_info->mouse_x = 0;
		w_info->mouse_y = 0;
		w_info->track_mouse = 1;
	}
}

void	init_frctl(t_frctl *frctl, int *win)
{
	(void)win;
	frctl->inc = 2;
	frctl->radius = 4;
	frctl->color = 0;
	if (frctl->type == JULIA)
	{
		frctl->julia_mx = 0;
		frctl->julia_my = 0;
		// TODO:
		// mlx_mouse_move(win, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	}
}

void	init_palette(t_vars *vars)
{
	vars->palette = (int *) malloc(sizeof(int) * COLOR_N * PALETTE_N);
	set_palette_1(vars->palette);
	set_palette_2(vars->palette + COLOR_N);
	set_palette_3(vars->palette + COLOR_N * 2);
}

t_vars	*init_vars(int argc, char **argv)
{
	t_vars		*vars;
	t_imgdata	*img;

	vars = (t_vars *) malloc(sizeof(t_vars));
	vars->img = NULL;
	vars->w_info = NULL;
	vars->palette = NULL;
	vars->frctl = (t_frctl *) malloc(sizeof(t_frctl));
	if (!set_frctl_type(vars->frctl, argc, argv))
		ft_mlx_close(KEY_ERROR, vars);
	init_frctl(vars->frctl, vars->win);
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(
			vars->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
	img = (t_imgdata *) malloc(sizeof(t_imgdata));
	img->img_ptr = mlx_new_image(vars->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	vars->img = img;
	vars->w_info = (t_winfo *) malloc(sizeof(t_winfo));
	init_winfo(vars->w_info, vars->frctl->type);
	init_palette(vars);
	return (vars);
}
