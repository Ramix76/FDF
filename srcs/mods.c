/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mods.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:32:47 by framos-p          #+#    #+#             */
/*   Updated: 2023/01/13 15:45:26 by framos-p         ###   ########.fr       */
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
