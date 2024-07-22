/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka <tndreka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 18:45:42 by tndreka           #+#    #+#             */
/*   Updated: 2024/07/22 03:44:29 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#include <stdio.h>

// int main()
// {
// 	void *mlx_ptr;
	
// 	//mlx_set_setting(MLX_MAXIMIZED, true);
// 	mlx_ptr = mlx_init( WIDTH, HEIGHT, "42BUFU", true);
// 	if(!mlx_ptr)
// 		return 1;
// 	mlx_loop(mlx_ptr);
	
// 	printf("HERE");
// 	return 0;
// }

int main()
{
	t_mlx_ptr *data;
	
	data->mlx_ptr = mlx_init(WIDTH, HEIGHT, "42BUFU", true);
	if(!data->mlx_ptr)
		return 1;
	mlx_loop(data->mlx_ptr);
	 
	
	return 0;
}