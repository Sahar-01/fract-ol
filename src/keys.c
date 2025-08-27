/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scheragh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 17:59:46 by scheragh          #+#    #+#             */
/*   Updated: 2025/08/27 12:31:53 by scheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/fractol.h"

static void	redraw_fractal(t_env *env)
{
	if (env->fractal_type == MANDELBROT)
		draw_mandelbrot(env);
	else if (env->fractal_type == JULIA)
		draw_julia(env);
	else if (env->fractal_type == TRICORN)
		draw_mandelbrot(env);
}

void	exit_cleanup(t_env *env)
{
	mlx_destroy_image(env->mlx, env->image.image);
	mlx_destroy_window(env->mlx, env->window);
	mlx_destroy_display(env->mlx);
	free(env->mlx);
	free(env);
	exit(0);
}

int	key_hook(int keycode, t_env *env)
{
	if (keycode == KEY_ESC)
		exit_cleanup(env);
	else if (keycode == LEFT)
		env->offset_x -= 0.1 / env->zoom;
	else if (keycode == RIGHT)
		env->offset_x += 0.1 / env->zoom;
	else if (keycode == UP)
		env->offset_y -= 0.1 / env->zoom;
	else if (keycode == DOWN)
		env->offset_y += 0.1 / env->zoom;
	else if (keycode == KEY_C)
	{
		env->color_mode++;
		redraw_fractal(env);
	}
	init_image(env);
	if (env->fractal_type == JULIA)
		draw_julia(env);
	else if (env->fractal_type == MANDELBROT)
		draw_mandelbrot(env);
	else
		draw_mandelbrot(env);
	return (0);
}
