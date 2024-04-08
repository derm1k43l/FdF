/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:33:28 by mrusu             #+#    #+#             */
/*   Updated: 2024/04/08 15:54:01 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FdF.h"

float	smooth_interpolate(float current, float target)
{
	float	diff;
	float	speed;

	speed = 0.015;
	diff = target - current;
	return (current + diff * speed);
}

float	absolute(float a)
{
	if (a < 0)
		return (a *= -1);
	else
		return (a);
}

void	cleanup_map(t_map *map)
{
	int	i;

	if (map == NULL)
		return ;
	if (map->depth_matrix != NULL)
	{
		i = 0;
		while (i < map->height)
		{
			free(map->depth_matrix[i]);
			i++;
		}
		free(map->depth_matrix);
		map->depth_matrix = NULL;
	}
	free(map);
}

float	maxim(float x, float y)
{
	if (x > y)
		return (x);
	else
		return (y);
}

void	error_exit(t_map *map, int flag)
{
	ft_printf("ERROR: Something went wrong!\n");
	if (flag == 0 || flag == 1 || flag == 2)
		cleanup_map(map);
	if (map != NULL)
	{
		free(map);
		map = NULL;
	}
	exit(EXIT_FAILURE);
}
