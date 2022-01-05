/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:25:05 by cbridget          #+#    #+#             */
/*   Updated: 2021/10/13 16:16:24 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!needle[j])
		return ((char *)haystack);
	while (i < len && *haystack)
	{
		while (haystack[j] == needle[j] && haystack[j] && needle[j]
			&& (i + j) < len)
			j ++;
		if (!needle[j])
			return ((char *)haystack);
		haystack++;
		j = 0;
		i ++;
	}
	return ((void *)0);
}
