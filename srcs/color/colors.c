/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 23:03:34 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/04/24 18:59:00 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	shift_color(t_frctl *frctl)
{
	frctl->color++;
	if (frctl->color == PALETTE_N)
		frctl->color = 0;
}

int	get_color(t_vars *vars, int iter, double mag)
{
	int		*palette;
	double	mu;
	int		clr1;
	int		clr2;
	double	t2;

	palette = vars->palette + (COLOR_N * vars->frctl->color);
	mu = iter + 1 - log(log(mag)) / log(sqrt(vars->frctl->radius));
	mu = mu / MAX_ITER * (sizeof(int) * COLOR_N);
	clr1 = (int)mu;
	t2 = mu - clr1;
	clr1 = clr1 % (sizeof(int) * COLOR_N);
	clr2 = (clr1 + 1) % (sizeof(int) * COLOR_N);
	return (create_trgb(0,
			(get_r(palette[clr1]) * (1.0f - t2) + get_r(palette[clr2]) * t2),
			(get_g(palette[clr1]) * (1.0f - t2) + get_g(palette[clr2]) * t2),
			(get_b(palette[clr1]) * (1.0f - t2) + get_b(palette[clr2]) * t2)));
}

int	get_color_newton(t_vars *vars, int iter, double mag, int color_n)
{
	int	color;
	int	old_color;

	color = 0;
	old_color = vars->frctl->color;
	color_n--;
	while (color_n-- > 0)
		shift_color(vars->frctl);
	color = get_color(vars, iter, mag);
	vars->frctl->color = old_color;
	return (color);
}

/* Simple color */
// int	get_color_1(t_frctl *frctl, int iter, double re, double img)
// {
// 	re++;
// 	img++;
// 	return (((double)0xFFFFFFFF / (double)(PALETTE_N + 1))
// 		* ((double)iter / (double)MAX_ITER)
// 		+ ((double)MAX_COLOR / (double)(PALETTE_N + 1)) * frctl->color);
// }
