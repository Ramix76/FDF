/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 10:10:47 by framos-p          #+#    #+#             */
/*   Updated: 2022/12/21 12:16:33 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static char	*join_protect(char *s1)
{
	s1 = malloc(sizeof(char) * 1);
	if (!s1)
		return (NULL);
	s1[0] = '\0';
	return (s1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	size_t	count;

	if (!s1)
		s1 = join_protect(s1);
	new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return (NULL);
	count = 0;
	while (s1[count] != '\0')
	{
		new[count] = s1[count];
		count++;
	}
	count = 0;
	while (s2[count] != '\0')
	{
		new[count + ft_strlen(s1)] = s2[count];
		count++;
	}
	new[count + ft_strlen(s1)] = '\0';
	free(s1);
	return (new);
}
