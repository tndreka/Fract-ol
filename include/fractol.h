/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka <tndreka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 18:45:55 by tndreka           #+#    #+#             */
/*   Updated: 2024/07/23 23:36:08 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "MLX42/MLX42.h" 
# include <stdio.h> 
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <math.h>

# define WIDTH 500
# define HEIGHT 500
# define MAXITERATIONS 1000
# define ERROR_MESSAGE "ERROR\n"

typedef struct s_frac
{
	double			x;
	double			y;
	double			esc_range;
    char 			*name;
    mlx_t 			*mlx;
	mlx_image_t		*image;
	int				*draw;

} t_frac;
// ARG CHECKER 
int	check_av(int ac, char **av);

//UTILS
void	ft_putstr_fd(char *s, int fd);
int		ft_strcmp(char *s1, char *s2, int n);

//Mandelbrot
int		init_mandel(t_frac *mb, mlx_t *mlx);
void	draw_mandel(mlx_t *mlx, t_frac *mb);

// MATH
double scale_calc(double unsaled_n, double new_min, double new_max, double old_min, double old_max);
t_frac sum_complx(t_frac z1, t_frac z2);
t_frac power_complx(t_frac z);
#endif