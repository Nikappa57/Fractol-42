/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:12:50 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/04/13 12:01:09 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx/mlx.h"
# include <math.h>
# include "libft.h"
# include "macos_keys.h"
# include "events.h"

/*		MLX		*/

/* img */
typedef struct s_data {
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_wininfo {
	int	zoom;
}	t_winfo;

/* fractol types */
typedef enum e_ftype {
	MANDELBROT,
}	t_ftype;

/* fractol names */
# define MANDELBROT_STR	"mandelbrot"

typedef struct s_frctl {
	t_ftype	type;
	int		p;
	int		q;
	int		n;
	int		w;
	double	x;
	double	y;
	double	xx;
	double	yy;
	double	incx;
	double	incy;
	double	maxiter;
}	t_frctl;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	t_data	*img;
	t_frctl	*frctl;
	t_winfo	*w_info;
}	t_vars;

/* window info */
# define WINDOW_WIDTH	600
# define WINDOW_HEIGHT	800
# define WINDOW_TITLE	"fract'ol"

/* utils */
void	ft_mlx_pixel_put(t_data *img, int x, int y, int color);
int		ft_mlx_create_trgb(int t, int r, int g, int b);
int		ft_mlx_key_hook(int keycode, t_vars *vars);
int		ft_mlx_close(int keycode, t_vars *vars);

#endif