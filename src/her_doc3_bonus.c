/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   her_doc3_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 19:36:18 by cbridget          #+#    #+#             */
/*   Updated: 2022/01/22 20:14:17 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "libft.h"

int	ch_hdoc(int argc, char **argv)
{
	char	*str;
	int		i;

	i = 0;
	str = "here_doc";
	if (argc != 6)
		return (0);
	while (argv[1][i] == str[i])
		i++;
	if (i == 9)
		return (1);
	else
		return (0);
}
