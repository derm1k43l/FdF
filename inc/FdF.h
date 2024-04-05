/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:14:31 by mrusu             #+#    #+#             */
/*   Updated: 2024/04/05 15:02:17 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// Standard
# include <signal.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/types.h>
# include <fcntl.h>
# include <stdbool.h>
# include <limits.h>
# include <math.h>
# include <errno.h>

// Extra
# include "../libft/inc/libft.h"
# include "../mlx42/include/MLX42/MLX42.h"

// Colors
# define SHELL_RED "\033[0;31m"
# define SHELL_GREEN "\033[0;32m"
# define SHELL_YELLOW "\033[0;33m"
# define SHELL_DEFAULT "\033[m"
# define TEXT_COLOR 0x1A1A1D
# define BACKGROUND 0x1A1A1D
# define MENU_BACKGROUND 0x950740
# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000

// App
# define W_WIDTH 2560
# define W_HEIGHT 1440

// Strucuture for map atributes
typedef struct s_map
{
	int		height;
	int		width;
	int		**depth_matrix;
	int		size;
	int		color_base;
	int		color_transit;
	int		color_top;
	int		x_position;
	int		y_position;
	float	sin_angle;
	float	cos_angle;
	float	sin_z_angle;
	float	cos_z_angle;
	float	depth_scale;
	void	*init;
	void	*win;
	bool	is_3d;
}	t_map;

// Structure for lines atributes
typedef struct s_line
{
	float	x_start;
	float	y_start;
	float	x_end;
	float	y_end;
	float	z_start;
	float	z_end;
	float	x_step;
	float	y_step;
	int		gradient_up;
	int		gradient_down;
}	t_line;

// color.c
void	palette_yellowish(t_map *map);
void	palette_calming(t_map *map);
void	print_current_values(t_map *map);
void	reset_background(t_map *map);

// draw.c
t_line	transform(t_map *map, t_line line);
void	bresenham(t_line line, t_map *map);
void	draw_line(t_line line, t_map *map, int max);
void	draw_base(t_map *map);
t_line	transform2d(t_map *map, t_line line);

// hooks.
void	key_hook(void *parameter);
void	control_hook(t_map *map);
void	other_key_hook(t_map *map);
void	reset_struct(t_map *map);

// read.c
int		get_map_dimensions(char *file_name, t_map *map);
void	allocate_depth_matrix(t_map *map);
void	get_depth(int *depth, char *line);
int		count_words(const char *str);
void	read_map(char *file_name, t_map *map);

// utils.c
float	smooth_interpolate(float current, float target, float speed);
float	absolute(float a);
void	cleanup_map(t_map *map);
float	maxim(float x, float y);
void	error_exit(t_map *map, int flag);

#endif
