/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 23:24:32 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/04/24 19:14:39 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_usage(void)
{
	ft_printf("Usage:\n\n");
	ft_printf("\tMANDEL:\t./fractol mandelbrot <max iter>\n\n");
	ft_printf("\tJULIA:\t./fractol julia <max iter> (x) (y)\n");
	ft_printf("\nCommands:\n\n");
	ft_printf("\tWASD or arrows for move\n");
	ft_printf("\t+ -\t(pad) for zoom\n");
	ft_printf("\tT\t[julia] toggle mouse traking \n");
	ft_printf("\t\t[newton] change color type\n");
	ft_printf("\tC\tchange palette\n");
	ft_printf("\tO-I\tde/increese Max iter\n");
	ft_printf("\tL-K\tde/increese Inc\n");
	ft_printf("\tM-N\tde/increese Radius\n");
}
