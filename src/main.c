/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scheragh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 18:48:36 by scheragh          #+#    #+#             */
/*   Updated: 2025/08/18 19:03:47 by scheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/fractol.h"
#include <math.h>

static void	ft_print_usage(void)
{
	ft_printf("Not Allowed");
}

static int	check_args(int argc, char **argv, t_env *env)
{
	if (argc == 2 && !ft_strcmp(argv[1], "Mandelbrot"))
		env->fractal_type = MANDELBROT;
	else if (argc == 2 && !ft_strcmp(argv[1], "Tricorn"))
		env->fractal_type = TRICORN;
	else if (!ft_strcmp(argv[1], "Julia") && (argc == 2 || argc == 4))
	{
		env->fractal_type = JULIA;
		if (argc == 4)
		{
			env->julia_c.re = ft_atof(argv[2]);
			env->julia_c.im = ft_atof(argv[3]);
		}
		else
		{
			env->julia_c.re = -0.7;
			env->julia_c.im = 0.27015;
		}
	}
	else
	{
		ft_print_usage();
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_env	*env;

	env = malloc(sizeof(t_env));
	if (!env || !check_args(argc, argv, env))
		return (1);
	initialise_mlx(env);
	init_image(env);
	mlx_key_hook(env->window, key_hook, env);
	mlx_mouse_hook(env->window, mouse_hook, env);
	mlx_hook(env->window, 17, 0, close_window, env);
	ft_printf("Fractal type: %d\n", env->fractal_type);
	if (env->fractal_type == MANDELBROT)
		draw_mandelbrot(env);
	else if (env->fractal_type == TRICORN)
		draw_mandelbrot(env);
	else
		draw_julia(env);
	mlx_loop(env->mlx);
	return (0);
}
