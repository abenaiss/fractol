/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenaiss <abenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 15:58:21 by abenaiss          #+#    #+#             */
/*   Updated: 2019/07/24 09:48:29 by abenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_H
# define FRACT_H

# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <pthread.h>

# define WIN_WIDTH 700
# define WIN_HEIGHT 700
# define LEFT_CLICK 2
# define RIGHT_CLICK 1
# define NUM_THREAD 4
# define I 34
# define ESC 53
# define PLUS 69
# define MINUS 78
# define SCROLL_UP 5
# define SCROLL_DOWN 4
# define CLEAR 49
# define LEFT 123
# define RIGHT 124
# define RED 15
# define GREEN 5
# define BLUE 11
# define UP 126
# define DOWN 125
# define I_UP 116
# define I_DOWN 121
# define LOCK 37
# define BLEND 35

typedef struct	s_coor
{
	int	x;
	int	y;
	int	z;
	int	rgb;
}				t_coor;

typedef struct	s_img
{
	void	*img_ptr;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
}				t_img;

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win;
	t_img	img;
}				t_mlx;

typedef struct	s_zoom
{
	double	rmin;
	double	rmax;
	double	imin;
	double	imax;
	double	rmins;
	double	rmaxs;
	double	imins;
	double	imaxs;
	double	mousere;
	double	mouseim;
	double	zoom;

}				t_zoom;

typedef struct	s_fract
{
	int		col;
	int		smooth;
	int		row;
	int		rgb;
	int		lock;
	int		choose;
	int		win_w;
	int		win_h;
	int		movex;
	int		movey;
	int		w;
	int		maxw;
	char	fractal[13];
	double	max_it;
	double	it;
	double	n;
	double	x1;
	double	y1;
	double	x2;
	double	y2;
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	double	zrsqr;
	double	zisqr;
	double	stockz;
	t_zoom	zoom;
	t_mlx	mlx;

}				t_fract;

void			ft_choose(char *src, t_fract *fract);
void			ft_fract_prep(t_fract *fract);
void			*ft_mandelbrot(void *fract);
int				ft_mouse_event(int x, int y, t_fract *fract);
int				ft_key_event(int keycode, t_fract *fract);
void			ft_init_win(t_fract fract);
void			*ft_julia(void *data);
int				ft_mouse_handel(int keycode, int x, int y, t_fract *fract);
int				ft_int_rgb(int r, int g, int b);
int				ft_color(t_fract *fract);
void			ft_draw(t_fract *fract);
void			ft_clear_mlx(t_mlx *mlx);
double			ft_map(double x, double in_min, double in_max);
void			*ft_burning_ship(void *data);
void			*ft_burning_julia(void *data);
void			*ft_julia_cross(void *data);
void			*ft_multibrot(void *data);
void			ft_print(t_fract *fract);
void			ft_rezeo(t_fract *fract);
void			ft_fractal(t_fract *fract);
void			ft_palettes(t_fract *fract);
void			ft_print_panel(t_fract fract);
void			ft_info_win2(t_fract fract2);
void			ft_info_win1(void);
void			ft_zoom(t_fract *fract);
void			ft_drawsquare(t_fract *fract, int col, int row, int rgb);
int				ft_exit(t_fract *fract);
void			*ft_tricorn(void *data);
void			ft_zoom(t_fract *fract);
void			ft_pos_zoom(t_fract *fract, double x, double y);
void			ft_mandelbrot_thread(t_fract *fract);
void			ft_burning_ship_thread(t_fract *fract);
void			ft_tricorn_thread(t_fract *fract);
void			ft_multibrot_thread(t_fract *fract);
void			ft_julia_thread(t_fract *fract);
void			ft_burning_julia_thread(t_fract *fract);
void			ft_julia_cross_thread(t_fract *fract);

#endif
