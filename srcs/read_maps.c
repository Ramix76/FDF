/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:36:10 by framos-p          #+#    #+#             */
/*   Updated: 2023/01/09 15:30:27 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/define.h"
#include "../lib/LIBFT/inc/libft.h"
#include "../lib/minilibx/minilibx_macos/mlx.h"
#include "../inc/utils.h"
#include "../inc/check_errors.h"

int	load_map(char *file_name, t_map *map)
{
	int		nline;
	int		fd;
	char	*line;

	nline = 0;
	map_init(map);
	valid_map(file_name, map);
	map -> points = ft_calloc(map -> total, sizeof(t_point));
	if (map -> limits.axes[X] == 0)
		terminate_map(ERR_EMPTY);
	fd = open(file_name, O_RDONLY);
	if (fd < 3 || map -> points == NULL)
		return (0);
	line = get_next_line(fd);
	while (line != NULL)
	{
		save_map_points(map, nline, line);
		nline++;
		free(line);
		line = get_next_line(fd);
		write(1, '.', 1);
	}
	return (1);
}
