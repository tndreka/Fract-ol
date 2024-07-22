/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka <tndreka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 21:08:44 by tndreka           #+#    #+#             */
/*   Updated: 2024/07/22 21:23:57 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_strcmp(char *s1, char *s2, int n)
{
	if (s1 == NULL || s2 == NULL || n <= 0)
		return (0);
	while (*s1 == *s2 && n > 0  && s2 != '\n')
	{
		s1++;
		s2++;
		n--;
	}
	return (*s1 - *s2);
}

void ft_putstr_fd(char *s, int fd)
{
	int		i;

	i = 0;
	if (s == NULL || fd < 0)
		return ;
	while (s[i] != '\0')
	{
		ft_putstr_fd(s[i], fd);
		i++;
	}
}

void	check_av(int ac, char **av)
{
	if (ac == 2 &&  !(ft_strcmp(av[1], "mandelbrot", 10)))
	{
		//implement mandelbrot
	}
	else if (ac == 2 &&  !(ft_strcmp(av[1], "mandelbrot", 10)))
	{
		//implement julia
	}
	else
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);	
}
