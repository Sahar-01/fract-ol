/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scheragh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 18:55:26 by scheragh          #+#    #+#             */
/*   Updated: 2025/08/12 19:16:57 by scheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/fractol.h"
#include "../inc/keys.h"

int	close_window(t_env *mlx_env)
{
	if (mlx_env->image.image)
		mlx_destroy_image(mlx_env->mlx, mlx_env->image.image);
	if (mlx_env->window)
		mlx_destroy_window(mlx_env->mlx, mlx_env->window);
	exit(EXIT_SUCCESS);
	return (0);
}

int	handle_events(int keycode, t_env *mlx_env)
{
	if (keycode == KEY_ESC)
		close_window(mlx_env);
	return (0);
}
