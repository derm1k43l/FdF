/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:33:07 by mrusu             #+#    #+#             */
/*   Updated: 2024/04/03 12:07:02 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FdF.h"

t_line	transform(t_map *map, t_line line)
{
	float	temp_x;
	float	temp_y;
	float	temp_x1;
	float	temp_y1;

	temp_x = (line.x_start - line.y_start) * cos(map->cos_angle);
	temp_y = (line.x_start + line.y_start) * sin(map->sin_angle) - line.z_start;
	temp_x1 = (line.x_end - line.y_end) * cos(map->cos_angle);
	temp_y1 = (line.x_end + line.y_end) * sin(map->sin_angle) - line.z_end;
	line.x_start = temp_x * cos(map->cos_z_angle)
		- temp_y * sin(map->sin_z_angle) + map->x_position;
	line.y_start = temp_x * sin(map->cos_z_angle)
		+ temp_y * cos(map->sin_z_angle) + map->y_position;
	line.x_end = temp_x1 * cos(map->cos_z_angle)
		- temp_y1 * sin(map->sin_z_angle) + map->x_position;
	line.y_end = temp_x1 * sin(map->cos_z_angle)
		+ temp_y1 * cos(map->sin_z_angle) + map->y_position;
	return (line);
}

void	bresenham(t_line line, t_map *map)
{
	int	max;

	line.z_start = map->depth_matrix[(int)line.y_start][(int)line.x_start];
	line.z_end = map->depth_matrix[(int)line.y_end][(int)line.x_end];
	line.z_start *= map->size * map->depth_scale;
	line.z_end *= map->size * map->depth_scale;
	line.x_start *= map->size;
	line.y_start *= map->size;
	line.x_end *= map->size;
	line.y_end *= map->size;
	line = transform(map, line);
	line.x_step = line.x_end - line.x_start;
	line.y_step = line.y_end - line.y_start;
	max = maxim(absolute(line.x_step), absolute(line.y_step));
	line.x_step /= max;
	line.y_step /= max;
	draw_line(line, map, max);
}

void	draw_line(t_line line, t_map *map, int max)
{
	if (!((line.x_start > 0 && line.x_start <= W_WIDTH)
			&& (line.x_end > 0 && line.x_end <= W_WIDTH)
			&& (line.y_start > 0 && line.y_start <= W_HEIGHT)
			&& (line.y_end > 0 && line.y_end <= W_HEIGHT)))
		return ;
	if (max == 0)
		return ;
	while ((int)(line.x_start - line.x_end) || (int)(line.y_start - line.y_end))
	{
		if (line.z_start == 0 && line.z_end == 0)
			mlx_put_pixel(map->win, line.x_start, line.y_start,
				map->color_base);
		else if (line.z_start != 0 && line.z_end != 0)
			mlx_put_pixel(map->win, line.x_start, line.y_start, map->color_top);
		else
			mlx_put_pixel(map->win, line.x_start, line.y_start,
				map->color_transit);
		line.x_start += line.x_step;
		line.y_start += line.y_step;
	}
}

void	draw_base(t_map *map)
{
	t_line	line;

	line.y_start = 0;
	while (line.y_start < map->height)
	{
		line.x_start = 0;
		while (line.x_start < map->width)
		{
			if (line.x_start < map->width - 1)
			{
				line.x_end = line.x_start + 1;
				line.y_end = line.y_start;
				bresenham(line, map);
			}
			if (line.y_start < map->height - 1)
			{
				line.x_end = line.x_start;
				line.y_end = line.y_start + 1;
				bresenham(line, map);
			}
			line.x_start++;
		}
		line.y_start++;
	}
}
