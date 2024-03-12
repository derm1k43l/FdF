/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:04:40 by mrusu             #+#    #+#             */
/*   Updated: 2024/03/12 10:56:51 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FdF.h"

//-----pseudo code-----
// 1. read file
// 	- get height
// 	- get width
// 	- allocate memory for **int by using witht and height (with ft_spli)
// 	- read file and write number into **int matrix with split ando atoi
// -----------------------
// 2. drawing line (bresenham alg)
// 3. function which draws lines beetwen evey dot
// 4. make 3d ish
// 5. adding futures
// 6. error
// 7. leaks and chack

int deal_key(int key, void *data)
{
	ft_printf("%d\n", key);
	return (0);
	(void)data;
}
int	main(int ac, char **av)
{
	t_map *data; //out struc for map has also the pointer for display and windows
	(void)ac;
	
	data = (t_map*)malloc(sizeof(t_map));
	read_map(av[1], data);
	data->zoom = 20;
	draw(data);
//	mlx_key_hook(data->mlx_dis, deal_key, NULL);
	mlx_loop(data->mlx_win);
}


void struct_init(t_map *data)
{
	data->mlx_dis = mlx_init(W_WIDTH, W_HEIGHT, "FdF by mrusu", true);
	data->mlx_win = mlx_new_image(data->init, W_WIDTH, W_HEIGHT);
}



/*
int main(int ac, char **av)
{
	t_map *data;
	
	if (ac == 2) // i dont think we need to check av since we do it in read map
	{
		here all
	}
	ft_usage??
	return (0);
}
*/