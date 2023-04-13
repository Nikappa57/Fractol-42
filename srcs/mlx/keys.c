/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 23:27:18 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/04/14 01:10:29 by lorenzogaud      ###   ########.fr       */
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
	else if (frctl->maxiter < 25)
		frctl->maxiter *= 2;
	else if (frctl->maxiter < 100)
		frctl->maxiter += 25;
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
	else if (frctl->maxiter < 50)
		frctl->maxiter /= 2;
	else
		frctl->maxiter -= 20;
}

void	move(t_winfo *w_info, int x, int y)
{
	w_info->m_x += x * 0.1 / w_info->zoom;
	w_info->m_y += y * 0.1 / w_info->zoom;
}

int	ft_mlx_key_hook(int keycode, t_vars *vars)
{
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
		init_winfo(vars->w_info);
	else if ((keycode == KEY_UP) || (keycode == KEY_W))
		move(vars->w_info, 0, -1);
	else if ((keycode == KEY_LEFT) || (keycode == KEY_A))
		move(vars->w_info, -1, 0);
	else if ((keycode == KEY_DOWN) || (keycode == KEY_S))
		move(vars->w_info, 0, 1);
	else if ((keycode == KEY_RIGHT) || (keycode == KEY_D))
		move(vars->w_info, 1, 0);
	else
		return (-1);
	ft_mlx_window_reload(vars);
	return (0);
}
