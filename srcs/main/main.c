/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:11:01 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/04/13 12:14:37 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	set_frctl_type(t_frctl *frctl, int argc, char **argv)
{
	t_ftype	ftype;

	if (argc != 4)
		return (0);
	if (!ft_isstrdigit(argv[2]))
		return (0);
	if (ft_strncmp(argv[1], MANDELBROT_STR, 11))
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
	t_winfo	*winfo;

	vars = (t_vars *) malloc(sizeof(t_vars));
	vars->img = NULL;
	vars->w_info = NULL;
	vars->frctl = (t_frctl *) malloc(sizeof(t_frctl));
	if (!set_frctl_type(vars->frctl, argc, argv))
	{
		ft_printf("Usage: ./fractol [...]\n");
		ft_mlx_close(-1, vars);
	}
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(
			vars->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
	img = (t_data *) malloc(sizeof(t_data));
	img->img_ptr = mlx_new_image(vars->win, WINDOW_WIDTH, WINDOW_HEIGHT);
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	vars->img = img;
	winfo = (t_winfo *) malloc(sizeof(t_winfo));
	winfo->zoom = 1;
	vars->w_info = winfo;
	return (vars);
}

int	main(int argc, char **argv)
{
	t_vars	*vars;

	argc += 1;
	(void)argv;
	vars = init_vars(argc, argv);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img_ptr, 0, 0);
	mlx_key_hook(vars->win, ft_mlx_key_hook, vars);
	mlx_hook(vars->win, ON_DESTROY, 0, ft_mlx_close, vars);
	mlx_loop(vars->mlx);
	return (0);
}
