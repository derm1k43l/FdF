/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:33:12 by mrusu             #+#    #+#             */
/*   Updated: 2024/04/08 16:42:03 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FdF.h"

void	key_hook(void *parameter)
{
	t_map			*map;

	map = parameter;
	if (mlx_is_key_down(map->init, MLX_KEY_ESCAPE))
		mlx_close_window(map->init);
	if (mlx_is_key_down(map->init, MLX_KEY_UP))
		map->y_position -= 5;
	if (mlx_is_key_down(map->init, MLX_KEY_DOWN))
		map->y_position += 5;
	if (mlx_is_key_down(map->init, MLX_KEY_LEFT))
		map->x_position -= 5;
	if (mlx_is_key_down(map->init, MLX_KEY_RIGHT))
		map->x_position += 5;
	if (mlx_is_key_down(map->init, MLX_KEY_KP_5))
		reset_struct(map);
	if (mlx_is_key_down(map->init, MLX_KEY_KP_ENTER))
		palette_yellowish(map);
	if (mlx_is_key_down(map->init, MLX_KEY_KP_0))
		palette_calming(map);
	other_key_hook(map);
	rotation_hook(map);
	reset_background(map);
	draw_base(map);
	print_current_values(map);
}

void	rotation_hook(t_map *map)
{
	if (mlx_is_key_down(map->init, MLX_KEY_KP_ADD))
		map->size += 0.15;
	if (mlx_is_key_down(map->init, MLX_KEY_KP_SUBTRACT))
		map->size -= 0.15;
	if (map->is_3d)
	{
		if (mlx_is_key_down(map->init, MLX_KEY_KP_8))
			map->cos_z_angle = smooth_interpolate(map->cos_z_angle, 5.0);
		if (mlx_is_key_down(map->init, MLX_KEY_KP_2))
			map->cos_z_angle = smooth_interpolate(map->cos_z_angle, -5.0);
		if (mlx_is_key_down(map->init, MLX_KEY_KP_4))
			map->sin_angle = smooth_interpolate(map->sin_angle, 5.0);
		if (mlx_is_key_down(map->init, MLX_KEY_KP_6))
			map->sin_angle = smooth_interpolate(map->sin_angle, -5.0);
		if (mlx_is_key_down(map->init, MLX_KEY_KP_1))
			map->sin_z_angle = smooth_interpolate(map->sin_z_angle, 5.0);
		if (mlx_is_key_down(map->init, MLX_KEY_KP_3))
			map->sin_z_angle = smooth_interpolate(map->sin_z_angle, -5.0);
		if (mlx_is_key_down(map->init, MLX_KEY_KP_7))
			map->cos_angle = smooth_interpolate(map->cos_angle, 5.0);
		if (mlx_is_key_down(map->init, MLX_KEY_KP_9))
			map->cos_angle = smooth_interpolate(map->cos_angle, -5.0);
	}
}

void	other_key_hook(t_map *map)
{
	if (mlx_is_key_down(map->init, MLX_KEY_KP_EQUAL))
	{
		if (map->color_base == (int)0xFFD700FF)
			map->color_base = 0x000000FF;
		else
			map->color_base = 0xFFD700FF;
	}
	if (mlx_is_key_down(map->init, MLX_KEY_KP_DIVIDE))
	{
		if (map->color_top == (int)0x4682B4FF)
			map->color_top = 0x000000FF;
		else
			map->color_top = 0x4682B4FF;
	}
	if (mlx_is_key_down(map->init, MLX_KEY_KP_MULTIPLY))
		map->sin_angle = 0.0;
	if (mlx_is_key_down(map->init, MLX_KEY_PAGE_UP))
		map->depth_scale += 0.005;
	if (mlx_is_key_down(map->init, MLX_KEY_PAGE_DOWN))
		map->depth_scale -= 0.005;
	if (mlx_is_key_down(map->init, MLX_KEY_KP_DECIMAL))
	{
		map->is_3d = !map->is_3d;
		usleep(500000);
	}
}

void	reset_struct(t_map *map)
{
	map->size = 25;
	map->x_position = 800;
	map->y_position = 240;
	map->sin_angle = 1.200;
	map->cos_angle = 0.362;
	map->sin_z_angle = 0.0;
	map->cos_z_angle = 0.0;
	map->depth_scale = 0.1;
	map->color_base = 0xFFD700FF;
	map->color_transit = 0xFF6347FF;
	map->color_top = 0x4682B4FF;
	map->is_3d = true;
}
