/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:11:08 by framos-p          #+#    #+#             */
/*   Updated: 2023/01/09 14:48:30 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/define.h"
#include "../lib/LIBFT/inc/libft.h"
#include "../lib/minilibx/minilibx_macos/mlx.h"
#include "../inc/utils.h"
#include "../inc/check_errors.h"

void	terminate_map(char *s)
{
	if (errno == 0)
		ft_putendl_fd(s, 2);
	else
		perror(s);
	exit(1);
}

int	double_free(char **ptr)
{
	int	i;

	if (!ptr)
		return ;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

int	terminate_windows(t_meta *param)
{
	if (param->data.img)
		mlx_destroy_image(param->vars.mlx_ptr, param->data.img);
	mlx_destroy_window(param->vars.mlx_ptr, param->vars.win_ptr);
	exit(0);
	return (0);
}
