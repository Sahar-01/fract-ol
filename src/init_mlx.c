/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scheragh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 16:40:58 by scheragh          #+#    #+#             */
/*   Updated: 2025/08/18 17:58:29 by scheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/fractol.h"

void	initialise_mlx(t_env *mlx_env)
{
	mlx_env->mlx = mlx_init();
	if (!mlx_env->mlx)
		exit(1);
	mlx_env->window = mlx_new_window(mlx_env->mlx, WIDTH, HEIGHT, "Fract-ol");
	if (!mlx_env->window)
		exit(1);
	mlx_env->max_iter = MAX_ITER;
	mlx_env->zoom = 1.0;
	mlx_env->offset_x = -0.5;
	mlx_env->offset_y = 0.0;
}

void	init_image(t_env *env)
{
	env->image.image = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	if (!env->image.image)
		exit(1);
	env->image.addr = mlx_get_data_addr(env->image.image,
			&env->image.bits_per_pixel,
			&env->image.line_length,
			&env->image.endian);
}
