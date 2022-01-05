/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:46:12 by cbridget          #+#    #+#             */
/*   Updated: 2021/10/13 15:56:48 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	tmp;

	i = 0;
	tmp = dstsize;
	if (dstsize > 0)
		dstsize --;
	while (src[i])
	{
		if (i < dstsize)
			dst[i] = src[i];
		else if (i == dstsize && dstsize != 0)
			dst[i] = '\0';
		i ++;
	}
	if (i <= dstsize && dstsize != 0)
		dst[i] = '\0';
	else if (tmp == 1)
		dst[0] = '\0';
	return (i);
}
