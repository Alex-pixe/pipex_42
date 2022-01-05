/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:05:43 by cbridget          #+#    #+#             */
/*   Updated: 2021/10/13 17:03:44 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	skip(const char *str, int *sign);

int	ft_atoi(const char *str)
{
	size_t			i;
	int				sign;
	unsigned int	result;

	result = 0;
	sign = 1;
	i = skip(str, &sign);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i ++;
		if (result > 2147483650)
			break ;
	}
	if (result > 2147483647 && sign == 1)
		return (-1);
	if (result > 2147483648 && sign == -1)
		return (0);
	return ((int)result * sign);
}

static int	skip(const char *str, int *sign)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i ++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*sign = -1;
		i ++;
	}
	return (i);
}
