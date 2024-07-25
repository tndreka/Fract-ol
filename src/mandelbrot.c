/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka <tndreka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 21:26:16 by tndreka           #+#    #+#             */
/*   Updated: 2024/07/25 21:54:35 by tndreka          ###   ########.fr       */
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
uint32_t	ft_pixel(int r, int g, int b, int a)
{
	return ((r << 24 | g << 16 | b << 8 | a));
}

void	pixel_trick(int x, int y, t_frac *mb)
{
	t_frac		z;
	t_frac		c;
	int			iterations;
	t_color		color;

	z.x = 0.0;
	z.y = 0.0;
	c.x = scale_calc(x, -2, +2, WIDTH);
	c.y = scale_calc(y, +2, -2, HEIGHT);
	iterations = 0;
	while (iterations < MAXITERATIONS && ((z.x * z.x) + (z.y * z. y)) <= 4.0)
	{
		z = sum_complx(power_complx(z), c);
		iterations++;
	}
	color.channel[0] = (iterations * 9) % 256;
	color.channel[1] = (iterations * 5) % 256;
	color.channel[2] = (iterations * 3) % 256;
	color.channel[3] = 255;
	mlx_put_pixel(mb->image, x, y, color.color);
}

void	fractol(void *arg)
{
	uint32_t	x;
	uint32_t	y;
	t_frac		*mb;

	mb = (t_frac *)arg;
	y = -1;
	while (++y < mb->image->height)
	{
		x = -1;
		while (++x < mb->image->width)
		{
			pixel_trick(x, y, mb);
		}
	}
}

void	scroll_fractal(double xdelta, double ydelta, void *param)
{
	t_frac		*mb;
	mlx_t		*mlx;	
	double		heigth;
	double		width;
	double		zoom;

	xdelta = 0;
	z = 0.2;
	mb = (t_frac *)param;
	mlx = (t_frac *)param;
	heigh = mb->xmax - mb->xmin;
	heigh = mb->ymax - mb->ymin;
	if (ydelta > 0)
	{
		mb = mb->xmax + width * 
	}
	else if (ydelta < 0)
	{
	}
}
