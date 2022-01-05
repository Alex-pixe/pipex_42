/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 19:04:40 by cbridget          #+#    #+#             */
/*   Updated: 2021/10/13 14:35:46 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*put_res(unsigned int start, char const *s, size_t len,
				char *result);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			j;
	char			*result;
	int				mod;

	if (s == ((void *)0))
		return ((void *)0);
	mod = 1;
	i = ft_strlen(s);
	if (i < start)
		mod = 0;
	i = start;
	j = 0;
	while (j < len && s[i] && mod)
	{
		i++;
		j++;
	}
	result = (char *)malloc (sizeof(char) * (j + 1));
	if (!result)
		return ((void *)0);
	return (put_res(start, s, len, result));
}

static char	*put_res(unsigned int start, char const *s, size_t len,
	char *result)
{
	unsigned int	i;
	size_t			j;
	int				mod;

	mod = 1;
	i = ft_strlen(s);
	if (i < start)
		mod = 0;
	i = start;
	j = 0;
	while (j < len && s[i] && mod)
	{
		result[j] = s[i];
		j++;
		i++;
	}
	result[j] = '\0';
	return (result);
}
