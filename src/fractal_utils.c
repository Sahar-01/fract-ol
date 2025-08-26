/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scheragh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 18:08:58 by scheragh          #+#    #+#             */
/*   Updated: 2025/08/18 18:10:29 by scheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/fractol.h"

t_complex	get_complex(int x, int y, t_env *env)
{
	t_complex	c;

	c.re = (x - WIDTH / 2.0) / (0.5 * env->zoom * WIDTH) + env->offset_x;
	c.im = (y - HEIGHT / 2.0) / (0.5 * env->zoom * HEIGHT) + env->offset_y;
	return (c);
}

static int	rgb(double r, double g, double b)
{
	int	ri = (int)(r * 255.0);
	int	gi = (int)(g * 255.0);
	int	bi = (int)(b * 255.0);

	return ((ri << 16) | (gi << 8) | bi);
}

int	get_colour(int i, int max_iter, int mode)
{
	double	t;
	double	r;
	double	g;
	double	b;

	if (i >= max_iter)
		return (0x000000);
	t = (double)i / max_iter;
	if (mode % 3 == 0)
	{
		r = 9 * (1 - t) * t * t * t;
		g = 15 * (1 - t) * (1 - t) * t * t;
		b = 8.5 * (1 - t) * (1 - t) * (1 - t) * t;
	}
	else if (mode % 3 == 1)
	{
		r = t * t;
		g = (1 - t) * t;
		b = (1 - t) * (1 - t);
	}
	else
	{
		r = sin(5 * t);
		g = sin(5 * t + 2);
		b = sin(5 * t + 4);
	}
	return (rgb(fabs(r), fabs(g), fabs(b)));
}
