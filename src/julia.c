#include "../inc/fractol.h"

void	draw_julia(t_env *mlx_env)
{
	int x = 960;  // center of the screen (1920 / 2)
	int y = 540;  // center of the screen (1080 / 2)

	my_mlx_pixel_put(&mlx_env->image, x, y, 0xFFFFFF);  // white pixel

	mlx_put_image_to_window(mlx_env->mlx, mlx_env->window,
		mlx_env->image.image, 0, 0);

	ft_printf("Pixel drawn at center (960, 540)\n");
}
