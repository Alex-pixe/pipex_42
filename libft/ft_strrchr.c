/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 21:18:04 by cbridget          #+#    #+#             */
/*   Updated: 2021/10/13 16:04:16 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	res;

	i = 0;
	res = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			res = i;
		i ++;
	}
	if (c > 255)
		return ((char *)s);
	if (s[i] == '\0' && (char)c == '\0')
		return ((char *)(s + i));
	else if (res == 0 && s[res] == (char)c)
		return ((char *)s);
	else if (res > 0 && i > 0)
		return ((char *)(s + res));
	return ((void *)0);
}
