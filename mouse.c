/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 20:28:25 by tbauer            #+#    #+#             */
/*   Updated: 2018/10/31 16:36:41 by tbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_it(t_img *o, int x, int y)
{
	o->guy = x;
	o->guy2 = y;
	if (o->julio == 1)
		julia(o);
	else if (o->brot == 1)
		mandelbrot(o);
	else if (o->shipo == 1)
		ship(o);
}

int		mouse_code(int button, int x, int y, t_img *o)
{
	o->flag++;
	if (button == MOLUP)
	{
		if (o->k == 10)
		{
			o->k = 0;
			o->z /= 10;
		}
		o->k++;
		o->zoom /= 1.5;
		o->zoom /= 0.5;
	}
	if (button == MOLDOWN)
	{
		if (o->j == 10)
		{
			o->j = 0;
			o->z *= 10;
		}
		o->j++;
		o->zoom /= 1.5;
	}
	draw_it(o, x, y);
	return (0);
}
