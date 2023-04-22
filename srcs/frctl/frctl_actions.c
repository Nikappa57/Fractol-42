/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frctl_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 11:31:41 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/04/20 18:33:58 by lorenzogaud      ###   ########.fr       */
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
	return (1);
}
