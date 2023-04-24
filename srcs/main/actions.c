/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 11:29:57 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/04/24 19:54:49 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	zoom(t_winfo *w_info, t_ftype ftype, int plus)
{
	if (((plus && ftype != NEWTON) || (!plus && ftype == NEWTON))
		&& (w_info->zoom < DBL_MAX / 1.1))
			w_info->zoom *= 1.1;
	else if (((!plus && ftype != NEWTON) || (plus && ftype == NEWTON)))
			w_info->zoom /= 1.1;
	else
		return (0);
	return (1);
}

void	move(t_winfo *w_info, t_ftype ftype, int x, int y)
{
	if (ftype == NEWTON)
	{
		w_info->m_x += x * 0.1 * w_info->zoom;
		w_info->m_y += y * 0.1 * w_info->zoom;
		return ;
	}
	w_info->m_x += x * 0.1 / w_info->zoom;
	w_info->m_y += y * 0.1 / w_info->zoom;
}

void	mouse_track(t_winfo *w_info)
{
	w_info->track_mouse = !w_info->track_mouse;
}

void	change_show_info(t_winfo *w_info)
{
	w_info->show_info = !w_info->show_info;
}