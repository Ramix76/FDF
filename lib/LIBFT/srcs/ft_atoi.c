/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:48:08 by framos-p          #+#    #+#             */
/*   Updated: 2022/06/10 10:29:00 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	resultado;
	int	signo;

	resultado = 0;
	signo = 1;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t' || \
				*str == '\v' || *str == '\f' || *str == '\r'))
		str++;
	if (*str == '-')
	signo = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str && *str >= '0' && *str <= '9')
	{
		resultado = resultado * 10 + (*str - 48);
		++str;
	}
	return (resultado * signo);
}
