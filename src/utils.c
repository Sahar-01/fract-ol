#include "../inc/fractol.h"

void	my_mlx_pixel_put(t_image *image, int x, int y, int color)
{
    char	*dst;

    dst = image->addr + (y * image->line_length + x * (image->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

int ft_strcmp(const char *s1, const char *s2)
{
    while (*s1 && (*s1 == *s2))
    {
        s1++;
        s2++;
    }
    return (unsigned char)*s1 - (unsigned char)*s2;
}

void	zoom(t_env *mlx_env, int x, int y, int direction)
{
	double	zoom_factor;
	double	mouse_re;
	double	mouse_im;

	mouse_re = (x - 960) / (400.0 * mlx_env->zoom) + mlx_env->offset_x;
	mouse_im = (y - 540) / (400.0 * mlx_env->zoom) + mlx_env->offset_y;

	if (direction > 0)
		zoom_factor = 1.2;
	else
		zoom_factor = 1 / 1.2;

	mlx_env->zoom *= zoom_factor;

	mlx_env->offset_x = mouse_re - (x - 960) / (400.0 * mlx_env->zoom);
	mlx_env->offset_y = mouse_im - (y - 540) / (400.0 * mlx_env->zoom);

	draw_mandlebrot(mlx_env);
}
