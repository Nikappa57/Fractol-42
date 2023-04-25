/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frctl_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 11:31:41 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/04/25 00:12:10 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	change_radius(t_frctl *frctl, int plus)
{
	if (frctl->type == NEWTON)
	{
		if (plus && (frctl->radius * 100 < INT_MAX / 1.1))
		{
			frctl->radius *= 1.1;
		}
		else if (!plus && frctl->radius > 1)
		{
			frctl->radius /= 1.1;
		}
		else
			return (0);
	}
	else
	{
		if (plus && (frctl->radius < INT_MAX / frctl->radius - 1))
			frctl->radius *= frctl->radius;
		else if (!plus && frctl->radius >= 8)
			frctl->radius = sqrt(frctl->radius);
		else
			return (0);
	}
	return (1);
}

int	change_inc(t_frctl *frctl, int plus)
{
	if (plus && (frctl->inc * 100 <= INT_MAX - 1))
		frctl->inc += 0.01;
	else if (frctl->inc * 100 >= INT_MIN + 1)
		frctl->inc -= 0.01;
	else
		return (0);
	if (frctl->type == NEWTON && frctl->inc == 1)
		change_inc(frctl, plus);
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
