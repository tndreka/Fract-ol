/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka <tndreka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 18:45:42 by tndreka           #+#    #+#             */
/*   Updated: 2024/07/28 05:04:50 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*	
**		PROJECT FRACT-OL
**	  MANDELBROT  and  JULIA
**	Fractol is a graphical application designed to explore different 
**	patterns of fractal
** 	Fractals are intriguing patterns that exhibiy self-similarity accros 
**	different scales,
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
// void	leaks(void)
// {
// 	system("leaks fractol");
//	atexit(leaks);
// }

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		ft_putstr_fd("choose a fractal name\n", 1);
		return (EXIT_FAILURE);
	}
	check_av(ac, av);
	return (EXIT_SUCCESS);
}

int	check_av(int ac, char **av)
{
	mlx_t	*mlx;
	t_frac	*mb;

	mlx = NULL;
	mb = NULL;
	if (ac == 2 && !(ft_strcmp(av[1], "mandelbrot", 10)))
		return (init_mandelbrot());
	if (ac == 4 && !(ft_strcmp(av[1], "julia", 5)))
		return (init_julia(av));
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

int	init_mandelbrot(void)
{
	mlx_t	*mlx;
	t_frac	*mb;

	mlx = NULL;
	mb = NULL;
	mb = malloc(sizeof(t_frac));
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	mlx = mlx_init(HEIGHT, WIDTH, "FRACT-OL", true);
	mb->xmin = -2.0;
	mb->xmax = 2.0;
	mb->ymin = -2.0;
	mb->ymax = 2.0;
	init_mandel(mb, mlx);
	mlx_loop_hook(mlx, fractol, mb);
	mlx_scroll_hook(mlx, scroll_fractal, (void *)mb);
	mlx_key_hook(mlx, ft_escape, (void *)mb);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	free(mb);
	return (EXIT_SUCCESS);
}

int	init_julia(char **av)
{
	mlx_t	*mlx;
	t_frac	*mb;

	mlx = NULL;
	mb = NULL;
	mb = malloc(sizeof(t_frac));
	mb->jx = ft_a_to_f(av[2]);
	mb->jy = ft_a_to_f(av[3]);
	mb->xmin = -1.5;
	mb->xmax = 1.5;
	mb->ymin = -1.5;
	mb->ymax = 1.5;
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	mlx = mlx_init(HEIGHT, WIDTH, "FRACT-OL", true);
	init_mandel(mb, mlx);
	mlx_loop_hook(mlx, fractol_julia, mb);
	mlx_scroll_hook(mlx, scroll_fractal, (void *)mb);
	mlx_key_hook(mlx, ft_escape, (void *)mb);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	free(mb);
	return (EXIT_SUCCESS);
}

int	init_mandel(t_frac *mb, mlx_t *mlx)
{
	if (!mlx || !mb)
	{
		mlx_strerror(mlx_errno);
		return (EXIT_FAILURE);
	}
	mb->image = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!mb->image)
	{
		mlx_close_window(mlx);
		mlx_strerror(mlx_errno);
		return (EXIT_FAILURE);
	}
	if (-1 == mlx_image_to_window(mlx, mb->image, 0, 0))
	{
		mlx_close_window(mlx);
		mlx_strerror(mlx_errno);
		return (EXIT_FAILURE);
	}
	mb->mlx = mlx;
	return (EXIT_SUCCESS);
}
