/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:36:10 by framos-p          #+#    #+#             */
/*   Updated: 2023/01/11 16:13:46 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/define.h"
#include "../lib/LIBFT/inc/libft.h"
#include "../lib/minilibx/minilibx_macos/mlx.h"
#include "../inc/utils.h"
#include "../inc/check_errors.h"

void	ft_load_color(t_map *map, char *line)
{
	char **color;

	if (ft_strchr(line, ','))
	{
		color = ft_split(line, ',');
		map -> points[map -> len].color = (long)strtol(color[1] + 2, NULL, 16);
		double_free(color);
	}
	else
		map -> points[map -> len].color = 0xFF00FF;
}

void	save_map_points(t_map *map, int nline, char *line)
{
	int		i;
	char	**splitted;

	i = 0;
	splitted = ft_split(line, ' ');
	while (splitted[i] && splitted[i][0] != '\n')
	{
		map -> points[map -> len].axes[X] = i - (map -> limits.axes[X]);
		map -> points[map -> len].axes[Y] = nline - (map -> limits.axes[Y]);
		if (!ft_isdigit(splitted[1][0]) && splitted[i][0] != '-')
			terminate_map(ERR_MAP);
		map -> points[map -> len].axes[Z] = ft_atoi(splitted[i]);
		ft_load_color(map, splitted[i]);
		i++;
		map -> len++;
	}
	double_free(splitted);
}

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
		write(1, "*", 1);
	}
	return (1);
}
