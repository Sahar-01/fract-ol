/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scheragh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 18:55:26 by scheragh          #+#    #+#             */
/*   Updated: 2025/08/27 12:18:20 by scheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/fractol.h"

int	close_window(t_env *env)
{
	mlx_destroy_image(env->mlx, env->image.image);
	mlx_destroy_window(env->mlx, env->window);
	mlx_destroy_display(env->mlx);
	free(env->mlx);
	free(env);
	exit(0);
}
