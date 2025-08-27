/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scheragh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 18:08:58 by scheragh          #+#    #+#             */
/*   Updated: 2025/08/27 12:44:14 by scheragh         ###   ########.fr       */
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
	int		ri;
	int		gi;
	int		bi;

	r = fmin(fmax(r, 0.0), 1.0);
	g = fmin(fmax(g, 0.0), 1.0);
	b = fmin(fmax(b, 0.0), 1.0);
	ri = (int)(r * 255.0);
	gi = (int)(g * 255.0);
	bi = (int)(b * 255.0);
	return ((ri << 16) | (gi << 8) | bi);
}

static void	sin_colour_helper(double *r, double *g, double *b, double t)
{
	*r = sin(4 * t);
	*g = sin(4 * t + 6);
	*b = sin(4 * t + 12);
}

static void	cos_colour_helper(double *r, double *g, double *b, double t)
{
	*r = cos(4 * t);
	*g = cos(4 * t + 2);
	*b = cos(4 * t + 4);
}

int	get_colour(int i, int max_iter, int mode)
{
	double	t;
	double	r;
	double	g;
	double	b;

	t = 0.0;
	r = 0.0;
	g = 0.0;
	b = 0.0;
	if (max_iter <= 0 || i >= max_iter || i < 0)
		return (0x000000);
	t = (double)i / (double)max_iter;
	if (mode % 3 == 0)
	{
		r = 9 * (1 - t) * t * t * t;
		g = 15 * (1 - t) * (1 - t) * t * t;
		b = 8.5 * (1 - t) * (1 - t) * (1 - t) * t;
	}
	else if (mode % 3 == 1)
		sin_colour_helper(&r, &g, &b, t);
	else
		cos_colour_helper(&r, &g, &b, t);
	return (rgb(fabs(r), fabs(g), fabs(b)));
}
