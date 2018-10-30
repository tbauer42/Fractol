/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 20:01:16 by tbauer            #+#    #+#             */
/*   Updated: 2018/10/30 20:13:56 by tbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"

void	init_brot(t_img *o)
{
	if (o->flag == 0)
	{
		o->x1 = -2.0;
		o->x2 = 1.0;
		o->y1 = -1.5;
		o->y2 = 1.5;
		o->zoom = 150;
		o->image_x = (o->x2 - o->x1) *o-> zoom;
		o->image_y = (o->y2 - o->y1) * o->zoom;
	}
		o->x = 0;
		o->y = 0;
		o->rc = 0;
		o->ic = 0;
		o->rz = 0;
		o->iz = 0;
		o->i = 0;
		o->tmp = 0;

	//mlx_clear_window(o->mlx, o->win);
	mlx_destroy_image(o->mlx, o->img);
	o->pix = mlx_get_data_addr(o->img, &o->bpp, &o->size_line, &o->endian);
	o->img = mlx_new_image(o->mlx, WINX, WINY);
}

void mandelbrot(t_img *o)
{
	init_brot(o);
	while (o->x < o->image_x)
	{
		o->y = 0;
		while (o->y < o->image_y)
		{
			o->rc = o->x / o->zoom + o->x1;
			o->ic = o->y / o->zoom + o->y1;
			o->rz = 0;
			o->iz = 0;
			o->i = 0;
			while (o->rz*o->rz + o->iz*o->iz < 4 && o->i < 50)
			{
				o->tmp = o->rz;
				o->rz = o->rz*o->rz - o->iz*o->iz + o->rc;
				o->iz = 2*o->iz*o->tmp + o->ic;
				o->i++;
			}
			if (o->i == 50)
				my_putpixel(o, o->x, o->y, 0x000000);
			else
				my_putpixel(o, o->x, o->y, o->i*255 / 50);
			o->y++;
		}
		o->x++;
	}
	mlx_put_image_to_window(o->mlx, o->win, o->img, 0, 0);
}
