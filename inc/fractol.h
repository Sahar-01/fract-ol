#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/inc/libft.h"
# include "../mlx-linux/mlx.h"

typedef struct	s_env
{
	void	*mlx;
	void	*window;
	void	*image;
	void	*pointer_to_image;
}	t_env;
//Libft utilities
int		ft_printf(const char *format, ...);
//general
void	initialise_mlx(t_env *mlx_env);
int		close_window(int keycode, t_env *mlx_env);
#endif
