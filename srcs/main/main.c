/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:11:01 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/04/13 22:57:52 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	set_frctl_type(t_frctl *frctl, int argc, char **argv)
{
	t_ftype	ftype;

	if (argc != 3)
		return (0);
	if (!ft_isstrdigit(argv[2]))
		return (0);
	if (!ft_strncmp(argv[1], MANDELBROT_STR, 11))
		ftype = MANDELBROT;
	else
		return (0);
	frctl->type = ftype;
	frctl->maxiter = ft_atoi(argv[2]);
	return (1);
}

static t_vars	*init_vars(int argc, char **argv)
{
	t_vars	*vars;
	t_data	*img;

	vars = (t_vars *) malloc(sizeof(t_vars));
	vars->img = NULL;
	vars->w_info = NULL;
	vars->frctl = (t_frctl *) malloc(sizeof(t_frctl));
	if (!set_frctl_type(vars->frctl, argc, argv))
		ft_mlx_close(KEY_ERROR, vars);
	vars->frctl->inc = 2;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(
			vars->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
	img = (t_data *) malloc(sizeof(t_data));
	img->img_ptr = mlx_new_image(vars->win, WINDOW_WIDTH, WINDOW_HEIGHT);
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	vars->img = img;
	vars->w_info = (t_winfo *) malloc(sizeof(t_winfo));
	vars->w_info->zoom = 1;
	vars->w_info->m_x = -0.5;
	vars->w_info->m_y = 0;
	return (vars);
}

int	main(int argc, char **argv)
{
	t_vars	*vars;

	vars = init_vars(argc, argv);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img_ptr, 0, 0);
	mlx_key_hook(vars->win, ft_mlx_key_hook, vars);
	mlx_hook(vars->win, ON_DESTROY, 0, ft_mlx_destroy, vars);
	show_frctl(vars);
	mlx_loop(vars->mlx);
	return (0);
}
