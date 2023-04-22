/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:05:18 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/04/21 13:28:29 by lorenzogaud      ###   ########.fr       */
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
	if ((mag > radius)
		|| (info.newre * info.newre < radius)
		|| (info.newim * info.newim < radius))
	{
		*saved_mag = mag;
		*saved_iter = info.i;
	}
	// if (info.newre * info.newre < radius)
	// {
	// 	*saved_mag = info.newre * info.newre;
	// 	*saved_iter = info.i;
	// }
	// if (info.newim * info.newim < radius)
	// {
	// 	*saved_mag = info.newim * info.newim;
	// 	*saved_iter = info.i;
	// }
}
