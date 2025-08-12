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

int	close_window(int keycode, t_env *mlx_env)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(mlx_env->mlx, mlx_env->window);
		exit(0);
	}

	return (0);
}
