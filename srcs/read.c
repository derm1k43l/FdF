/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:32:52 by mrusu             #+#    #+#             */
/*   Updated: 2024/03/01 17:52:54 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FdF.h"

int	get_height(char *file_name)
{
	int		height;
	int		fd;
	char	*line;

	height = 0;
	fd = open(file_name, O_RDONLY, 0);
	while(get_next_line(fd))
	{
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

int	get_width(char *file_name)
{
	int		width;
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY, 0);
	get_next_line(fd);
	width = ft_split(line, ' ');
	free(line);
	close(fd);
	return (width);
}

void fill_matrix(int *depth, char *line)
{
	char	**values;
	int		i;

	values  = ft_split(line, ' ');
	i = 0;
	while(values[i])
	{
		depth[i] = ft_atoi(values[i]);
		free(values[i]);
		i++;
	}
	free(values);
}

void	read_map(char *file_name, t_map *data)
{
	int fd;
	char *line;
	int i;
	
	data->height = get_height(file_name);
	data->width = get_height(file_name);
	data->depth = (int **)malloc(sizeof(int *) * (data->height + 1));
	i = 0;
	while (i <= data->height)
		data->depth[i++] = (int *)malloc(sizeof(int) * (data->width + 1));
	fd = open(file_name, O_RDONLY, 0);
	i = 0;
	while (get_next_line(fd))
	{
		fill_matrix(data->depth[i], line);
		free(line);
		i++;
	}
	close(fd);
	data->depth[i] = NULL;
}
