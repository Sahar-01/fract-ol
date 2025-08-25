/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scheragh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 17:59:46 by scheragh          #+#    #+#             */
/*   Updated: 2025/08/18 18:37:55 by scheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/fractol.h"

int	key_hook(int keycode, t_env *env)
{
	if (keycode == 65307)
		exit(0);
	else if (keycode == LEFT)
		env->offset_x -= 0.1 / env->zoom;
	else if (keycode == RIGHT)
		env->offset_x += 0.1 / env->zoom;
	else if (keycode == UP)
		env->offset_y -= 0.1 / env->zoom;
	else if (keycode == DOWN)
		env->offset_y += 0.1 / env->zoom;
	init_image(env);
	if (env->fractal_type == JULIA)
		draw_julia(env);
	else if (env->fractal_type == MANDELBROT)
		draw_mandelbrot(env);
	else
		draw_cantor(env);
	return (0);
}
