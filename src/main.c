
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scheragh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 16:43:25 by scheragh          #+#    #+#             */
/*   Updated: 2025/08/12 19:12:10 by scheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/fractol.h"

int		main(void)
{
	t_env	*mlx_env;

	mlx_env = malloc(sizeof(t_env));
	initialise_mlx(mlx_env);
	mlx_hook(mlx_env->window, 2, 1L<<0, close_window, mlx_env);
	mlx_loop(mlx_env->mlx);
}
