/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:04:40 by mrusu             #+#    #+#             */
/*   Updated: 2024/04/02 15:50:49 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FdF.h"

void	init_struct(t_map *map)
{
	map->init = mlx_init(1920, 1080, "FdF by mrusu", true);
	map->win = mlx_new_image(map->init, W_WIDTH, W_HEIGHT);
	map->size = 25;
	map->x_position = 800;
	map->y_position = 240;
	map->sin_angle = 1.200;
	map->cos_angle = 0.362;
	map->sin_z_angle = 0.0;
	map->cos_z_angle = 0.0;
	map->depth_scale = 0.135;
	map->color_base = 0xFFD700FF;
	map->color_transit = 0xFF6347FF;
	map->color_top = 0x4682B4FF;
}

int	main(int ac, char **av)
{
	t_map	*map;

	if (ac != 2)
		return (ft_printf("Usage: ./fdf <filename>.fdf\n"), 1);
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		error_exit(NULL, -3);
	read_map(av[1], map);
	init_struct(map);
	if ((mlx_image_to_window(map->init, map->win, 0, 0)) == -1)
		error_exit(map, 1);
	draw_base(map);
	if (!(mlx_loop_hook(map->init, key_hook, map)))
		error_exit(map, 1);
	mlx_loop(map->init);
	mlx_terminate(map->init);
	free(map);
	return (EXIT_SUCCESS);
}
