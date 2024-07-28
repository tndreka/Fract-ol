/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka <tndreka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 21:08:44 by tndreka           #+#    #+#             */
/*   Updated: 2024/07/27 23:19:55 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// void draw_mandel(mlx_t *mlx, t_frac *mb);

int	ft_strcmp(char *s1, char *s2, int n)
{
	if (s1 == NULL || s2 == NULL || n <= 0)
		return (0);
	while (*s1 == *s2 && n > 0 && s2 != (void *)0)
	{
		s1++;
		s2++;
		n--;
	}
	return (*s1 - *s2);
}

void	ft_putstr_fd(char *s, int fd)
{
	int		i;

	i = 0;
	if (s == NULL || fd < 0)
		return ;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int	ft_atoi(const char *str)
{
	long		i;
	long		res;
	int			sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] != '\0' && (str[i] == 32 || str[i] == '\t'
			|| str[i] == '\n' || str[i] == '\r' || str[i] == '\v'
			|| str[i] == '\f'))
		i++;
	if (str[i] == '-' && str[i])
	{
		sign = -sign;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && (str[i] >= 48 && str[i] <= 57))
		res = (res * 10 + (str[i++] - '0'));
	return (res * sign);
}

int	ft_strlen(const char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

//AtoF

double	ft_a_to_f(const char *s)
{
	// int			len;
	// double		res_int;
	// double		res_float;
	// const char	*tmp;

	// res_int = (double)ft_atoi(tmp);
	// tmp = (char *)str;
	// while (*tmp && *tmp != '.')
	// 	tmp++;
	// if (*tmp == '.')
	// 	tmp++;
	// res_float = (double)ft_atoi(tmp);
	// len = ft_strlen(tmp);
	// while (len)
	// {
	// 	res_float = res_float / 10;
	// 	len--;
	// }
	// if (res_int >= 0)
	// 	return (res_int + res_float);
	// else
	// 	return (res_int + (-res_float));
	long int_p;
	double fract_p;
	double pow;
	int sign;

	int_p = 0;
	fract_p = 0;
	sign = 1;
	pow = 1;
	while((*s >= 9 && *s <= 13) || *s == 32)
		++s;
	while (*s == '+' || *s == '-')
	{
		if(*s++ == '-')
			sign = -sign;
	}
	while (*s != '.' && *s)
		int_p = (int_p * 10) + (*s++ - 48);
	if (*s == '.')
		++s;
	while(*s)
	{
		pow /= 10;
		fract_p = fract_p + (*s++ - 48) * pow;
	}
	return ((int_p + fract_p) * sign);
}

