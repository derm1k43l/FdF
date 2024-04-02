/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:41:04 by mrusu             #+#    #+#             */
/*   Updated: 2024/04/02 14:00:33 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FdF.h"

void	palette_yellowish(t_map *map)
{
	map->color_base = 0x9400D3FF;
	map->color_transit = 0xDA70D6FF;
	map->color_top = 0xFFD700FF;
}

void	palette_calming(t_map *map)
{
	map->color_base = 0x3C9E8EFF;
	map->color_transit = 0x50BFE6FF;
	map->color_top = 0xCCCCFFFF;
}

void	reset_background(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < W_HEIGHT)
	{
		x = 0;
		while (x < W_WIDTH)
		{
			mlx_put_pixel(map->win, x, y, 0x000000FF);
			x++;
		}
		y++;
	}
}

void	print_current_values(t_map *map)
{
	ft_printf("\n");
	ft_printf("\n");
	ft_printf("\n");
	ft_printf("\n");
	ft_printf("\n");
	ft_printf("\n");
	ft_printf("\n");
	ft_printf("\n");
	ft_printf("\n");
	ft_printf("\n");
	ft_printf("\n");
	ft_printf("\n");
	ft_printf("\n");
	ft_printf("\n======== Current Values ========\n");
	ft_printf("Size: 		   %d 	( + / - ZOOM)\n", map->size);
	ft_printf("X Position:	   %d	( LEFT / RIGHT)\n", map->x_position);
	ft_printf("Y Position:	   %d 	( UP / DOWN )\n", map->y_position);
	ft_printf("Sin Angle:      %f	( 4 / 6 )\n", map->sin_angle);
	ft_printf("Cos Angle:      %f 	( 7 / 9 )\n", map->cos_angle);
	ft_printf("Sin Z Angle:    %f	( 1 / 3 )\n", map->sin_z_angle);
	ft_printf("Cos Z Angle:    %f	( 2 / 8 )\n", map->cos_z_angle);
	ft_printf("Depth Scale:    %f	(Use Page Up/Down)\n", map->depth_scale);
}
