/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:32:52 by mrusu             #+#    #+#             */
/*   Updated: 2024/03/12 11:51:51 by mrusu            ###   ########.fr       */
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
	if (fd == -1)
		return -1;
	while ((line = get_next_line(fd)) != NULL)
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
	line = get_next_line(fd);
	width = count_words(line);
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
	
    if (file_name == NULL || data == NULL)
        generic_error();
	fd = open(file_name, O_RDONLY, 0);
    if (fd == -1)
        generic_error();
	data->height = get_height(file_name);
	data->width = get_width(file_name);
	data->depth = (int **)malloc(sizeof(int *) * (data->height + 1));
	i = 0;
	while (i <= data->height)
		data->depth[i++] = (int *)malloc(sizeof(int) * (data->width + 1));
	i = 0;
	while((line = get_next_line(fd)) != NULL)
	{
		fill_matrix(data->depth[i], line);
		free(line);
		i++;
	}
	close(fd); // maywb check here for rox not = with coloms
	data->depth[i] = NULL;
}

int count_words(const char *str)
{
    int word_count = 0;
    int in_word = 0;

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
    return word_count;
}
