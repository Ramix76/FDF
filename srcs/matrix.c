/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:07:03 by framos-p          #+#    #+#             */
/*   Updated: 2023/01/18 16:17:36 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

void	matrix_zero(float matrix[3][3])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			matrix[i][j] = 0;
			j++;
		}
		i++;
	}
}

t_point	matrix_mult(float matrix[3][3], t_point points)
{
	t_point	result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < 3)
	{
		result.axes[i] = 0;
		j = 0;
		while (j < 3)
		{
			result.axes[i] += matrix[i][j] * points.axes[j];
			j++;
		}
		i++;
	}
	result.color = points.color;
	return (result);
}
