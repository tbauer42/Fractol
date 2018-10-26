/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 20:00:06 by tbauer            #+#    #+#             */
/*   Updated: 2018/10/26 19:22:44 by tbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FRACTOL_H
# define FRACTOL_H

#include "Libft/includes/libft.h"
#include <stdlib.h>
#include "mlx.h"

typedef	struct	s_img
{
	void	*img;
	void	*win;
	void	*mlx;
	void	*adr;
	char	*pix;
	int		endian;
	int		img_x;
	int		img_y;
	int		bpp;
	int		size_line;
	double	x1;
	double	x2;
	double	y1;
	double	y2;
	double	zoom;
	int		x;
	int		y;
	double	rc;
	double	ic;
	double	rz;
	double	iz;
	double	tmp;
	int		i;
	double	image_x;
	double	image_y;
}				t_img;

void	my_putpixel(t_img *env, int x, int y, int color);

void	recup(t_img *env);

void	julia(t_img *env);

#define WINX 1400
#define WINY 1400
#endif
