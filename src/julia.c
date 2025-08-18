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

void	draw_julia(t_env *mlx_env)
{
	my_mlx_pixel_put(&mlx_env->image, WIDTH, HEIGHT, 0xFFFFFF);

	mlx_put_image_to_window(mlx_env->mlx, mlx_env->window,
		mlx_env->image.image, 0, 0);

	ft_printf("Pixel drawn at center (960, 540)\n");
}
