/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaudino <lgaudino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:05:18 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/04/22 17:00:10 by lgaudino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	newton_re(t_frctl_info info)
{
	return (2 * info.ore / 3
		- (info.ore * info.ore - info.oim * info.oim)
		/ (info.ore * info.ore + info.oim * info.oim)
		/ (info.ore * info.ore + info.oim * info.oim) / 3);
}

double	newton_im(t_frctl_info info)
{
	return (2 * info.oim / 3 + 2 * info.ore * info.oim
		/ (info.ore * info.ore + info.oim * info.oim)
		/ (info.ore * info.ore + info.oim * info.oim) / 3);
}

void	newton_check_radius(
		t_frctl_info info, double radius, double *saved_mag, int *saved_iter)
{
	double	mag;

	mag = info.newre * info.newre + info.newim * info.newim;
	
	if (info.newre * info.newre < radius)
	{
		*saved_mag = mag;
		*saved_iter = info.i;
	}
	if (info.newim * info.newim < radius)
	{
		*saved_mag = mag;
		*saved_iter = info.i;
	}
	if ((mag > radius))
	{
		*saved_mag = mag;
		*saved_iter = info.i;
	}
}
