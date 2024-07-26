/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka <tndreka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 18:45:55 by tndreka           #+#    #+#             */
/*   Updated: 2024/07/27 00:51:28 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "MLX42/MLX42.h"
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 1042
# define HEIGHT 1042
# define MAXITERATIONS 42
# define ERROR_MESSAGE "ERROR\n"
# define BLACK	0x000000
# define WHITE	0xFFFFFF
# define RED	0xFF0000
# define GREEN	0x00FF00
# define BLUE	0x0000FF
# define MIN_RANGE 0.001

typedef union u_color
{
	u_int8_t	channel[4];
	u_int32_t	color;
}				t_color;

typedef struct s_frac
{
	double		x;
	double		y;
	double		xmin;
	double		xmax;
	double		ymin;
	double		ymax;
	char		*name;
	mlx_t		*mlx;
	mlx_image_t	*image;
	int			iter;
}				t_frac;
// ARG CHECKER
int				check_av(int ac, char **av);

// UTILS
void			ft_putstr_fd(char *s, int fd);
int				ft_strcmp(char *s1, char *s2, int n);
double			atobl(char *s);

// Mandelbrot
int				init_mandel(t_frac *mb, mlx_t *mlx);
void			pixel_trick(int x, int y, t_frac *fractal);
void			fractol(void *arg);
uint32_t		ft_pixel(int r, int g, int b, int a);

// MATH
double			scale_calc(double unsaled_n, double new_min, double new_max,
					double old_max);
t_frac			sum_complx(t_frac z1, t_frac z2);
t_frac			power_complx(t_frac z);
// double scale_calc(double unsaled_n, double new_min, double new_max, double old_min, double old_max);
// SCROLL HOOK
// void			scroll_fractal(double xdelta, double ydelta, void *param);
void	scroll_fractal(double x, double y, void *param);
#endif