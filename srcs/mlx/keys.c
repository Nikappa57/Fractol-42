/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 23:27:18 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/04/16 01:03:58 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(t_winfo *w_info, int plus)
{
	if (plus)
		w_info->zoom *= 1.1;
	else
		w_info->zoom /= 1.1;
}

void	incresse_iterations(t_frctl *frctl)
{
	if (frctl->maxiter == 0)
		frctl->maxiter = 1;
	else if (frctl->maxiter < MAX_ITER / 4)
		frctl->maxiter *= 2;
	else if (frctl->maxiter < MAX_ITER)
		frctl->maxiter += MAX_ITER / 4;
	else
		ft_printf("Max iterations reached\n");
}

void	decrease_iterations(t_frctl *frctl)
{
	if (frctl->maxiter < 2)
	{
		ft_printf("Zero iterations reached\n");
		frctl->maxiter = 1;
	}
	else if (frctl->maxiter < MAX_ITER / 2)
		frctl->maxiter /= 2;
	else
		frctl->maxiter -= MAX_ITER / 4;
}

void	move(t_winfo *w_info, int x, int y)
{
	w_info->m_x += x * 0.1 / w_info->zoom;
	w_info->m_y += y * 0.1 / w_info->zoom;
}

void	mandel_inc(t_frctl *frctl, int plus)
{
	if (plus)
		frctl->inc += 0.1;
	else
		frctl->inc -= 0.1;
}

void	mandel_radius(t_frctl *frctl, int plus)
{
	if (plus)
		frctl->radius *= 2;
	else
		frctl->radius /= 2;
	if (frctl->radius < 1)
		frctl->radius = 1;
}

void	shift_color(t_frctl *frctl)
{
	frctl->color++;
	if (frctl->color == PALETTE_N)
		frctl->color = 0;
}

int	ft_mlx_key_hook(int keycode, t_vars *vars)
{
	if (vars->w_info->loading == 1)
		return (0);
	ft_printf("kye: %d\n", keycode);
	ft_printf("ITER: %d\n", vars->frctl->maxiter);
	if (keycode == KEY_ESCAPE)
		ft_mlx_close(KEY_ESCAPE, vars);
	else if (keycode == KEY_I)
		incresse_iterations(vars->frctl);
	else if (keycode == KEY_O)
		decrease_iterations(vars->frctl);
	else if ((keycode == KEY_PAD_ADD) || (keycode == KEY_MINUS))
		zoom(vars->w_info, keycode == KEY_PAD_ADD);
	else if (keycode == KEY_R)
	{
		init_winfo(vars->w_info);
		init_frctl(vars->frctl);
	}
	else if ((keycode == KEY_UP) || (keycode == KEY_W))
		move(vars->w_info, 0, -1);
	else if ((keycode == KEY_LEFT) || (keycode == KEY_A))
		move(vars->w_info, -1, 0);
	else if ((keycode == KEY_DOWN) || (keycode == KEY_S))
		move(vars->w_info, 0, 1);
	else if ((keycode == KEY_RIGHT) || (keycode == KEY_D))
		move(vars->w_info, 1, 0);
	else if ((keycode == KEY_K) || (keycode == KEY_L))
	{
		if (vars->frctl->type == MANDELBROT)
			mandel_inc(vars->frctl, keycode == KEY_K);
	}
	else if ((keycode == KEY_N) || (keycode == KEY_M))
	{
		if (vars->frctl->type == MANDELBROT)
			mandel_radius(vars->frctl, keycode == KEY_N);
	}
	else if (keycode == KEY_C)
		shift_color(vars->frctl);
	else
		return (-1);
	ft_mlx_window_reload(vars);
	return (0);
}
