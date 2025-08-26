#include "../inc/fractol.h"

static double	ft_atof_frac(const char *str)
{
	double	frac;
	double	div;

	frac = 0.0;
	div = 1.0;
	while (*str >= '0' && *str <= '9')
	{
		frac = frac * 10.0 + (*str - '0');
		div *= 10.0;
		str++;
	}
	return (frac / div);
}

double	ft_atof(const char *str)
{
	double	result;
	int		sign;

	result = 0.0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
		sign = (*str++ == '-') ? -1 : 1;
	while (*str >= '0' && *str <= '9')
		result = result * 10.0 + (*str++ - '0');
	if (*str == '.')
		result += ft_atof_frac(++str);
	return (result * sign);
}
