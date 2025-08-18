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

int	get_colour(int i, int max_iter)
{
	int	green;
	int	blue;

	if (i == max_iter)
		return (0x000000);
	green = (i * 255) / MAX_ITER;
	blue = ((MAX_ITER - i) * 255) / MAX_ITER;
	return ((green << 8) | blue);
}
