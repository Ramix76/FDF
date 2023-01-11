/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixels.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:53:06 by framos-p          #+#    #+#             */
/*   Updated: 2023/01/11 15:44:36 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minilibx/minilibx_macos/mlx.h"
#include "../inc/define.h"
#include "../inc/utils.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*pixel;

	pixel = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)pixel = color;
}

int	draw_line(t_meta *meta, t_point start, t_point end)
{
	t_point	alpha;
	t_point	pixel;
	int		pixels;
	int		len;

	alpha.axes[X] = end.axes[X] - start.axes[X];
	alpha.axes[Y] = end.axes[Y] - start.axes[Y];
	pixels = sqrt((alpha.axes[X] * alpha.axes[X]) + \
		   	(alpha.axes[Y] * alpha.axes[Y]));
	len = pixels;
	alpha.axes[X] = alpha.axes[X] - pixels;
	alpha.axes[Y] = alpha.axes[Y] - pixels;
	while (pixels > 0)
	{
		my_mlx_pixel_put(&meta -> data, pixel.axes[X], pixel.axes[Y], start.color);
		pixel.axes[X] = pixel.axes[X] + alpha.axes[X];
		pixel.axes[Y] = pixel.axes[Y] + alpha.axes[Y];
		pixels = pixels - 1;
	}
	return (1);
}

