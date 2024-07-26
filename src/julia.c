/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka <tndreka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 21:26:09 by tndreka           #+#    #+#             */
/*   Updated: 2024/07/26 20:37:35 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// uint32_t	ft_pixel(int r, int g, int b, int a)
// {
// 	return ((r << 24 | g << 16 | b << 8 | a));
// }

// void	pixel_trick(int x, int y, t_frac *mb)
// {
// 	t_frac		z;
// 	t_frac		c;
// 	int			iterations;
// 	t_color		color;

// 	z.x = scale_calc(x, -2, +2, WIDTH);
// 	z.y = scale_calc(y, +2, -2, HEIGHT);
// 	iterations = 0;
// 	while (iterations < MAXITERATIONS && ((z.x * z.x) + (z.y * z.y)) <= 4.0)
// 	{
// 		z = sum_complx(power_complx(z), c);
// 		iterations++;
// 	}
// 	color.channel[0] = (iterations * 9) % 256;
// 	color.channel[1] = (iterations * 5) % 256;
// 	color.channel[2] = (iterations * 3) % 256;
// 	color.channel[3] = 255;
// 	mlx_put_pixel(mb->image, x, y, color.color);
// }

// void	fractol(void *arg)
// {
// 	uint32_t	x;
// 	uint32_t	y;
// 	t_frac		*mb;

// 	mb = (t_frac *)arg;
// 	y = -1;
// 	while (++y < mb->image->height)
// 	{
// 		x = -1;
// 		while (++x < mb->image->width)
// 		{
// 			pixel_trick(x, y, mb);
// 		}
// 	}
// }

// void	ft_resize(int width, int height, void *mb)
// {
// 	(void)width;
// 	(void)height;
// 	t_frac	temp;
	
// 	temp = *(t_frac *)mb;
// 	mlx_delete_image(temp.mlx, temp.image);
// 	temp.image = mlx_new_image(temp.mlx, WIDTH, HEIGHT);
// 	if (mlx_image_to_window(temp.mlx, temp.image, 0, 0) == -1)
// 		return (mlx_close_window(temp.mlx), mlx_strerror(mlx_errno), exit(EXIT_FAILURE));
// 	fractol((void *)mb);
// }