/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 20:01:16 by tbauer            #+#    #+#             */
/*   Updated: 2018/10/26 18:58:59 by tbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"

void	init_brot(t_img *o)
{
	o->x1 = -2.1;
	o->x2 = 0.6;
	o->y1 = -1.2;
	o->y2 = 1.2;
	o->zoom = 400;
	o->x = 0;
	o->y = 0;
	o->rc = 0;
	o->ic = 0;
	o->rz = 0;
	o->iz = 0;
	o->i = 0;
	o->tmp = 0;
	o->image_x = (o->x2 - o->x1) *o-> zoom;
	o->image_y = (o->y2 - o->y1) * o->zoom;
}

void recup(t_img *o)
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
}
