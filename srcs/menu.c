/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:33:22 by mrusu             #+#    #+#             */
/*   Updated: 2024/03/15 11:06:39 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FdF.h"

void	print_menu(t_map *fdf) // just example 
{
	int		y;
	void	*mlx;
	void	*win;

	y = 0;
	mlx = fdf->mlx;
	win = fdf->win;
	mlx_string_put(mlx, win, 65, y += 20, TEXT_COLOR, "How to Use");
	mlx_string_put(mlx, win, 15, y += 35, TEXT_COLOR, "Zoom: Scroll or +/-");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Move: Arrows");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Flatten: </>");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Rotate: Press & Move");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Rotate:");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "X-Axis - 2/8");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "Y-Axis - 4/6");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "Z-Axis - 1(3)/7(9)");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Projection");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "ISO: I Key");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "Parallel: P Key");
}