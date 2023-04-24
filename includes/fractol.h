/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogaudino <lorenzogaudino@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:12:50 by lorenzogaud       #+#    #+#             */
/*   Updated: 2023/04/24 19:02:41 by lorenzogaud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx/mlx.h"
# include <math.h>
# include <limits.h>
# include <float.h>
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
	double	zoom;
	int		track_mouse;
	int		mouse_x;
	int		mouse_y;
	double	m_x;
	double	m_y;
}	t_winfo;

/* fractol types */
typedef enum e_ftype {
	MANDELBROT,
	NEWTON,
	JULIA,
}	t_ftype;

/* fractol names */
# define MANDELBROT_STR	"mandelbrot"
# define JULIA_STR		"julia"
# define NEWTON_STR		"newton"

/* fractol info */
typedef struct s_frctl {
	t_ftype	type;
	int		color;
	double	inc;
	double	radius;
	int		maxiter;
	double	julia_mx;
	double	julia_my;
	int		newton_ctype;
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
# define WINDOW_WIDTH	600
# define WINDOW_HEIGHT	600
# define WINDOW_TITLE	"fract'ol - "

/* drow */
void			ft_mlx_pixel_put(t_imgdata *img, int x, int y, int color);
int				ft_mlx_close(int keycode, t_vars *vars);
int				ft_mlx_destroy(void *data);
void			ft_mlx_window_reload(t_vars *vars);

/* colors */
int				ft_mlx_create_trgb(int t, int r, int g, int b);

/* keys */
int				key_hook(int keycode, t_vars *vars);
int				mousemove_hook(int x, int y, t_vars *vars);
int				mouse_hook(int keycode, int x, int y, t_vars *vars);

/*		FRACTOL		*/

/* default info */
# define MAX_ITER 100
# define MIN_ITER 10

/* fractols info */
typedef struct s_mandel_info {
	int		i;
	double	pr;
	double	pi;
	double	newre;
	double	newim;
	double	ore;
	double	oim;
	double	nwtn_incx;
	double	nwtn_incy;
}	t_frctl_info;

/* utils */
double			get_xmove_pos(int x, t_winfo *w_info);
double			get_ymove_pos(int y, t_winfo *w_info);
int				check_radius(t_vars *vars, t_frctl_info info, int x, int y);
int				set_frctl_type(
					t_frctl *frctl, t_winfo *w_info, int argc, char **argv);
void			mouse_update_julia(t_vars *vars);
double			newton_re(t_frctl_info info);
double			newton_im(t_frctl_info info);
int				newton_check_radius(t_frctl_info info, t_frctl *frctl,
					double *saved_mag, int *saved_iter);

/* fractol */
void			show_frctl(t_vars *vars);

/* actions */
int				change_radius(t_frctl *frctl, int plus);
int				change_inc(t_frctl *frctl, int plus);
int				zoom(t_winfo *w_info, t_ftype ftype, int plus);
int				increase_iterations(t_frctl *frctl);
int				decrease_iterations(t_frctl *frctl);
void			move(t_winfo *w_info, t_ftype ftype, int x, int y);
void			mouse_track(t_winfo *w_info);
void			change_newton_ctype(t_frctl *frctl);

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
int				get_color(t_vars *vars, int iter, double mag);
void			shift_color(t_frctl *frctl);
int				get_color_newton(
					t_vars *vars, int iter, double mag, int color_n);

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
void			init_winfo(t_winfo *w_info, t_ftype f_type);
void			init_frctl(t_frctl *frctl);
t_vars			*init_vars(int argc, char **argv);
void			print_usage(void);

#endif