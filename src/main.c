
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
#include "../inc/image.h"

int	main(int argc, char **argv)
{
	t_env	*mlx_env;

	if ((argc != 2) || !argv[1])
	{
		ft_printf("Usage: %s <Mandlebrot | Julia>\n", argv[0]);
		return (1);
	}
	mlx_env = malloc(sizeof(t_env));
	if (!mlx_env)
		return (1);
	initialise_mlx(mlx_env);
	init_image(mlx_env);
	mlx_key_hook(mlx_env->window, key_hook, mlx_env);
	mlx_mouse_hook(mlx_env->window, mouse_hook, mlx_env);
	mlx_hook(mlx_env->window, 2, 1L << 0, handle_events, mlx_env);
	mlx_hook(mlx_env->window, 17, 0, close_window, mlx_env);
	if (ft_strcmp(argv[1], "Julia") == 0)
		draw_julia(mlx_env);
	else if (ft_strcmp(argv[1], "Mandelbrot") == 0)
		draw_mandlebrot(mlx_env);
	else
		ft_printf("expected: ");
	mlx_loop(mlx_env->mlx);
	free(mlx_env);
	return (0);
}
