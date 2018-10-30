/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 15:17:26 by tbauer            #+#    #+#             */
/*   Updated: 2018/10/30 20:07:39 by tbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

void	init_ship(t_img *o)
{
	if (o->flag == 0)
	{
		o->x1 = -2.1;
		o->x2 = 1.5;
		o->y1 = -2.1;
		o->y2 = 1.5;
		o->zoom = 125;
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
	mlx_destroy_image(o->mlx, o->img);
	o->pix = mlx_get_data_addr(o->img, &o->bpp, &o->size_line, &o->endian);
	o->img = mlx_new_image(o->mlx, WINX, WINY);

}

void	ship(t_img *o)
{
	init_ship(o);
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
			while (o->rz*o->rz + o->iz*o->iz < 4 && o->i < 100)
			{
				o->tmp = o->rz;
				o->rz = o->rz*o->rz - o->iz*o->iz + o->rc;
				o->iz = 2* fabs(o->iz)* fabs(o->tmp) + o->ic;
				o->i++;
			}
			if (o->i == 50)
				my_putpixel(o, o->x, o->y, 0x000000);
			else
				my_putpixel(o, o->x, o->y, o->i* 10000);
			o->y++;
		}
		o->x++;
	}
	mlx_put_image_to_window(o->mlx, o->win, o->img, 0, 0);
}
