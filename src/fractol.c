/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka <tndreka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 18:45:42 by tndreka           #+#    #+#             */
/*   Updated: 2024/07/23 15:05:24 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#include <stdio.h>
/*	
**		PROJECT FRACT-OL
**	  MANDELBROT  and  JULIA
**	Fractol is a graphical application designed to explore different patterns of fractal
** 	Fractals are intriguing patterns that exhibiy self-similarity accros different scales,
**  meaning that they look similar no matter how much you zoom in or out. 
*/

/*				TO DO
	MANDELBROT 
	JULIA
	CHECK COMMAND LINE ARG for MANDELBROT & JULIA
	ZOOM WITH MOUSE 
	ESC - CLOSE THE PROGRAMM
	NO LEAKS
*/
int main(int ac, char **av)
{
	// mlx_t	*mlx;
	// t_frac 	*mb;
	// if (ac == 1)
	// 	return 0;
	if (ac > 2)
	{  
		ft_putstr_fd("choose a fractal name\n", 1);
    	return (EXIT_FAILURE);
	}
		check_av(ac, av);
		return (EXIT_SUCCESS);
}

	// mlx = mlx_init(WIDTH, HEIGHT, "FRACT-OL", true);
    //     if (!mlx)
    //     {
    //        ft_purstr_fd("Failed to initialize MLX\n, 1");
    //         return (EXIT_FAILURE);
    //     }
    //     mb = malloc(sizeof(t_frac));
    //     if (!mb)
    //     {
    //         mlx_strerror(mlx_errno);
    //         return (EXIT_FAILURE);
    //     }

    //     mb->mlx = mlx;
    //     mb->name = av[1]; // ose inicializoni sipas nevojës

    //     // Këtu mund të shtoni kodin për të vizatuar fractal-et duke përdorur `mb`

    //     mlx_loop(mlx);
    //     free(mb); // lironi memorien kur të mbaroni përdorimin e saj
    //     return (EXIT_SUCCESS);