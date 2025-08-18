#include "../inc/fractol.h"
#include "../inc/keys.h"

int	mouse_hook(int mouse_code, int x, int y, t_env *mlx_env)
{
	if (mouse_code == SCROLL_UP)
		zoom(mlx_env, x, y, 1);
	else if (mouse_code == SCROLL_DOWN)
		zoom(mlx_env, x, y, -1);
	return (0);
}
