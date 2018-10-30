/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 15:52:54 by tbauer            #+#    #+#             */
/*   Updated: 2018/10/30 20:44:18 by tbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoum(t_img *o)
{
	o->zoom += 100;
}

int		key_code(int key, t_img *o)
{
	o->flag++;
	//mlx_clear_window(o->mlx, o->win);
	if (key == ESC)
		exit(1);
	if (key == ZOOM)
		o->zoom+=100;
	if (key == DEZOOM)
		o->zoom-=100;
	if (key == RIGHT)
		o->x1 -= 0.05;
	if (key == LEFT)
		o->x1 += 0.05;
	if (key == BOT)
		o->y1 -= 0.05;
	if (key == TOP)
		o->y1 += 0.05;
	if (o->julio == 1)
		julia(o);
	else if (o->brot == 1)
		mandelbrot(o);
	else if (o->shipo == 1)
		ship(o);
	return 0;
}

