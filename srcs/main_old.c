/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 17:40:53 by framos-p          #+#    #+#             */
/*   Updated: 2022/08/01 11:49:35 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minilibx/minilibx_macos/mlx.h"
#include "../inc/define.h"
#include "../inc/draw_utils.h"

int	main()
{
	int 	k;
	int		y;
	int		x;
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	img;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1920, 1080, "mlx 42");
	img.img = mlx_new_image(mlx_ptr, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	k = 1920 + 1080;
	y = 0;
	x = 0;
	while (x < 1920)
	{
		y = 0;
		while (y < 1080)
		{
			my_mlx_pixel_put(&img, x, y, gradient(0x6400, 0xe6e6fa, x , y));
				y++;
		}	
		x++;
	}
	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img, 0, 0);
	mlx_loop(mlx_ptr);
}
