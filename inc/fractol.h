/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scheragh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 17:54:50 by scheragh          #+#    #+#             */
/*   Updated: 2025/08/18 18:52:53 by scheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/inc/libft.h"
# include "../mlx-linux/mlx.h"
# include "image.h"
# include "keys.h"
# include "type.h"
# define WIDTH 620
# define HEIGHT 490
# define MAX_ITER 100

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_env
{
	int			x;
	int			y;
	int			max_iter;
	double		zoom;
	double		offset_x;
	double		offset_y;
	void		*mlx;
	void		*window;
	t_image		image;
	t_type		fractal_type;
	t_complex	julia_c;
}	t_env;

//Libft utilities
int			ft_printf(const char *format, ...);
int			ft_strcmp(const char *s1, const char *s2);
size_t		ft_strlen(const char *s);

//Keys and mouse
int			key_hook(int key_code, t_env *mlx_env);
int			mouse_hook(int mouse_code, int x, int y, t_env *mlx_env);

//general
void		initialise_mlx(t_env *mlx_env);
void		init_image(t_env *mlx_env);
int			handle_events(int keycode, t_env *mlx_env);
int			close_window(t_env *mlx_env);
void		my_mlx_pixel_put(t_image *image, int x, int y, int colour);
void		zoom(t_env *mlx_env, int x, int y, int direction);
//mandlebrot
void		draw_julia(t_env *mlx_env);
void		draw_mandelbrot(t_env *mlx_env);
void		draw_cantor(t_env *env);
void		calculate_mandelbrot(t_env *env, int x, int y);

//colours
t_complex	get_complex(int x, int y, t_env *env);
int			get_colour(int i, int max_iter);
#endif
