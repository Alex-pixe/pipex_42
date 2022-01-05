/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 13:15:02 by cbridget          #+#    #+#             */
/*   Updated: 2021/10/07 14:05:19 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if ((unsigned char)s1[i] > (unsigned char)s2[i])
			return ((unsigned char)s1[i]);
		else if ((unsigned char)s1[i] < (unsigned char)s2[i])
			return (-1);
		if (!s1[i] || !s2[i])
			break ;
		i ++;
	}
	return (0);
}
