/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scheragh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 13:47:33 by scheragh          #+#    #+#             */
/*   Updated: 2025/08/27 13:47:44 by scheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/fractol.h"

static void	ft_print_usage(void)
{
	ft_printf("Usage:\n");
	ft_printf("./fractol <Mandelbrot/Tricorn>\n");
	ft_printf("./fractol Julia <real> <imag>\n");
	ft_printf("Example: ./fractol Julia 0.32 0.42\n");
}

static int	is_valid_float(const char *s)
{
	int	i = 0;
	int	dot = 0;

	if (!s || !*s)
		return (0);
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i])
	{
		if (s[i] == '.')
		{
			if (dot++)
				return (0);
		}
		else if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	set_julia_params(int argc, char **argv, t_env *env)
{
	env->fractal_type = JULIA;
	if (argc == 4)
	{
		if (!is_valid_float(argv[2]) || !is_valid_float(argv[3]))
		{
			ft_putendl_fd("Error: Julia parameters must be valid floats", 2);
			return (0);
		}
		env->julia_c.re = ft_atof(argv[2]);
		env->julia_c.im = ft_atof(argv[3]);
	}
	else
	{
		env->julia_c.re = -0.7;
		env->julia_c.im = 0.27015;
	}
	return (1);
}

static int	check_args(int argc, char **argv, t_env *env)
{
	if (argc < 2)
	{
		ft_print_usage();
		return (0);
	}
	if (!ft_strcmp(argv[1], "Mandelbrot") && argc == 2)
		env->fractal_type = MANDELBROT;
	else if (!ft_strcmp(argv[1], "Tricorn") && argc == 2)
		env->fractal_type = TRICORN;
	else if (!ft_strcmp(argv[1], "Julia") && (argc == 2 || argc == 4))
		return (set_julia_params(argc, argv, env));
	else
	{
		ft_putendl_fd("Error: Invalid arguments", 2);
		ft_print_usage();
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_env	*env;

	env = ft_calloc(1, sizeof(t_env));
	if (!env)
		return (ft_putendl_fd("Error: Malloc failed", 2), 1);
	if (!check_args(argc, argv, env))
		return (free(env), 1);
	initialise_mlx(env);
	init_image(env);
	mlx_key_hook(env->window, key_hook, env);
	mlx_mouse_hook(env->window, mouse_hook, env);
	mlx_hook(env->window, 17, 0, close_window, env);
	if (env->fractal_type == MANDELBROT || env->fractal_type == TRICORN)
		draw_mandelbrot(env);
	else
		draw_julia(env);
	mlx_loop(env->mlx);
	return (0);
}
