/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:10:47 by framos-p          #+#    #+#             */
/*   Updated: 2023/01/11 18:51:06 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/define.h"
#include "../inc/utils.h"
#include "../lib/minilibx/minilibx_macos/mlx.h"
#include "../lib/LIBFT/inc/libft.h"

void	draw_map_lines(t_meta *meta, int len, t_map *map, t_point *proyected)
{
	int	i;

	i = 0;
	while (i < len -1)
	{
		if (i >= len - (int)map -> limits.axes[X])
			draw_line(meta, proyected[i], proyected[i + 1]);
		else if (i == 0 || (i + 1) % (int)map -> limits.axes[X] != 0)
		{
			draw_line(meta, proyected[i], proyected[i + 1]);
			draw_line(meta, proyected[i], proyected[i + \
					(int)map -> limits.axes[X]]);
		}
		else
			draw_line(meta, proyected[i], proyected[i + \
					(int)map -> limits.axes[X]]);
		i++;
	}
}

void	copy_map_points(t_point *source, t_point *dest, int total)
{
	int	i;

	i = 0;
	while (i < total)
	{
		dest[i] = source[i];
		i++;
	}
}

void	black_background(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j <= WINDOW_HEIGHT)
	{
		i = 0;
		while (i <= WINDOW_WIDTH)
		{
			my_mlx_pixel_put(data, i, j, BLACK);
			i++;
		}
		j++;
	}
}

void	draw_map(t_meta *meta)
{
	t_point	*copy;

	copy = malloc(sizeof(t_point) * meta -> map.total);
	black_background(&meta -> data);
	copy_map_points(meta -> map.points, copy, meta -> map.total);
	draw_map_lines(meta, meta -> map.total, &meta -> map, copy);
	free(copy);
	mlx_put_image_to_window(meta -> vars.mlx_ptr, \
			meta -> vars.win_ptr, meta -> data.img, 0, 0);
}
