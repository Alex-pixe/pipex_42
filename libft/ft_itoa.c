/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 14:10:50 by cbridget          #+#    #+#             */
/*   Updated: 2021/10/11 15:46:23 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	check_size(long long number, size_t *discharge);

char	*ft_itoa(int n)
{
	long long	number;
	size_t		discharge;
	size_t		i;
	char		*result;

	number = n;
	discharge = 1;
	i = check_size(number, &discharge);
	result = (char *)malloc(sizeof(char) * (i + 1));
	if (!result)
		return ((void *)0);
	i = -1;
	if (n < 0)
	{
		result[++i] = '-';
		number *= -1;
	}
	while (discharge > 0)
	{
		result[++i] = (number / discharge) + '0';
		number %= discharge;
		discharge /= 10;
	}
	result[++i] = '\0';
	return (result);
}

static size_t	check_size(long long number, size_t *discharge)
{
	size_t	i;

	i = 0;
	if (number < 0)
	{
		number *= -1;
		i += 1;
	}
	if (number < 10)
		i += 1;
	else
	{
		while (number > 9)
		{
			*discharge *= 10;
			number /= 10;
			i += 1;
		}
		i += 1;
	}
	return (i);
}
