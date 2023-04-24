/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 01:32:19 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/04/24 19:12:08 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_palette_1(int *palette)
{
	*palette++ = VIOLETTE;
	*palette++ = BLUE2;
	*palette = WHITE;
}

void	set_palette_2(int *palette)
{
	*palette++ = RED;
	*palette++ = ORANGE;
	*palette = WHITE;
}

void	set_palette_3(int *palette)
{
	*palette++ = BLUE;
	*palette++ = ORANGE;
	*palette = WHITE;
}
