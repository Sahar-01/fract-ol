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

double	ft_atof(const char *str)
{
	double	result;
	double	sign;
	double	frac;
	double	divider;

	result = 0.0;
	sign = 1.0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1.0;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10.0 + (*str - '0');
		str++;
	}
	if (*str == '.')
		str++;
	frac = 0.0;
	divider = 1.0;
	while (*str >= '0' && *str <= '9')
	{
		frac = frac * 10.0 + (*str - '0');
		divider *= 10.0;
		str++;
	}
	return (sign * (result + frac / divider));
}

static int	check_args(int argc, char **argv, t_env *env)
{
	if (argc == 2 && !ft_strcmp(argv[1], "Mandelbrot"))
		env->fractal_type = MANDELBROT;
	else if (argc == 4 && !ft_strcmp(argv[1], "Julia"))
	{
		env->fractal_type = JULIA;
		env->julia_c.re = ft_atof(argv[2]);
		env->julia_c.im = ft_atof(argv[3]);
	}
	else
	{
		ft_printf("Usage:\n");
		ft_printf("./fractol Mandelbrot\n");
		ft_printf("./fractol Julia <real> <imag>\n");
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
	if (env->fractal_type == MANDELBROT)
		draw_mandelbrot(env);
	else
		draw_julia(env);
	mlx_loop(env->mlx);
	return (0);
}
