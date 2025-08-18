#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/inc/libft.h"
# include "../mlx-linux/mlx.h"
# include "image.h"

typedef struct	s_env
{
	void	*mlx;
	void	*window;
	t_image	image;
	double	zoom;
	double	offset_x;
	double	offset_y;
}	t_env;

typedef struct	s_complex
{
	double	re;
	double	im;
}	t_complex;

//Libft utilities
int	ft_printf(const char *format, ...);
int	ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlen(const char *s);

//Keys and mouse
int	key_hook(int key_code, t_env *mlx_env);
int	mouse_hook(int mouse_code, int x, int y, t_env *mlx_env);

//general
void	initialise_mlx(t_env *mlx_env);
void	init_image(t_env *mlx_env);
int	handle_events(int keycode, t_env *mlx_env);
int	close_window(t_env *mlx_env);
void	my_mlx_pixel_put(t_image *image, int x, int y, int colour);
void	zoom(t_env *mlx_env, int x, int y, int direction);
//mandlebrot
void	draw_julia(t_env *mlx_env);
void	draw_mandlebrot(t_env *mlx_env);
#endif
