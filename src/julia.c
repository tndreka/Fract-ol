/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka <tndreka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 21:26:09 by tndreka           #+#    #+#             */
/*   Updated: 2024/07/28 03:07:12 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pixel_trick_julia(int x, int y, t_frac *mb)
{
	t_frac		z;
	t_frac		c;
	int			iterations;
	t_color		color;

	z.x = scale_calc(x, mb->xmin, mb->xmax, WIDTH);
	z.y = -scale_calc(y, mb->ymin, mb->ymax, HEIGHT);
	c.x = mb->jx;
	c.y = mb->jy;
	// sleep(2);
	iterations = 0;
	while (iterations < MAXITERATIONS && ((z.x * z.x) + (z.y * z.y)) <= 4.0)
	{
		z = sum_complx(power_complx(z), c);
		z.x = scale_calc(x, mb->xmin, mb->xmax, WIDTH);
		z.y = scale_calc(y, mb->ymin, mb->ymax, HEIGHT);
		iterations++;
	}
	color.channel[0] = (iterations * 8) % 256;
	color.channel[1] = (iterations * 0) % 256;
	color.channel[2] = (iterations * 8) % 256;
	color.channel[3] = 255;
	mlx_put_pixel(mb->image, x, y, color.color);
}


void	fractol_julia(void *arg)
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
			pixel_trick_julia(x, y, mb);
		}
	}
}
