/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:33:28 by mrusu             #+#    #+#             */
/*   Updated: 2024/03/18 17:48:31 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FdF.h"

float	absolute(float a)
{
	if (a < 0)
		return (a *= -1);
	return (a);
}

float	faster(float x, float y)
{
	if (x > y)
		return (x);
	return (y);
}

float	lerp(float a, float b, float step)
{
	return (a + step * (b - a));
}

void	reset_background(t_map *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < W_HEIGHT)
	{
		x = 0;
		while (x < W_WIDTH)
		{
			mlx_put_pixel(data->mlx_windows, x, y, 0x000000FF);
			x++;
		}
	y++;
	}
}

