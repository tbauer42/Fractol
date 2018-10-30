/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 20:28:25 by tbauer            #+#    #+#             */
/*   Updated: 2018/10/30 20:48:40 by tbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_code(int button,int x, int y, t_img *o)
{
	o->flag++;
	//mlx_clear_window(o->mlx, o->win);
	if (button == MOLUP)
		o->zoom += 100;
	if (button == MOLDOWN)
		o->zoom -= 100;
	if (o->julio == 1)
		julia(o);
	else if (o->brot == 1)
		mandelbrot(o);
	else if (o->shipo == 1)
		ship(o);
	return 0;
}
