/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:18:20 by cbridget          #+#    #+#             */
/*   Updated: 2021/10/11 17:19:39 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**clear_res(char **result, size_t j);
static char	**put_result(char **result, char const *s, char c, size_t i);
static char	**create_res(char const *s, char c, size_t size, size_t i);

char	**ft_split(char const *s, char c)
{
	size_t	size;
	size_t	i;
	size_t	j;

	size = 0;
	i = -1;
	j = 0;
	if (s == ((void *)0))
		return ((void *)0);
	while (s[++i])
	{
		if (s[i] == c && j)
		{
			size++;
			j = 0;
		}
		if (s[i] != c)
			j++;
	}
	if (j)
		size++;
	i = -1;
	return (create_res(s, c, size, i));
}

static char	**put_result(char **result, char const *s, char c, size_t i)
{
	size_t	j;
	size_t	size;

	j = 0;
	size = -1;
	i = -1;
	while (s[++i])
	{
		if (s[i] == c && size != (size_t) - 1)
		{
			result[j][++size] = '\0';
			j ++;
			size = -1;
		}
		else if (s[i] != c)
			result[j][++size] = s[i];
	}
	if (result[j])
		result[j][++size] = '\0';
	return (result);
}

static char	**create_res(char const *s, char c, size_t size, size_t i)
{
	size_t	j;
	char	**result;

	j = 0;
	result = (char **)malloc(sizeof(char *) * (size + 1));
	if (!result)
		return ((void *)0);
	size = 0;
	while (s[++i] || size)
	{
		if (s[i] != c)
			size++;
		if ((s[i] == c && size > 0) || !s[i])
		{
			result[j] = (char *)malloc(sizeof(char) * (size + 1));
			if (!result[j])
				return (clear_res(result, j));
			size = 0;
			j++;
			if (!s[i])
				break ;
		}
	}
	result[j] = (void *)0;
	return (put_result(result, s, c, i));
}

static char	**clear_res(char **result, size_t j)
{
	size_t	i;

	i = 0;
	while (i < j)
	{
		free(result[i]);
		i ++;
	}
	free(result);
	return ((void *)0);
}
