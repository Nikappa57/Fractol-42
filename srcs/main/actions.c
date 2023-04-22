/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 11:29:57 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/04/21 12:30:55 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	zoom(t_winfo *w_info, t_ftype ftype, int plus)
{
	if (plus && (w_info->zoom * 100 < INT_MAX))
	{
		if (ftype == NEWTON)
			w_info->zoom /= 1.1;
		else
			w_info->zoom *= 1.1;
	}
	else if (!plus && w_info->zoom > 0.02f)
	{
		if (ftype == NEWTON)
			w_info->zoom *= 1.1;
		else
			w_info->zoom /= 1.1;
	}
	else
		return (0);
	return (1);
}

int	increase_iterations(t_frctl *frctl)
{
	int	old_iter;

	if (frctl->type == NEWTON)
	{
		if (frctl->maxiter > MAX_ITER - 1)
			return (0);
		frctl->maxiter += 1;
		return (1);
	}
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

	if (frctl->type == NEWTON)
	{
		if (frctl->maxiter < 2)
			return (0);
		frctl->maxiter -= 1;
		return (1);
	}
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

void	move(t_winfo *w_info, t_ftype ftype, int x, int y)
{
	if (ftype == NEWTON)
	{
		w_info->m_x += x * 0.1 * w_info->zoom;
		w_info->m_y += y * 0.1 * w_info->zoom;
		return ;
	}
	w_info->m_x += x * 0.1 / w_info->zoom;
	w_info->m_y += y * 0.1 / w_info->zoom;
}

void	mouse_track(t_winfo *w_info)
{
	w_info->track_mouse = !w_info->track_mouse;
}
