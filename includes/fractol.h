/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:12:50 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/04/16 01:38:28 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx/mlx.h"
# include <math.h>
# include "libft.h"
# include "macos_keys.h"
# include "events.h"
# include "colors.h"

/*		VARS		*/

/* img */
typedef struct s_imgdata {
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_imgdata;

/* win info */
typedef struct s_wininfo {
	int		loading;
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
	int		color;
	double	inc;
	double	radius;
	int		maxiter;
}	t_frctl;

/* all vars */
typedef struct s_vars {
	int			*palette;
	void		*mlx;
	void		*win;
	t_imgdata	*img;
	t_frctl		*frctl;
	t_winfo		*w_info;
}	t_vars;

/*		MLX		*/

/* window info */
# define WINDOW_WIDTH	1200
# define WINDOW_HEIGHT	800
# define WINDOW_TITLE	"fract'ol"

/* drow */
void			ft_mlx_pixel_put(t_imgdata *img, int x, int y, int color);
int				ft_mlx_close(int keycode, t_vars *vars);
int				ft_mlx_destroy(void *data);
void			ft_mlx_window_reload(t_vars *vars);

/* colors */
int				ft_mlx_create_trgb(int t, int r, int g, int b);

/* keys */
int				ft_mlx_key_hook(int keycode, t_vars *vars);

/*		FRACTOL		*/

/* default info */
# define MAX_ITER 100

/* utils */
int				set_frctl_type(t_frctl *frctl, int argc, char **argv);
void			show_frctl(t_vars *vars);

/* fractols func */
void			mandelbrot(t_vars *vars);

/* fractols info */
typedef struct s_mandel_info {
	int		i;
	double	pr;
	double	pi;
	double	newre;
	double	newim;
	double	ore;
	double	oim;
}	t_mandel_info;

/*		COLOR		*/

/* rgb */
int				create_trgb(unsigned char t, unsigned char r,
					unsigned char g, unsigned char b);
unsigned char	get_t(int trgb);
unsigned char	get_r(int trgb);
unsigned char	get_g(int trgb);
unsigned char	get_b(int trgb);

/* palette */
void			set_palette_1(int *palette);
void			set_palette_2(int *palette);
void			set_palette_3(int *palette);

/* pixel color */
int				get_color(t_vars *frctl, int iter, double re, double im);

/*		MAIN		*/

/* info */
typedef struct s_info {
	char	*iter;
	char	*zoom;
	char	*inc;
	char	*radius;
	char	*color;
}	t_info;

void			set_info(t_vars *vars);

/* init */
void			init_winfo(t_winfo *w_info);
void			init_frctl(t_frctl *frctl);
t_vars			*init_vars(int argc, char **argv);
void			set_info(t_vars *vars);

#endif