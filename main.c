/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 19:59:02 by tbauer            #+#    #+#             */
/*   Updated: 2018/10/30 15:30:36 by tbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"

int	main(int argc, char **argv)
{
	t_img	env;

	env.zoom = 150;
	env.img_x = WINX;
	env.img_y = WINY;
	ft_putchar('a');
	env.mlx = mlx_init();
	ft_putchar('b');
	env.img = mlx_new_image(env.mlx, env.img_x, env.img_y);
	ft_putchar('c');
	env.win = mlx_new_window(env.mlx, WINX, WINY, "fractol");
	ft_putchar('d');
	env.pix = mlx_get_data_addr(env.img, &env.bpp, &env.size_line, &env.endian);
	ft_putchar('a');
	aff(&env, argv, argc);
	ft_putchar('b');
	//mlx_put_image_to_window(env.mlx, env.win, env.img, 0, 0);
	mlx_key_hook(env.win, key_code, &env);
	mlx_loop(env.mlx);
	return (0);
}
