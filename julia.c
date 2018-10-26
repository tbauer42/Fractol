/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 19:07:08 by tbauer            #+#    #+#             */
/*   Updated: 2018/10/26 19:23:48 by tbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"

void	init_julia(t_img *o)
{
	o->x1 = -1;
	o->x2 = 1;
	o->y1 = -1.2;
	o->y2 = 1.2;
	o->zoom = 400;
	o->image_x = (o->x2 - o->x1) * o->zoom;
	o->image_y = (o->y2 - o->y1) * o->zoom;
	o->x = 0;
	o->y = 0;
}

void	julia(t_img *o)
{
	init_julia(o);
	while (o->x < o->image_x)
	{
		o->y = 0;
		while (o->y < o->image_y)
		{
			o->rc = 0.285;
			o->ic = 0.01;
			o->rz = o->x / o->zoom + o->x1;
			o->iz = o->y / o->zoom + o->y1;
			o->i = 0;
			while (o->rz*o->rz + o->iz*o->iz < 4 && o->i < 150)
			{
				o->tmp = o->rz;
				o->rz = o->rz * o->rz - o->iz * o->iz + o->rc;
				o->iz = 2 * o->iz * o->tmp + o->ic;
				o->i++;
			}
			if (o->i == 150 )
				my_putpixel(o, o->x, o->y, 0x000000);
			else
				my_putpixel(o, o->x, o->y, o->i * 255 /150);
			o->y++;
		}
		o->x++;
	}
}


