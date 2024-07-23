/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka <tndreka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 21:08:44 by tndreka           #+#    #+#             */
/*   Updated: 2024/07/23 23:25:53 by tndreka          ###   ########.fr       */
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

int	check_av(int ac, char **av)
{
	mlx_t	*mlx = NULL;
	t_frac 	*mb = NULL;
	
	if (ac == 2 &&  !(ft_strcmp(av[1], "mandelbrot", 10)))
	{
		mlx = mlx_init(WIDTH, HEIGHT, "FRACT-OL", true);
		mb = malloc(sizeof(t_frac));
		init_mandel(mb, mlx);
		mlx_loop(mlx);
        free(mb);
    }
	else if (ac == 4 &&  !(ft_strcmp(av[1], "julia", 5)))
	{
		//implement julia
	}
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);	
		exit(EXIT_FAILURE);
		
	}
	exit(EXIT_SUCCESS);
}

int init_mandel(t_frac *mb, mlx_t *mlx)
{
    if (!mlx)
	{
		mlx_strerror(mlx_errno);
        return (EXIT_FAILURE);
	}
	mb->image = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!mb->image)
    {
		mlx_close_window(mlx);
    	mlx_strerror(mlx_errno);
        return (EXIT_FAILURE);
	}
	if(-1 == mlx_image_to_window(mlx, mb->image, 0, 0))
	{
		mlx_close_window(mlx);
    	mlx_strerror(mlx_errno);
        return (EXIT_FAILURE);
	}
    return (0);			
}
