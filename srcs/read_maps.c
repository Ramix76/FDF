/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:36:10 by framos-p          #+#    #+#             */
/*   Updated: 2023/01/19 11:31:16 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/define.h"
#include "../lib/LIBFT/inc/libft.h"
#include "../lib/minilibx/minilibx_macos/mlx.h"
#include "../inc/utils.h"
#include "../inc/check_errors.h"

void	ft_load_color(t_map *map, char *line)
{
	char	**color;

	if (ft_strchr(line, ',') != 0)
	{
		color = ft_split(line, ',');
		map -> points[map -> len].color = (long)strtol(color[1] + 2, NULL, 16);
		double_free(color);
	}
	else
		map -> points[map -> len].color = WHITE;
}

void	save_map_points(t_map *map, int nline, char *line)
{
	int		i;
	char	**splitted;

	i = 0;
	splitted = ft_split(line, ' ');
	while (splitted[i] && splitted[i][0] != '\n')
	{
		map -> points[map -> len].axes[X] = i - map -> limits.axes[X] / 2;
		map -> points[map -> len].axes[Y] = nline - map -> limits.axes[Y] / 2;
		if (!ft_isdigit(splitted[i][0]) && splitted[i][0] != '-')
			terminate_map(ERR_MAP);
		map -> points[map -> len].axes[Z] = ft_atoi(splitted[i]);
		ft_load_color(map, splitted[i]);
		i++;
		map -> len++;
	}
	double_free(splitted);
}

int	load_map(char *file_name, t_meta *meta)
{
	int		nline;
	int		fd;
	char	*line;

	nline = 0;
	map_init(meta);
	valid_map(file_name, &meta -> map);
	meta -> map.points = ft_calloc(meta -> map.total, sizeof(t_point));
	if (meta -> map.limits.axes[X] == 0)
		terminate_map(ERR_EMPTY);
	fd = open(file_name, O_RDONLY);
	if (fd < 2 || meta -> map.points == NULL)
		return (0);
	line = get_next_line(fd);
	while (line != NULL)
	{
		save_map_points(&meta -> map, nline, line);
		nline++;
		free(line);
		line = get_next_line(fd);
		write(1, "*", 1);
	}
	return (1);
}
