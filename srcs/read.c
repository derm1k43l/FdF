/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:32:52 by mrusu             #+#    #+#             */
/*   Updated: 2024/04/09 15:54:59 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FdF.h"

int	get_map_dimensions(char *file_name, t_map *map)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(file_name, O_RDONLY, 0);
	if (fd == -1)
		exit(1);
	height = 0;
	line = get_next_line(fd);
	if (line == NULL)
		error_exit(map, -1);
	map->width = count_words(line);
	free(line);
	fd = open(file_name, O_RDONLY, 0);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		free(line);
		height++;
	}
	close(fd);
	map->height = height;
	return (1);
}

void	allocate_depth_matrix(t_map *map)
{
	int	i;

	i = 0;
	map->depth_matrix = (int **)malloc(sizeof(int *) * (map->height + 1));
	if (map->depth_matrix == NULL)
		exit(1);
	while (i < map->height)
	{
		map->depth_matrix[i] = NULL;
		i++;
	}
	i = 0;
	while (i < map->height)
	{
		map->depth_matrix[i] = (int *)malloc(sizeof(int) * map->width);
		if (map->depth_matrix[i] == NULL)
			error_exit(map, 2);
		i++;
	}
	map->depth_matrix[i] = NULL;
}

void	get_depth(int *depth, char *line)
{
	char	**values;
	int		i;

	values = ft_split(line, ' ');
	if (!values)
		return ;
	i = 0;
	while (values[i] != NULL)
	{
		if (depth != NULL)
			depth[i] = ft_atoi(values[i]);
		free(values[i]);
		i++;
	}
	free(values);
}

int	count_words(const char *str)
{
	int	word_count;
	int	in_word;

	in_word = 0;
	word_count = 0;
	while (*str != '\0')
	{
		if (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r')
		{
			in_word = 0;
		}
		else if (!in_word)
		{
			in_word = 1;
			word_count++;
		}
		str++;
	}
	return (word_count);
}

void	read_map(char *file_name, t_map *map)
{
	int		fd;
	int		i;
	char	*line;

	if (!get_map_dimensions(file_name, map))
		exit(1);
	fd = open(file_name, O_RDONLY, 0);
	if (fd == -1)
		error_exit(map, 1);
	allocate_depth_matrix(map);
	if (map->depth_matrix == NULL)
		error_exit(map, 1);
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		get_depth(map->depth_matrix[i], line);
		free(line);
		i++;
		line = get_next_line(fd);
	}
	close(fd);
}
