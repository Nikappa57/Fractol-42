/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:12:50 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/04/13 22:58:11 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx/mlx.h"
# include <math.h>
# include "libft.h"
# include "macos_keys.h"
# include "events.h"

/*		VARS		*/

/* img */
typedef struct s_data {
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

/* win info */
typedef struct s_wininfo {
	double	zoom;
	double	m_x;
	double	m_y;
}	t_winfo;

/* fractol types */
typedef enum e_ftype {
	MANDELBROT,
}	t_ftype;

/* fractol names */
# define MANDELBROT_STR	"mandelbrot"

/* fractol info */
typedef struct s_frctl {
	t_ftype	type;
	double	inc;
	int		maxiter;
}	t_frctl;

/* all vars */
typedef struct s_vars {
	void	*mlx;
	void	*win;
	t_data	*img;
	t_frctl	*frctl;
	t_winfo	*w_info;
}	t_vars;

/*		MLX		*/

/* window info */
# define WINDOW_WIDTH	1200
# define WINDOW_HEIGHT	800
# define WINDOW_TITLE	"fract'ol"

/* utils */
void	ft_mlx_pixel_put(t_data *img, int x, int y, int color);
int		ft_mlx_create_trgb(int t, int r, int g, int b);
int		ft_mlx_key_hook(int keycode, t_vars *vars);
int		ft_mlx_close(int keycode, t_vars *vars);
int		ft_mlx_destroy(void *data);

/*		FRACTOL		*/

/* utils */
void	show_frctl(t_vars *vars);

/* fractols func */
void	mandelbrot(t_vars *vars);

/* fractols info */
typedef struct s_mandel_info {
	double	pr;
	double	pi;
	double	newre;
	double	newim;
	double	ore;
	double	oim;
}	t_mandel_info;

#endif