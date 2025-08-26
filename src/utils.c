/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scheragh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 18:20:28 by scheragh          #+#    #+#             */
/*   Updated: 2025/08/18 19:13:34 by scheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/fractol.h"
#include <stdlib.h>
#include <stdio.h>

void	*safe_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
	{
		perror("malloc failed");
		exit(EXIT_FAILURE);
	}
	return (ptr);
}

void	my_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;

	dst = image->addr
		+ (y * image->line_length + x * (image->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	zoom(t_env *mlx_env, int x, int y, int direction)
{
	double	mouse_re;
	double	mouse_im;

	mouse_re = (x - WIDTH / 2.0) / (0.5 * mlx_env->zoom * WIDTH)
		+ mlx_env->offset_x;
	mouse_im = (y - HEIGHT / 2.0) / (0.5 * mlx_env->zoom * HEIGHT)
		+ mlx_env->offset_y;
	if (direction > 0)
	{
		mlx_env->zoom *= 1.1;
		mlx_env->max_iter += 10;
	}
	else if (direction < 0)
	{
		mlx_env->zoom /= 1.1;
		if (mlx_env->max_iter > 50)
			mlx_env->max_iter -= 10;
	}
	mlx_env->offset_x = mouse_re
		- (x - WIDTH / 2.0) / (0.5 * mlx_env->zoom * WIDTH);
	mlx_env->offset_y = mouse_im
		- (y - HEIGHT / 2.0) / (0.5 * mlx_env->zoom * HEIGHT);
	if (mlx_env->image.image)
        	mlx_destroy_image(mlx_env->mlx, mlx_env->image.image);
	init_image(mlx_env);
	if (mlx_env->fractal_type == JULIA)
		draw_julia(mlx_env);
	else if (mlx_env->fractal_type == MANDELBROT)
		draw_mandelbrot(mlx_env);
	else
		draw_tricorn(mlx_env);
}
