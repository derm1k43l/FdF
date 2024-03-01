/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:04:40 by mrusu             #+#    #+#             */
/*   Updated: 2024/03/01 17:55:22 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FdF.h"

// int	main(int ac, char **av)
// {
// 	void *mlx_dis; //disply
// 	void *mlx_win;
// 	t_data image;

// 	mlx_dis = mlx_init(); //display init
// 	mlx_win = mlx_new_window(mlx, W_WIDTH, W_HEIGHT, "FdF by mrusu"); // window init
// 	image.img = mlx_new_image(mlx, W_WIDTH, W_HEIGHT) //image init

	
// 	if (ac == 2)
// 	{
// 		app =
// 		fd =
// 		if(fd < 0)
// 			return (close app())
// 		else
// 		{
// 			if (app init)
// 			{
// 				loop app
// 				return (close app())
// 			}
// 			else
// 				return(close app())
// 		}
// 	}
// 	ft_print("Usage: ./fdf map file") ; // mawyb special eror print that also ahve a flag adn cleans omting wehn is true
// 	return (1);
// }

int	main(int ac, char **av)
{
	t_map *data;
	(void)ac;
	
	data = (t_map*)malloc(sizeof(t_map));
	read_map(av[1], data);

	int	i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			ft_printf("%3d", data->depth[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
	return 0;
}