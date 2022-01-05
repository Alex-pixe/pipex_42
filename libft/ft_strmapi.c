/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:27:41 by cbridget          #+#    #+#             */
/*   Updated: 2021/10/13 14:14:43 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*result;

	i = 0;
	if (!s || !f)
		return ((void *)0);
	while (s[i])
		i++;
	result = (char *)malloc(sizeof(char) * (i + 1));
	if (!result)
		return ((void *)0);
	i = -1;
	while (s[++i])
		result[i] = f(i, s[i]);
	result[i] = '\0';
	return (result);
}
