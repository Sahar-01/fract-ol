#include "../inc/fractol.h"

static void	get_cantor_iter(t_env *env, double x1, double x2, int y, int depth)
{
	int	spacing;

	spacing = 10;
	if (depth == 0)
		return;

	int x = (int)x1;
	while (x <= (int)x2 && x < WIDTH)
	{
		if (x >= 0 && y >= 0 && y < HEIGHT)
			my_mlx_pixel_put(&env->image, x, y, 0xFFFFFF);
		x++;
	}

	double third = (x2 - x1) / 3.0;

	get_cantor_iter(env, x1, x1 + third, y + spacing, depth - 1);
	get_cantor_iter(env, x2 - third, x2, y + spacing, depth - 1);
}

void	draw_cantor(t_env *env)
{
	int	start_y = 50;
	int	depth = 22; // Use your existing max_iter to control depth

	get_cantor_iter(env, 0, WIDTH, start_y, depth);
	mlx_put_image_to_window(env->mlx, env->window, env->image.image, 0, 0);
}

