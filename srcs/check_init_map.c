/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_init_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:38:35 by framos-p          #+#    #+#             */
/*   Updated: 2023/01/19 11:32:54 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/define.h"
#include "../lib/LIBFT/inc/libft.h"
#include "../lib/minilibx/minilibx_macos/mlx.h"
#include "../inc/utils.h"
#include "../inc/check_errors.h"

void	map_init(t_meta *meta)
{
	meta -> map.len = 0;
	meta -> map.total = 0;
	meta -> map.limits.axes[X] = 0;
	meta -> map.limits.axes[Y] = 0;
	meta -> map.ang[X] = 0;
	meta -> map.ang[Y] = 0;
	meta -> map.ang[Z] = 0;
	meta -> map.source.axes[X] = WINDOW_WIDTH / 2;
	meta -> map.source.axes[Y] = WINDOW_HEIGHT / 2;
	meta -> map.source.axes[Z] = 0;
	meta -> map.scale = 1;
	meta -> map.divisor = 1;
	meta -> isometric = 1;
}

int	check_line(char **map_line)
{
	int	i;

	i = 0;
	while (map_line[i] && map_line[i][0] != '\n')
		i++;
	if (i == 0 || (i == 1 && map_line[0][0] == '\n'))
		terminate_map(ERR_EMPTY);
	return (i);
}

void	valid_map(char *file_name, t_map *map)
{
	int		fd;
	char	*line;
	char	**splitted;
	int		max;

	fd = open(file_name, O_RDONLY);
	if (fd < 2)
		terminate_map(ERR_NOMAP);
	line = get_next_line(fd);
	while (line != NULL)
	{
		splitted = ft_split(line, ' ');
		max = check_line(splitted);
		if (map -> limits.axes[X] == 0)
			map -> limits.axes[X] = max;
		if (map -> limits.axes[X] != max)
			terminate_map(ERR_MAP);
		free(line);
		double_free(splitted);
		line = get_next_line(fd);
		map -> total += max;
		map -> limits.axes[Y]++;
		write(1, ".", 1);
	}
	close(fd);
}
