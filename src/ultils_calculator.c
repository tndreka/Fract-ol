/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultils_calculator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka <tndreka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 01:10:10 by tndreka           #+#    #+#             */
/*   Updated: 2024/08/02 00:00:00 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "fractol.h"
/* NEEd to chec k if the point given is in the mandelbrot scale 
*/

#include "fractol.h"
//this function puts the specific range of the complex values of mandelbro
// X(-2 .. 0.5) [real] || Y(-1 .. 1)[imaginary] and converts it.
//on the function Z = Z^2 + c;  ===> in the first iteration we know 
//that the first poiint 
//its Z(0, 0) so out old min is Z(0,0) ==> so we can remove as the
// because we already know the value ... 
/*
	unscaled_n == The original scalue that needs to be scaled
	new_min == the minimum value of the range of the new range
	new_max == the maximum value of the range of the new range
	old_max == the maximum value of the old range
	(whith rhe assumption of ore old_min as 0)
	creates the new scale from [0, old_max] to [new_min, new_max]
	scale_calc(x, -2.0, 2.0, WIDHT) 
*/
double	scale_calc(double unsaled_n, double new_min, double new_max,
					double old_max)
{
	return ((new_max - new_min) * (unsaled_n / old_max) + new_min);
}

/*SUM COMPLEX CALCULAOR*/

t_frac	sum_complx(t_frac z1, t_frac z2)
{
	t_frac	sum;

	sum.x = z1.x + z2.x;
	sum.y = z1.y + z2.y;
	return (sum);
}

/*
power
real = (x ^2 - y^2)
imaginary = 2 * x * y
*/

t_frac	power_complx(t_frac z)
{
	t_frac	res;

	res.x = (z.x * z.x) - (z.y * z.y);
	res.y = 2 * z.x * z.y;
	return (res);
}
