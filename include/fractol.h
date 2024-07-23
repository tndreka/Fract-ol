/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka <tndreka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 18:45:55 by tndreka           #+#    #+#             */
/*   Updated: 2024/07/23 15:40:45 by tndreka          ###   ########.fr       */
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

# define ERROR_MESSAGE "ERROR\n"

typedef struct s_frc
{
	double			re;
	double			im;
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
int		init_mandel(t_frac *mb, mlx_t *mlx);
#endif