/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:20:03 by cbridget          #+#    #+#             */
/*   Updated: 2021/10/13 14:04:10 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i] && i < dstsize)
		i++;
	if (dstsize > 0)
		dstsize--;
	while (src[j])
	{
		if (i < dstsize)
			dst[i] = src[j];
		else if (i == dstsize && dstsize != 0)
			dst[i] = '\0';
		i++;
		j++;
	}
	if (i <= dstsize && dstsize != 0)
		dst[i] = '\0';
	return (i);
}
