/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixels.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:53:06 by framos-p          #+#    #+#             */
/*   Updated: 2022/12/22 16:50:45 by framos-p         ###   ########.fr       */
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

int	render_rect(t_meta *meta)
{
	int	x;
	int	y;
	
	x = 0;
	while (x <= 500)
	{
		y = 0;
		while (y <= 500)
		{
			my_mlx_pixel_put(&meta->data, 640+x, 300+y, ROJO);
			y= y+10;
		}
		x++;
	}
	x = 0;
	while (x <= 500)
	{
		y = 0;
		while (y <= 500)
		{
			my_mlx_pixel_put(&meta->data, 640+x, 300+y, AZUL);
			y++;
		}
		x=x+10;
	}
	return (0);
}
