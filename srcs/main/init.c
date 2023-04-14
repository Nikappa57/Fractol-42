/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 00:25:42 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/04/14 20:42:58 by lorenzogaud      ###   ########.fr       */
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

void	init_winfo(t_winfo *w_info)
{
	w_info->loading = 0;
	w_info->zoom = 1;
	w_info->m_x = -0.5;
	w_info->m_y = 0;
}

void	init_frctl(t_frctl *frctl)
{
	frctl->inc = 2;
	frctl->radius = 4;
}

void	set_info(t_vars *vars)
{
	char	*iter;
	char	*zoom;
	char	*inc;
	char	*radius;

	if (vars->frctl->maxiter > MAX_ITER)
		iter = ft_strdup("MAX");
	else
		iter = ft_itoa(vars->frctl->maxiter);
	inc = ft_strjoin_gnl(ft_itoa(vars->frctl->inc * 100 - 200), "%");
	radius = ft_itoa(vars->frctl->radius);
	zoom = ft_strjoin_gnl(ft_itoa(vars->w_info->zoom * 100 - 100), "%");
	mlx_string_put(vars->mlx, vars->win, 15, 15, WHITE, "Max iter:");
	mlx_string_put(vars->mlx, vars->win, 15, 30, WHITE, "Zoom:");
	mlx_string_put(vars->mlx, vars->win, 15, 45, WHITE, "Inc+:");
	mlx_string_put(vars->mlx, vars->win, 15, 60, WHITE, "Radius:");
	mlx_string_put(vars->mlx, vars->win, 80, 15, WHITE, iter);
	mlx_string_put(vars->mlx, vars->win, 80, 30, WHITE, zoom);
	mlx_string_put(vars->mlx, vars->win, 80, 45, WHITE, inc);
	mlx_string_put(vars->mlx, vars->win, 80, 60, WHITE, radius);
	free(iter);
	free(inc);
	free(radius);
	free(zoom);
}

t_vars	*init_vars(int argc, char **argv)
{
	t_vars		*vars;
	t_imgdata	*img;

	vars = (t_vars *) malloc(sizeof(t_vars));
	vars->img = NULL;
	vars->w_info = NULL;
	vars->frctl = (t_frctl *) malloc(sizeof(t_frctl));
	if (!set_frctl_type(vars->frctl, argc, argv))
		ft_mlx_close(KEY_ERROR, vars);
	init_frctl(vars->frctl);
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(
			vars->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
	img = (t_imgdata *) malloc(sizeof(t_imgdata));
	img->img_ptr = mlx_new_image(vars->win, WINDOW_WIDTH, WINDOW_HEIGHT);
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	vars->img = img;
	vars->w_info = (t_winfo *) malloc(sizeof(t_winfo));
	init_winfo(vars->w_info);
	return (vars);
}
