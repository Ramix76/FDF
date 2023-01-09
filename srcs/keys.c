/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 17:15:55 by framos-p          #+#    #+#             */
/*   Updated: 2022/12/23 15:08:30 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minilibx/minilibx_macos/mlx.h"
#include "../inc/define.h"
#include "../inc/keycodes.h"
#include "../inc/utils.h"

static void	control_keys1(int key, t_meta *meta)
{
	if (key == KEY_ESC)
		terminate_windows(meta);
}

int	key_press(int key, t_meta *param)
{
	control_keys1(key, param);
	printf(" keypress: %d\n",key);
	return (0);
}
