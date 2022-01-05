/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:44:43 by cbridget          #+#    #+#             */
/*   Updated: 2021/10/07 18:53:57 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*result;

	i = 0;
	while (s1[i])
		i ++;
	result = (char *)malloc (sizeof(char) * (i + 1));
	if (!result)
		return ((void *)0);
	i = 0;
	while (s1[i])
	{
		result[i] = s1[i];
		i ++;
	}
	result[i] = s1[i];
	return (result);
}
