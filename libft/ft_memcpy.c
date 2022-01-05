/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 20:18:59 by cbridget          #+#    #+#             */
/*   Updated: 2021/10/13 13:52:53 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dst == ((void *)0) && src == ((void *)0))
		return ((void *)0);
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i ++;
	}
	return (dst);
}
