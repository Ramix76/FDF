/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mods.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:32:47 by framos-p          #+#    #+#             */
/*   Updated: 2023/01/19 12:14:48 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/define.h"
#include "../inc/utils.h"

void	zoom(t_point *points, int len, float scale)
{
	int	i;

	i = 0;
	while (i < len)
	{
		points[i].axes[X] *= scale;
		points[i].axes[Y] *= scale;
		points[i].axes[Z] *= scale;
		i++;
	}
}

void	rotationX(int len, t_point *points, t_point *proyected)
{
	float	rotation_matrix[3][3];
	float	rad;
	int		ang;
	int		i;

	i = 0;
	ang = 60;
	rad = ang * M_PI / 180;
	matrix_zero(rotation_matrix);
	rotation_matrix [0][0] = 1;
	rotation_matrix [1][1] = cos(rad);
	rotation_matrix [1][2] = -sin(rad);
	rotation_matrix [2][1] = sin(rad);
	rotation_matrix [2][2] = cos(rad);
	while (i < len)
	{
		proyected[i] = matrix_mult(rotation_matrix, points[i]);
		i++;
	}
}

void	rotationY(int len, t_point *points, t_point *proyected)
{
	float	rotation_matrix[3][3];
	float	rad;
	int		ang;
	int		i;

	i = 0;
	ang = 330;
	rad = ang * M_PI / 180;
	matrix_zero(rotation_matrix);
	rotation_matrix [0][0] = cos(rad);
	rotation_matrix [0][2] = sin(rad);
	rotation_matrix [1][1] = 1;
	rotation_matrix [2][0] = -sin(rad);
	rotation_matrix [2][2] = cos(rad);
	while (i < len)
	{
		proyected[i] = matrix_mult(rotation_matrix, points[i]);
		i++;
	}
}

void	rotationZ(int len, t_point *points, t_point *proyected)
{
	float	rotation_matrix[3][3];
	float	rad;
	int		ang;
	int		i;

	i = 0;
	ang = 30;
	rad = ang * M_PI /180;
	matrix_zero(rotation_matrix);
	rotation_matrix [0][0] = cos(rad);
	rotation_matrix [0][1] = -sin(rad);
	rotation_matrix [1][0] = sin(rad);
	rotation_matrix [1][1] = cos(rad);
	rotation_matrix [2][2] = 1;
	while (i < len)
	{
		proyected[i] = matrix_mult(rotation_matrix, points[i]);
		i++;
	}
}

void	reduceZ(int len, t_point *points, float divisor)
{
	int	i;

	i = 0;
	while (i < len)
	{
		points[i].axes[Z] /= divisor;
		i++;
	}
}
