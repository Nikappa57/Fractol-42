/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 12:32:08 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/04/20 12:34:44 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	init_julia(t_frctl *frctl, t_winfo *w_info, int argc, char **argv)
{
	if (argc == 5)
	{
		if (!ft_isstrdouble(argv[3]) || !ft_isstrdouble(argv[4]))
			return (0);
		frctl->julia_mx = ft_atodb(argv[3]);
		frctl->julia_my = ft_atodb(argv[4]);
		w_info->track_mouse = 0;
	}
	else if (argc == 3)
	{
		frctl->julia_mx = 0;
		frctl->julia_my = 0;
		w_info->track_mouse = 1;
	}
	else
		return (0);
	return (1);
}

int	set_frctl_type(t_frctl *frctl, t_winfo *w_info, int argc, char **argv)
{
	t_ftype	ftype;

	if (argc < 3)
		return (0);
	if (!ft_isstrdigit(argv[2]))
		return (0);
	if (!ft_strncmp(argv[1], MANDELBROT_STR, 11))
		ftype = MANDELBROT;
	else if (!ft_strncmp(argv[1], JULIA_STR, 6))
		ftype = JULIA;
	else if (!ft_strncmp(argv[1], NEWTON_STR, 7))
		ftype = NEWTON;
	else
		return (0);
	if ((ftype == MANDELBROT || ftype == NEWTON) && argc != 3)
		return (0);
	if (ftype == JULIA && !init_julia(frctl, w_info, argc, argv))
		return (0);
	frctl->type = ftype;
	frctl->maxiter = ft_atoi(argv[2]);
	return (1);
}
