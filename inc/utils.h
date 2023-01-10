/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:57:37 by framos-p          #+#    #+#             */
/*   Updated: 2023/01/10 18:17:30 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../inc/define.h"
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <errno.h>
# include <math.h>

int		load_map(char *file_name, t_map *map);
int		gradient(int startcolor, int endcolor, int len, int pix);
int		render_rect(t_meta *meta);
int		terminate_windows(t_meta *param);
int		key_press(int key, t_meta *param);
int		check_line(char **map_line);
int		double_free(char **ptr);
void	terminate_map(char *s);
void	map_init(t_map *map);
void	valid_map(char *file_name, t_map *map);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	save_map_points(t_map *map, int nline, char *line);
void	ft_load_color(t_map *map, char *line);

#endif
