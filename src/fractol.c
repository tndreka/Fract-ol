/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka <tndreka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 18:45:42 by tndreka           #+#    #+#             */
/*   Updated: 2024/07/23 17:44:04 by tndreka          ###   ########.fr       */
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
	if (ac > 2)
	{  
		ft_putstr_fd("choose a fractal name\n", 1);
    	return (EXIT_FAILURE);
	}
		check_av(ac, av);
		return (EXIT_SUCCESS);
		
}
