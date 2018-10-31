/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 19:59:02 by tbauer            #+#    #+#             */
/*   Updated: 2018/10/31 18:58:43 by tbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"

void	ft_error(int argc, char **av)
{
	if (!((argc == 2) && ((ft_strcmp(av[1], "Mandelbrot") == 0) || \
			(ft_strcmp(av[1], "Julia") == 0) || \
			(ft_strcmp(av[1], "Burningship") == 0))))
		exit(1);
}

int		main(int argc, char **argv)
{
	t_img	env;

	env.color = 100;
	env.flag = 0;
	env.brot = 0;
	env.julio = 0;
	env.shipo = 0;
	env.k = 0;
	env.z = 0.1;
	env.j = 0;
	ft_error(argc, argv);
	env.img_x = WINX;
	env.img_y = WINY;
	env.mlx = mlx_init();
	env.img = mlx_new_image(env.mlx, env.img_x, env.img_y);
	env.win = mlx_new_window(env.mlx, WINX, WINY, "fractol");
	env.pix = mlx_get_data_addr(env.img, &env.bpp, &env.size_line, &env.endian);
	aff(&env, argv, argc);
	mlx_mouse_hook(env.win, mouse_code, &env);
	mlx_key_hook(env.win, key_code, &env);
	if (env.julio == 1)
		mlx_hook(env.win, 6, (1L << 6), ft_moovit, &env);
	mlx_loop(env.mlx);
	return (0);
}
