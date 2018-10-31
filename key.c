/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 15:52:54 by tbauer            #+#    #+#             */
/*   Updated: 2018/10/31 17:08:22 by tbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color_up(int key, t_img *o)
{
	if (key == L)
		o->color *= 5;
}

int		key_code(int key, t_img *o)
{
	o->flag++;
	color_up(key, o);
	if (key == ESC)
		exit(1);
	if (key == S)
		o->iter_max += 100;
	if (key == R)
		o->iter_max -= 100;
	if (key == RIGHT)
		o->x1 *= (1 + o->z);
	if (key == LEFT)
		o->x1 /= (1 + o->z);
	if (key == BOT)
		o->y1 *= (1 + o->z);
	if (key == TOP)
		o->y1 /= (1 + o->z);
	if (o->julio == 1)
		julia(o);
	else if (o->brot == 1)
		mandelbrot(o);
	else if (o->shipo == 1)
		ship(o);
	return (0);
}
