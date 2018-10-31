/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 15:26:38 by tbauer            #+#    #+#             */
/*   Updated: 2018/10/31 18:02:29 by tbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	no_param(void)
{
	ft_putstr("Try with : Mandelbrot, Julia or Burningship.\n");
	exit(1);
}

void	aff(t_img *o, char **av, int argc)
{
	if (argc == 2)
	{
		if (ft_strcmp(av[1], "Mandelbrot") == 0)
		{
			o->brot = 1;
			mandelbrot(o);
		}
		else if (ft_strcmp(av[1], "Julia") == 0)
		{
			o->julio = 1;
			julia(o);
		}
		else if (ft_strcmp(av[1], "Burningship") == 0)
		{
			o->shipo = 1;
			ship(o);
		}
		else
		{
			ft_putstr("Try with : Mandelbrot, Julia or Burningship.\n");
			exit(1);
		}
	}
	else
		no_param();
}
