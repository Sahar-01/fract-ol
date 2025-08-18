#include "../inc/fractol.h"
#include "../inc/keys.h"

int	key_hook(int key_code, t_env *mlx_env)
{
	if (key_code == LEFT)
		mlx_env->offset_x -= 30 / mlx_env->zoom;
	else if (key_code == RIGHT)
		mlx_env->offset_x += 30 / mlx_env->zoom;
	else if (key_code == UP)
		mlx_env->offset_y -= 30 / mlx_env->zoom;
	else if (key_code == DOWN)
		mlx_env->offset_y += 30 / mlx_env->zoom;
	return (0);
}
