/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 17:15:55 by framos-p          #+#    #+#             */
/*   Updated: 2023/01/13 15:55:30 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minilibx/minilibx_macos/mlx.h"
#include "../inc/define.h"
#include "../inc/keycodes.h"
#include "../inc/utils.h"

int	control_keys1(int key, t_meta *meta)
{
	if (key == KEY_ESC)
		terminate_windows(meta);
	if (key == KEY_SUM)
		meta -> map.scale *= 1.5;
	if (key == KEY_RES)
		meta -> map.scale /= 1.5;
	draw_map(meta);
	return (0);
}

int	key_press(int key, t_meta *param)
{
	control_keys1(key, param);
	printf("keypress: %d\n", key);
	return (0);
}
