/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 11:31:41 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/04/16 13:07:04 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandel_radius(t_frctl *frctl, int plus)
{
	if (plus)
		frctl->radius *= frctl->radius;
	else
		frctl->radius = sqrt(frctl->radius);
	if (frctl->radius < 4)
		frctl->radius = 4;
}

void	mandel_inc(t_frctl *frctl, int plus)
{
	if (plus)
		frctl->inc += 0.1;
	else
		frctl->inc -= 0.1;
}
