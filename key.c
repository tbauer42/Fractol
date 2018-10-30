/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 15:52:54 by tbauer            #+#    #+#             */
/*   Updated: 2018/10/30 15:15:57 by tbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoum(t_img *o)
{
	o->zoom += 100;
}

int		key_code(int key, t_img *o)
{
	mlx_clear_window(o->mlx, o->win);
	if (key == ZOOM)
		zoum(o);/*o->zoom+=100;
	if (key == DEZOOM)
		o->zoom-=100;
	if (key == RIGHT)
		o->x1 += 0.1;
	if (key == LEFT)
		o->x2 -= 0.1;
	if (key == BOT)
		o->y1 += 0.1;
	if (key == TOP)
		o->y2 -= 0.1;*/
	mandelbrot(o);
	return 0;
}

