/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixels.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:53:06 by framos-p          #+#    #+#             */
/*   Updated: 2023/01/11 19:56:17 by framos-p         ###   ########.fr       */
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
	int		pixels;
	int		len;

	alpha.axes[X] = end.axes[X] - start.axes[X];
	alpha.axes[Y] = end.axes[Y] - start.axes[Y];
	pixels = sqrt((alpha.axes[X] * alpha.axes[X]) + \
		(alpha.axes[Y] * alpha.axes[Y]));
	len = pixels;
	alpha.axes[X] /= pixels;
	alpha.axes[Y] /= pixels;
	while (pixels > 0)
	{
		my_mlx_pixel_put(&meta -> data, pixel.axes[X], \
				pixel.axes[Y], start.color);
		pixel.axes[X] += alpha.axes[X];
		pixel.axes[Y] += alpha.axes[Y];
		pixels = pixels - 1;
	}
	return (1);
}
