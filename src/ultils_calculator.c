/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultils_calculator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka <tndreka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 01:10:10 by tndreka           #+#    #+#             */
/*   Updated: 2024/07/24 21:58:37 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "fractol.h"
/* NEEd to chec k if the point given is in the mandelbrot scale 
*/

#include "fractol.h"
//this function puts the specific range of the complex values of mandelbro
// X(-2 .. 0.5) [real] || Y(-1 .. 1)[imaginary] and converts it with our 
// HEIGHT AND WIDTH ==> transform the condinat  -22 to +2 to the scale 800

//on the function Z = Z^2 + c;  ===> in the first iteration we know that the first poiint 
//its Z(0, 0) so out old min is Z(0,0) ==> so we can remove as the parameter the old_min 
// because we already know the value ... 


// double scale_calc(double unsaled_n, double new_min, double new_max, double old_min, double old_max)
// {
// 	return (new_max - new_min) * (unsaled_n - old_min)/(old_max - old_min) + new_min;
// }int main ()
// {
// 	for(int i=0; i < 800; ++i)
// 	{
// 	printf("%d -> %f\n",i ,scale_calc((double)i, -2, +2, 0, 799));	
// 	}
// }
double scale_calc(double unsaled_n, double new_min, double new_max, double old_max)
{
	return (new_max - new_min) * (unsaled_n /old_max) + new_min;
}
// int main ()
// {
// 	for(int i=0; i < 800; ++i)
// 	{
// 	printf("%d -> %f\n",i ,scale_calc((double)i, -2, +2, 799));	
// 	}
// }

/*SUM COMPLEX CALCULAOR*/

t_frac sum_complx(t_frac z1, t_frac z2)
{
	t_frac sum;

	sum.x = z1.x + z2.x;
	sum.y = z1.y + z2.y;
	
	return (sum);
}

/*
power
real = (x ^2 - y^2)
imaginary = 2 * x * y
*/

t_frac power_complx(t_frac z)
{
	t_frac res;

	res.x = (z.x * z.x) - (z.y * z.y);
	res.y = 2 * z.x * z.y;
	
	return (res);
}