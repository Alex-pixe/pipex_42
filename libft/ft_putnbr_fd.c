/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student-21school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 18:31:16 by cbridget          #+#    #+#             */
/*   Updated: 2022/01/24 21:11:36 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	check_s(long long number, size_t *discharge);

void	ft_putnbr_fd(int n, int fd)
{
	long long	number;
	size_t		discharge;
	char		res;

	number = n;
	discharge = 1;
	check_s(number, &discharge);
	if (n < 0)
	{
		write(fd, "-", 1);
		number *= -1;
	}
	while (discharge > 0)
	{
		res = (number / discharge) + '0';
		write(fd, &res, 1);
		number %= discharge;
		discharge /= 10;
	}
}

static void	check_s(long long number, size_t *discharge)
{
	if (number < 0)
	{
		number *= -1;
	}
	while (number > 9)
	{
		*discharge *= 10;
		number /= 10;
	}
}
