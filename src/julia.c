/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scheragh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 18:14:37 by scheragh          #+#    #+#             */
/*   Updated: 2025/08/18 18:16:01 by scheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/fractol.h"
#include <math.h>

static int	get_julia_iter(t_complex z, t_complex c, int max_iter)
{
	double	tmp;
	int		i;

	i = 0;
	while (i < max_iter)
	{
		tmp = z.re;
		z.re = (z.re * z.re) - (z.im * z.im) + c.re;
		z.im = (2.0 * z.im * tmp) + c.im;
		if ((z.re * z.re) + (z.im * z.im) > 4.0)
			break ;
		i++;
	}
	return (i);
}

void	calculate_julia(t_env *env, int x, int y)
{
	t_complex	z;
	int			i;
	int			colour;

	z = get_complex(x, y, env);
	i = get_julia_iter(z, env->julia_c, env->max_iter);
	colour = get_colour(i, env->max_iter, env->color_mode);
	my_mlx_pixel_put(&env->image, x, y, colour);
}

void	draw_julia(t_env *env)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			calculate_julia(env, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(env->mlx, env->window, env->image.image, 0, 0);
}
