/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudino <lgaudino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 11:31:41 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/04/18 12:44:48 by lgaudino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandel_radius(t_frctl *frctl, int plus)
{
	if (plus && (frctl->radius < INT_MAX / frctl->radius - 1))
		frctl->radius *= frctl->radius;
	else if (!plus && frctl->radius >= 8)
		frctl->radius = sqrt(frctl->radius);
	else
		return (0);
	return (1);
}

int	mandel_inc(t_frctl *frctl, int plus)
{
	if (plus && (frctl->inc * 100 <= INT_MAX - 10))
		frctl->inc += 0.1;
	else if (frctl->inc * 100 >= INT_MIN + 10)
		frctl->inc -= 0.1;
	else
		return (0);
	return (1);
}
