/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 17:40:53 by framos-p          #+#    #+#             */
/*   Updated: 2023/01/10 18:17:43 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minilibx/minilibx_macos/mlx.h"
#include "../inc/define.h"
#include "../inc/utils.h"

int	main()
{
	t_meta	meta;

	meta.vars.mlx_ptr = mlx_init();
	meta.vars.win_ptr = mlx_new_window(meta.vars.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "FDF 42");
	meta.data.img = mlx_new_image(meta.vars.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	meta.data.addr = mlx_get_data_addr(meta.data.img, &meta.data.bits_per_pixel, &meta.data.line_length, &meta.data.endian);
	render_rect(&meta);
	mlx_put_image_to_window(meta.vars.mlx_ptr, meta.vars.win_ptr, meta.data.img, 0, 0);
	mlx_hook(meta.vars.win_ptr, 2, 0, key_press, &meta);
	mlx_hook(meta.vars.win_ptr, 17, 0, terminate_windows, &meta);
	mlx_loop(meta.vars.mlx_ptr);
}
