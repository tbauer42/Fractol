/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 15:26:38 by tbauer            #+#    #+#             */
/*   Updated: 2018/10/29 15:48:05 by tbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	aff(t_img *o, char ** av, int argc)
{
	if (argc == 2)
	{
		if (ft_strcmp(av[1],"Mandelbrot") == 0)
			mandelbrot(o);
		else if (ft_strcmp(av[1],"Julia") == 0)
			julia(o);
		else if (ft_strcmp(av[1],"Burningship") == 0)
			ship(o);
		else
		{
			ft_putstr("Try with one of those parameter: Mandelbrot, Julia or Burning ship.\n");
			exit(1);
		}
	}
	else
	{
		ft_putstr("Try with one of those parameter: Mandelbrot, Julia or Burning ship.\n");
		exit(1);
	}
}

