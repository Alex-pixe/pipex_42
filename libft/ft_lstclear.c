/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 21:17:11 by cbridget          #+#    #+#             */
/*   Updated: 2021/10/13 14:37:58 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		del((*lst)->content);
		if ((*lst)->next)
		{
			tmp = (*lst)->next;
			free(*lst);
			*lst = tmp;
		}
		else
		{
			free(*lst);
			*lst = ((void *)0);
		}
	}
}
