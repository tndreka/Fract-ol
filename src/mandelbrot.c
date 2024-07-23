/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka <tndreka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 21:26:16 by tndreka           #+#    #+#             */
/*   Updated: 2024/07/23 23:38:44 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


/* NEEd to chec k if the point given is in the mandelbrot scale 

				map ------> √
				
			Z = Z^2 + c
			
//this function puts the specific range of the complex values of mandelbro
// X(-2 .. 0.5) [real] || Y(-1 .. 1)[imaginary] and converts it with our 
// HEIGHT AND WIDTH ==> transform the condinat  -22 to +2 to the scale 799 

	
*/
void pixel_trick(int x, int y, t_frac *fractal)
{
	t_frac	z;
	t_frac	c;
	int		iterations;
	//the first iteration
	z.x = 0.0;
	z.y = 0.0;
	
	// we get the cordinates for X & Y to fit mandelbrot scale 
	c.x = scale_calc(x, -2, +2, WIDTH);
	c.y = scale_calc(y, +2, -2, HEIGHT);
	
	iteratons = 0;
	while(interations < MAXITERATIONS && ((z.x * z.x) + (z.y * z. y)) <= 4.0) // how many time you iterate in the mandelbron equacionee 
	{
		z = sum_complx(power_complx(z), c);
		//lets se if we are in the scale zone of mandel bron if not or point is out of scale 
		//if ((z.x * z.x) + (z.y * z. y)){}
		iterations++;
	}
	
	
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