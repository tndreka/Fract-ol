/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka <tndreka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 21:26:16 by tndreka           #+#    #+#             */
/*   Updated: 2024/07/23 22:24:40 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


/* NEEd to chec k if the point given is in the mandelbrot scale 
*/


//this function puts the specific range of the complex values of mandelbro
// X(-2 .. 0.5) [real] || Y(-1 .. 1)[imaginary] and converts it with our 
// HEIGHT AND WIDTH ==> transform the condinat  -22 to +2 to the scale 800

void pixel_trick(int x, int y, t_frac *fractal)
{
		
}

void fractol(t_frac *fractal)
{
	int x;
	int y;

	y = -1;
	while(HEIGHT > y)
	{
		x = -1;
		while(WIDTH > x)
		{
			pixel_trick(x, y, fractal);
			x++;
		}
		y++;
	}
}