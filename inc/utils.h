/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:57:37 by framos-p          #+#    #+#             */
/*   Updated: 2022/12/22 16:50:45 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include <stdio.h>

void 	my_mlx_pixel_put(t_data *data, int x, int y, int color);
//int		gradient(int startcolor, int endcolor, int len, int pix);
int	render_rect(t_meta *meta);
int	terminate_windows(t_meta *param);
int	key_press(int key, t_meta *param);

#endif
