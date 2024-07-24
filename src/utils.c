/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka <tndreka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 21:08:44 by tndreka           #+#    #+#             */
/*   Updated: 2024/07/24 01:55:42 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// void draw_mandel(mlx_t *mlx, t_frac *mb);

int		ft_strcmp(char *s1, char *s2, int n)
{
	if (s1 == NULL || s2 == NULL || n <= 0)
		return (0);
	while (*s1 == *s2 && n > 0  && s2 != (void *)0)
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
		write(fd, &s[i], 1);
		i++;
	}
}


