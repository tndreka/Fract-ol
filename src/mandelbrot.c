/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka <tndreka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 21:26:16 by tndreka           #+#    #+#             */
/*   Updated: 2024/07/24 15:02:54 by tndreka          ###   ########.fr       */
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
uint32_t ft_pixel(int r, int g, int b, int a)
{
	return((r << 24 | g << 16 | b << 8 | a));
}

void pixel_trick(int x, int y, t_frac *mb)
{
	t_frac		z;
	t_frac		c;
	int			iterations;
	uint32_t	color;
	int			r;
	int			g;
	int			b;
	int			a;
	
	//the first iteration
	z.x = 0.0;
	z.y = 0.0;
	
	// we get the cordinates for X & Y to fit mandelbrot scale 
	c.x = scale_calc(x, -2, +2, WIDTH);
	c.y = scale_calc(y, +2, -2, HEIGHT);
	
	iterations = 0;
	while(iterations < MAXITERATIONS && ((z.x * z.x) + (z.y * z. y)) <= 4.0) // how many time you iterate in the mandelbron equacionee 
	{
		z = sum_complx(power_complx(z), c);
		//lets se if we are in the scale zone of mandel bron if not or point is out of scale 
		//if ((z.x * z.x) + (z.y * z. y)){}
		iterations++;
	}
	//get colors
	r = (iterations * 9) % 256;
	g = (iterations * 5) % 256;
	b = (iterations * 3) % 256;
	a = 255;
	color = ft_pixel(r, g, b, a);
	mlx_put_pixel(mb->image, x, y, color);
}

void fractol(void *arg)
{
	uint32_t	x;
	uint32_t 	y;
	t_frac	*mb;

	mb = (t_frac *)arg;	
	y = -1;
	while(y < mb->image->height )
	{
		x = -1;
		while(x < mb->image->width )
		{
			pixel_trick(x, y, mb);
			x++;
		}
		y++;
	}
}
