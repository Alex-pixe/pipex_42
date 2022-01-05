/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:16:46 by cbridget          #+#    #+#             */
/*   Updated: 2021/10/12 18:16:00 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*put_str(char const *s1, char const *s2, char *result);
static char	*put_str2(char const *s2, char *result, size_t j);

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*result;

	i = 0;
	j = 0;
	if (s1 == ((void *)0) && s2 == ((void *)0))
		return ((void *)0);
	if (s1 != ((void *)0))
		while (s1[i])
			i ++;
	if (s1 != ((void *)0))
		while (s2[j])
			j ++;
	result = (char *)malloc(sizeof(char) * (i + j + 1));
	if (!result)
		return ((void *)0);
	return (put_str(s1, s2, result));
}

static char	*put_str(char const *s1, char const *s2, char *result)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s1 != ((void *)0))
	{
		while (s1[i])
		{
			result[j] = s1[i];
			i ++;
			j ++;
		}
	}
	return (put_str2(s2, result, j));
}

static char	*put_str2(char const *s2, char *result, size_t j)
{
	size_t	i;

	i = 0;
	if (s2 != ((void *)0))
	{
		while (s2[i])
		{
			result[j] = s2[i];
			i ++;
			j ++;
		}
	}
	result[j] = '\0';
	return (result);
}
