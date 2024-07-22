/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka <tndreka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 18:45:55 by tndreka           #+#    #+#             */
/*   Updated: 2024/07/22 21:19:09 by tndreka          ###   ########.fr       */
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

# define ERROR_MESSAGE "ERROR"

typedef struct s_frac
{
	void		*mlx_ptr;
	void		*mlx_window;
	void		*image;
}			t_frac;

// ARG CHECKER 
void	check_av(int ac, char **av);

//UTILS
void	ft_putstr_fd(char *s, int fd);
int		ft_strcmp(char *s1, char *s2, int n);
#endif