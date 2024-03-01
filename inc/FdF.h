/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:14:31 by mrusu             #+#    #+#             */
/*   Updated: 2024/03/01 17:52:31 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

//Standart
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/types.h>
# include <fcntl.h>
# include <stdbool.h>
# include <limits.h>
# include <math.h>
# include <errno.h>

//Extra
# include "../libft/inc/libft.h"
# include "../mlx42/include/MLX42/MLX42.h"

//Colors
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

//App
# define W_WIDTH 1500
# define W_HEIGHT 1100

typedef struct s_map
{
	int	width;
	int	height;
	int	**depth;
}	t_map;

// Read
int		get_height(char *file_name);
int		get_width(char *file_name);
void	fill_matrix(int *depth, char *line);
void	read_map(char *file_name, t_map *data);

#endif
