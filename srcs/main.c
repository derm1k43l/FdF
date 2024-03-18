/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:04:40 by mrusu             #+#    #+#             */
/*   Updated: 2024/03/18 16:31:03 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FdF.h"

//-----pseudo code-----
// 1. read file
// 	- get height
// 	- get width
// 	- allocate memory for **int by using witht and height (with ft_split)
// 	- read file and write number into **int matrix with split ando atoi
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
	t_fdf *fdf; //out struc for map has also the pointer for display and windows

	if (ac != 2)
		generic_error();
	fdf = (t_fdf*)malloc(sizeof(t_fdf));
	read_map(av[1], fdf->map);
	fdf->map->zoom = 20;
	draw(fdf);
//	mlx_key_hook(data->mlx_dis, deal_key, NULL);
	mlx_loop(data->mlx_win);
}

// int main(int ac, char **av) //testign mapr read main
// {
// 	t_map *data;

// 	data = (t_map*)malloc(sizeof(t_map));
// 	read_map(av[1], data);
	
// 	(void)ac;
// 	int i;
// 	int j;
	
//     // Iterate over rows
//     for (i = 0; i < data->height && i < 10; i++) {
//         // Iterate over columns
//         for (j = 0; j < data->width && j < 20; j++) {
//             printf("%3d ", data->depth[i][j]);
//         }
//         printf("\n");
// 	}
// }
