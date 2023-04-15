/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:22:28 by lgaudino          #+#    #+#             */
/*   Updated: 2023/04/16 01:34:10 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	set_frctl_type(t_frctl *frctl, int argc, char **argv)
{
	t_ftype	ftype;

	if (argc != 3)
		return (0);
	if (!ft_isstrdigit(argv[2]))
		return (0);
	if (!ft_strncmp(argv[1], MANDELBROT_STR, 11))
		ftype = MANDELBROT;
	else
		return (0);
	frctl->type = ftype;
	frctl->maxiter = ft_atoi(argv[2]);
	return (1);
}

void	show_frctl(t_vars *vars)
{
	vars->w_info->loading = 1;
	if (vars->frctl->type == MANDELBROT)
		mandelbrot(vars);
	vars->w_info->loading = 0;
	set_info(vars);
}
