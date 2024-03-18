/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:33:07 by mrusu             #+#    #+#             */
/*   Updated: 2024/03/18 17:47:19 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FdF.h"


// int	lin_in(int color_start, int color_end, float step)
// {
// 	t_color	co;

// 	co.r_start = (color_start >> 16) & 0xFF;
// 	co.g_start = (color_start >> 8) & 0xFF;
// 	co.b_start = color_start & 0xFF;
// 	co.a_start = (color_start >> 24) & 0xFF;
// 	co.r_end = (color_end >> 16) & 0xFF;
// 	co.g_end = (color_end >> 8) & 0xFF;
// 	co.b_end = color_end & 0xFF;
// 	co.a_end = (color_end >> 24) & 0xFF;
// 	co.r_res = (int)lerp(co.r_start, co.r_end, step);
// 	co.g_res = (int)lerp(co.g_start, co.g_end, step);
// 	co.b_res = (int)lerp(co.b_start, co.b_end, step);
// 	co.a_res = (int)lerp(co.a_start, co.a_end, step);
// 	return ((co.a_res << 24) | (co.r_res << 16) | (co.g_res << 8) | (co.b_res));
// }

t_draw transform(t_fdf fdf)
{
    t_draw coord;
    t_map *map = fdf.map;

	float temp_x;
	float temp_y;
	float temp_x1;
	float temp_y1;

    temp_x = (coord.x - coord.y) * cos(map->cos);
    temp_y = (coord.x + coord.y) * sin(map->sin) - coord.z;
    temp_x1 = (coord.x1 - coord.y1) * cos(map->cos);
    temp_y1 = (coord.x1 + coord.y1) * sin(map->sin) - coord.z1;
    coord.x = temp_x * cos(map->cosz) - temp_y * sin(map->sinz);
    coord.y = temp_x * sin(map->cosz) - temp_y * cos(map->sinz);
    coord.x1 = temp_x1 * cos(map->cosz) - temp_y1 * sin(map->sinz);
    coord.y1 = temp_x1 * sin(map->cosz) - temp_y1 * cos(map->sinz);
    coord.x += map->x_pos;
    coord.y += map->y_pos;
    coord.x1 += map->x_pos;
    coord.y1 += map->y_pos;
    return coord;
}


void draw_line(t_fdf fdf, int max)
{
    float step;
    float increment = 1.0;
    t_draw coord = *(fdf.draw); // Accessing draw structure from fdf

    // if (!((coord.x > 0 && coord.x <= W_WIDTH) && (coord.x1 > 0 && coord.x1 <= W_WIDTH)
    //       && (coord.y > 0 && coord.y <= W_HEIGHT) && (coord.y1 > 0 && coord.y1 <= W_HEIGHT)))
    //     return;
	if (coord.x <= 0 || coord.x > W_WIDTH || coord.x1 <= 0 || coord.x1 > W_WIDTH
    	|| coord.y <= 0 || coord.y > W_HEIGHT || coord.y1 <= 0 || coord.y1 > W_HEIGHT)
    	return;
    // while ((int)(coord.x - coord.x1) || (int)(coord.y - coord.y1))
    // {
    //     step = increment++ / max;
    //     if (coord.z == 0 && coord.z1 != 0)
    //         coord.gradient_up = lin_in(fdf.map->co_bu, fdf.map->co_to, step);
    //     if (coord.z == 0 && coord.z1 != 0)
    //         mlx_put_pixel(fdf.mlx_windows, coord.x, coord.y, coord.gradient_up);
    //     if (coord.z != 0 && coord.z1 == 0)
    //         coord.gradient_do = lin_in(fdf.map->co_to, fdf.map->co_bu, step);
    //     if (coord.z != 0 && coord.z1 == 0)
    //         mlx_put_pixel(fdf.mlx_windows, coord.x, coord.y, coord.gradient_do);
    //     if (coord.z != 0 && coord.z1 != 0)
    //         mlx_put_pixel(fdf.mlx_windows, coord.x, coord.y, fdf.map->co_to);
    //     if (coord.z == 0 && coord.z1 == 0)
    //         mlx_put_pixel(fdf.mlx_windows, coord.x, coord.y, fdf.map->color_grind);
    //     coord.x += coord.x_step;
    //     coord.y += coord.y_step;
	while ((int)(coord.x - coord.x1) || (int)(coord.y - coord.y1))
    {
        float step = step++ / max;

        if (coord.z == 0 && coord.z1 != 0)
            mlx_put_pixel(fdf.mlx_windows, coord.x, coord.y, lin_in(fdf.map->co_bu, fdf.map->co_to, step));
        else if (coord.z != 0 && coord.z1 == 0)
            mlx_put_pixel(fdf.mlx_windows, coord.x, coord.y, lin_in(fdf.map->co_to, fdf.map->co_bu, step));
        else if (coord.z != 0 && coord.z1 != 0)
            mlx_put_pixel(fdf.mlx_windows, coord.x, coord.y, fdf.map->co_to);
        else if (coord.z == 0 && coord.z1 == 0)
            mlx_put_pixel(fdf.mlx_windows, coord.x, coord.y, fdf.map->color_grid);

        coord.x += coord.x_step;
        coord.y += coord.y_step;
    }
}

void bresenham(t_fdf *fdf)
{
    t_draw *draw = fdf->draw; // Accessing the draw field from the fdf structure

    draw->z = fdf->map->depth[(int)draw->y][(int)draw->x];
    draw->z1 = fdf->map->depth[(int)draw->y1][(int)draw->x1];
    draw->z *= fdf->map->size * fdf->map->depth;
    draw->z1 *= fdf->map->size * fdf->map->depth;
    draw->x *= fdf->map->size;
    draw->y *= fdf->map->size;
    draw->x1 *= fdf->map->size;
    draw->y1 *= fdf->map->size;
    *draw = perspective(*draw, fdf->map);
    draw->x_step = draw->x1 - draw->x;
    draw->y_step = draw->y1 - draw->y;
    int max = faster(absolute(draw->x_step), absolute(draw->y_step));
    draw->x_step /= max;
    draw->y_step /= max;
    draw_line(*fdf, max); // Pass fdf as a pointer
}

void draw_grid(t_fdf *fdf)
{
    t_draw coo;

    coo.y = 0;
    while (coo.y < fdf->map->height)
    {
        coo.x = 0;
        while (coo.x < fdf->map->width)
        {
            if (coo.x < fdf->map->width - 1)
            {
                coo.x1 = coo.x + 1;
                coo.y1 = coo.y;
                bresenham(fdf);
            }
            if (coo.y < fdf->map->height - 1)
            {
                coo.x1 = coo.x;
                coo.y1 = coo.y + 1;
                bresenham(fdf);
            }
            coo.x++;
        }
        coo.y++;
    }
}
