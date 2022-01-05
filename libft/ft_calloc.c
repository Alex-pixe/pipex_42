/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:32:49 by cbridget          #+#    #+#             */
/*   Updated: 2021/10/07 18:41:38 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;
	size_t	i;

	i = 0;
	result = malloc(count * size);
	if (!result)
		return ((void *)0);
	while (i < count * size)
	{
		((unsigned char *)result)[i] = 0;
		i ++;
	}
	return (result);
}
