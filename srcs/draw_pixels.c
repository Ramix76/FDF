/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixels.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:53:06 by framos-p          #+#    #+#             */
/*   Updated: 2023/01/18 16:18:30 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minilibx/minilibx_macos/mlx.h"
#include "../inc/define.h"
#include "../inc/utils.h"

int	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= WINDOW_WIDTH || y >= WINDOW_HEIGHT || x < 0 || y < 0)
		return (-1);
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
	return (0);
}

int	draw_line(t_meta *meta, t_point start, t_point end)
{
	t_point	alpha;
	t_point	pixel;
	float	pixels;
	float	len;

	alpha.axes[X] = end.axes[X] - start.axes[X];
	alpha.axes[Y] = end.axes[Y] - start.axes[Y];
	pixels = sqrt((alpha.axes[X] * alpha.axes[X]) + \
		(alpha.axes[Y] * alpha.axes[Y]));
	len = pixels;
	alpha.axes[X] /= pixels;
	alpha.axes[Y] /= pixels;
	pixel.axes[X] = start.axes[X];
	pixel.axes[Y] = start.axes[Y];
	while (pixels > 0)
	{
		my_mlx_pixel_put(&meta -> data, pixel.axes[X] + WINDOW_WIDTH / 2,
			pixel.axes[Y] + WINDOW_HEIGHT / 2, start.color);
		pixel.axes[X] += alpha.axes[X];
		pixel.axes[Y] += alpha.axes[Y];
		pixels = pixels - 1;
	}
	return (1);
}
