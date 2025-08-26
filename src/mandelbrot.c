/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scheragh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 18:03:40 by scheragh          #+#    #+#             */
/*   Updated: 2025/08/26 15:11:19 by scheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/fractol.h"

static int	get_mandelbrot_iter(t_complex c, int max_iter, int type)
{
	t_complex	z;
	double		tmp;
	int			i;
	double		constant;

	i = 0;
	constant = 2.0;
	if (type == 0)
		constant = -2.0;
	z.re = 0;
	z.im = 0;
	while (i < max_iter)
	{
		tmp = z.re * z.re - z.im * z.im + c.re;
		z.im = constant * z.re * z.im + c.im;
		z.re = tmp;
		if ((z.re * z.re + z.im * z.im) > 4.0)
			break ;
		i++;
	}
	return (i);
}

void	calculate_mandelbrot(t_env *env, int x, int y)
{
	t_complex	c;
	int			i;
	int			colour;
	int			type;

	type = env->fractal_type;
	c = get_complex(x, y, env);
	i = get_mandelbrot_iter(c, env->max_iter, type);
	colour = get_colour(i, env->max_iter, env->color_mode);
	my_mlx_pixel_put(&env->image, x, y, colour);
}

void	draw_mandelbrot(t_env *env)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			calculate_mandelbrot(env, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(env->mlx, env->window, env->image.image, 0, 0);
}
