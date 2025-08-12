#include "../inc/fractol.h"

void	initialise_mlx(t_env *mlx_env)
{
	mlx_env->mlx = mlx_init();
	mlx_env->window = mlx_new_window(mlx_env->mlx, 1920, 1080, "Fract-ol");
}
