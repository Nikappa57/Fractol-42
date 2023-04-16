/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 11:29:57 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/04/16 19:37:47 by lorenzogaud      ###   ########.fr       */
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
