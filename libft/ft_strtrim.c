/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:05:38 by cbridget          #+#    #+#             */
/*   Updated: 2021/10/11 15:51:54 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check(char const *s1, char const *set, int *mod, int i);
static int		check2(char const *s1, char const *set, int *mod, int i);
static char		*put_res1(char const *s1, char const *set, char *result);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	size;
	char	*result;
	int		mod;

	i = -1;
	size = 0;
	mod = 1;
	if (s1 == ((void *)0) || set == ((void *)0))
		return ((void *)0);
	while (s1[++i])
	{
		if (mod && check(s1, set, &mod, i))
			mod = 0;
		if (!mod && check(s1, set, &mod, i))
			size ++;
	}
	result = (char *)malloc(sizeof(char) * (size + 1));
	if (!result)
		return ((void *)0);
	return (put_res1(s1, set, result));
}

static int	check(char const *s1, char const *set, int *mod, int i)
{
	size_t	j;

	j = -1;
	if (*mod)
	{
		while (set[++j])
		{
			if (set[j] == s1[i])
				return (0);
		}
		return (1);
	}
	else
	{
		if (check2(s1, set, mod, i))
			return (1);
		else
			return (0);
	}
}

static int	check2(char const *s1, char const *set, int *mod, int i)
{
	size_t	length_s;
	size_t	con;
	size_t	j;

	j = i - 1;
	length_s = -1;
	con = -1;
	while (set[++length_s])
		;
	while (s1[++j])
	{
		while (set[++con] && s1[j] != set[con])
			;
		if (length_s == con)
			return (1);
		con = -1;
	}
	*mod = 1;
	return (0);
}

static char	*put_res1(char const *s1, char const *set, char *result)
{
	size_t	i;
	size_t	size;
	int		mod;

	i = -1;
	size = -1;
	mod = 1;
	while (s1[++i])
	{
		if (mod && check(s1, set, &mod, i))
			mod = 0;
		if (!mod && check(s1, set, &mod, i))
			result[++size] = s1[i];
	}
	result[++size] = '\0';
	return (result);
}
