/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 19:07:08 by tbauer            #+#    #+#             */
/*   Updated: 2018/10/31 17:09:17 by tbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"

void	init_julia(t_img *o)
{
	if (o->flag == 0)
	{
		o->x1 = -1.1;
		o->x2 = 1.9;
		o->y1 = -1.2;
		o->y2 = 1.43;
		o->zoom = 170;
		o->iter_max = 150;
		o->image_x = (o->x2 - o->x1) * o->zoom;
		o->image_y = (o->y2 - o->y1) * o->zoom;
	}
	o->x = 0;
	o->y = 0;
	mlx_destroy_image(o->mlx, o->img);
	o->pix = mlx_get_data_addr(o->img, &o->bpp, &o->size_line, &o->endian);
	o->img = mlx_new_image(o->mlx, WINX, WINY);
}

void	for_norm(t_img *o)
{
	o->tmp = o->rz;
	o->rz = o->rz * o->rz - o->iz * o->iz + o->rc;
	o->iz = 2 * o->iz * o->tmp + o->ic;
	o->i++;
}

void	julia(t_img *o)
{
	init_julia(o);
	while (o->x < o->image_x)
	{
		o->y = 0;
		while (o->y < o->image_y)
		{
			if (!o->flag)
			{
				o->rc = 0.285;
				o->ic = 0.01;
			}
			o->rz = o->x / o->zoom + o->x1;
			o->iz = o->y / o->zoom + o->y1;
			o->i = 0;
			while (o->rz * o->rz + o->iz * o->iz < 4 && o->i < o->iter_max)
				for_norm(o);
			if (o->i == o->iter_max)
				my_putpixel(o, o->x, o->y, 0x000000);
			else
				my_putpixel(o, o->x, o->y, o->i * o->color);
			o->y++;
		}
		o->x++;
	}
	mlx_put_image_to_window(o->mlx, o->win, o->img, 0, 0);
}
