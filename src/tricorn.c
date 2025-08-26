#include "../inc/fractol.h"
#include <math.h>

static int	get_tricorn_iter(t_complex c, int max_iter)
{
	t_complex	z;
	double		tmp;
	int			i;

	i = 0;
	z.re = 0;
	z.im = 0;
	while (i < max_iter)
	{
		tmp = z.re * z.re - z.im * z.im + c.re;
		z.im = -2.0 * z.re * z.im + c.im;
		z.re = tmp;
		if ((z.re * z.re + z.im * z.im) > 4.0)
			break ;
		i++;
	}
	return (i);
}

void	calculate_tricorn(t_env *env, int x, int y)
{
	t_complex	c;
	int			i;
	int			colour;

	c = get_complex(x, y, env);
	i = get_tricorn_iter(c, env->max_iter);
	colour = get_colour(i, env->max_iter);
	my_mlx_pixel_put(&env->image, x, y, colour);
}

void	draw_tricorn(t_env *env)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			calculate_tricorn(env, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(env->mlx, env->window, env->image.image, 0, 0);
}
