/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 19:59:02 by tbauer            #+#    #+#             */
/*   Updated: 2018/10/26 19:22:50 by tbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"

int	main(int argc, char **argv)
{
	t_img	env;

	env.img_x = WINX;
	env.img_y = WINY;
	env.mlx = mlx_init();
	env.img = mlx_new_image(env.mlx, env.img_x, env.img_y);
	env.win = mlx_new_window(env.mlx, WINX, WINY, "fractol");
	env.pix = mlx_get_data_addr(env.img, &env.bpp, &env.size_line, &env.endian);
	julia(&env);
	mlx_put_image_to_window(env.mlx, env.win, env.img, 0, 0);
	mlx_loop(env.mlx);
	return (0);
}
