/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 11:29:57 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/04/16 23:49:18 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	zoom(t_winfo *w_info, int plus)
{
	if (plus && w_info->zoom < DBL_MAX / 1.1)
		w_info->zoom *= 1.1;
	else if (w_info->zoom > 0.02f)
		w_info->zoom /= 1.1;
	else
		return (0);
	return (1);
}

int	increase_iterations(t_frctl *frctl)
{
	int	old_iter;

	old_iter = frctl->maxiter;
	if (frctl->maxiter < MIN_ITER)
		frctl->maxiter = MIN_ITER;
	else if (frctl->maxiter < MAX_ITER / 2)
		frctl->maxiter += MAX_ITER / 10;
	else if (frctl->maxiter < MAX_ITER)
		frctl->maxiter += MAX_ITER / 4;
	if (frctl->maxiter > MAX_ITER && old_iter <= MAX_ITER)
		frctl->maxiter = MAX_ITER;
	if (old_iter == frctl->maxiter)
		return (0);
	return (1);
}

int	decrease_iterations(t_frctl *frctl)
{
	int	old_iter;

	old_iter = frctl->maxiter;
	if (frctl->maxiter > MAX_ITER)
		frctl->maxiter = MAX_ITER;
	else if (frctl->maxiter > MAX_ITER / 2)
		frctl->maxiter -= MAX_ITER / 4;
	else if (frctl->maxiter > MIN_ITER)
		frctl->maxiter -= MAX_ITER / 10;
	if (frctl->maxiter < MIN_ITER && old_iter >= MIN_ITER)
		frctl->maxiter = MIN_ITER;
	if (old_iter == frctl->maxiter)
		return (0);
	return (1);
}

void	move(t_winfo *w_info, int x, int y)
{
	w_info->m_x += x * 0.1 / w_info->zoom;
	w_info->m_y += y * 0.1 / w_info->zoom;
}
