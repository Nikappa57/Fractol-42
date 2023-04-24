/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:05:18 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/04/24 19:08:11 by lorenzogaud      ###   ########.fr       */
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

int	newton_check_radius(
		t_frctl_info info, t_frctl *frctl, double *saved_mag, int *saved_iter)
{
	double	mag;

	mag = info.ore * info.ore + info.oim * info.oim;
	if (info.ore * info.ore - info.oim * info.oim > 0)
	{
		if (frctl->newton_ctype)
			*saved_mag = mag / (info.ore * info.ore);
		else
			*saved_mag = mag;
		*saved_iter = info.i;
		return (1);
	}
	if (info.oim * info.oim - info.ore * info.ore > 0)
	{
		if (frctl->newton_ctype)
			*saved_mag = mag / (info.oim * info.oim);
		else
			*saved_mag = mag;
		*saved_iter = info.i;
		return (2);
	}
	return (0);
}

void	change_newton_ctype(t_frctl *frctl)
{
	frctl->newton_ctype = !frctl->newton_ctype;
}
