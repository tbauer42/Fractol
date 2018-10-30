/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 20:00:06 by tbauer            #+#    #+#             */
/*   Updated: 2018/10/30 20:48:54 by tbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FRACTOL_H
# define FRACTOL_H

#include "Libft/includes/libft.h"
#include <stdlib.h>
#include "mlx.h"

# define ZOOM 69
# define DEZOOM 78
# define RIGHT 124
# define LEFT 123
# define BOT 125
# define TOP 126
# define ESC 53
# define MOLUP 5
# define MOLDOWN 4

typedef	struct	s_img
{
	int		brot;
	int		julio;
	int		shipo;
	int		flag;
	char **argv;
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
	double	z;
	int		k;
	double	image_x;
	double	image_y;
}				t_img;

int		mouse_code(int mouse,int x, int y, t_img *env);

int		key_code(int key, t_img *env);

void	my_putpixel(t_img *env, int x, int y, int color);

void	ship(t_img *env);

void	mandelbrot(t_img *env);

void	julia(t_img *env);

void	aff(t_img *env, char **argv, int argc);

#define WINX 450
#define WINY 450
#endif
