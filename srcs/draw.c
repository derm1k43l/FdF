/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:33:07 by mrusu             #+#    #+#             */
/*   Updated: 2024/03/12 10:39:14 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FdF.h"

#define MOD(a) ((a < 0) ? -a : a)
#define MAX1(a, b) (a > b ? a : b)
float mod(float nr)
{
	return (i < 0) ? -i : i;
} 

void bresenham(int x, int y, int x1, int y1, t_map *data) // [1:1] [3:12]
{
	float x_step;
	float y_step;
	int max;

	z = data->z_matrix[(int)y][(int)x];
	z1 = data->z_matrix[(int)y1][(int)x1];
	
// zoom
	x *=data->zoom;
	y *=data->zoom;
	x1 *=data->zoom;
	y1 *=data->zoom;

//color
	data->color = (z || z1) ? 0xe80c0c : 0xffffff;

	x_step = x1 - x; //-2
	y_step = y1 - y; //-11
//isometric
	isometric(&x, &y, z);
	isometric(&x1, &y1, z1);

//shift
	x += 150;
	y += 150;
	x1 += 150;
	y1 += 150;

	max = MAX(MOD(x_step), MOD(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(data->mlx_dis, data->mlx_dis, x, y, data->color);
		x += x_step;
		y += y_step;
	}
}

void isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

void draw(t_map *data)
{
	int x;
	int y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				bresenham(x, y, x + 1, y, data);
			if (y < data->height - 1)
				bresenham(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
}
