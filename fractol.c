/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 20:34:09 by tbauer            #+#    #+#             */
/*   Updated: 2018/10/24 20:35:29 by tbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"

void	my_putpixel(t_img *env, int x, int y, int color)
{
	int	pos;
	int	mask;

	if ((x >= 0 && x <= WINX) && (y >= 0 && y <= WINY))
	{
		pos = (y * env->size_line + x * 4);
		mask = color;
		env->pix[pos] = mask;
		color = color >> 8;
		mask = color;
		env->pix[pos + 1] = mask;
		color = color >> 8;
		mask = color;
		env->pix[pos + 2] = mask;
		env->pix[pos + 3] = 0x00;
	}
}
