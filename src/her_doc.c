/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   her_doc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:26:08 by cbridget          #+#    #+#             */
/*   Updated: 2022/01/20 17:04:54 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "libft.h"

int	ch_hdoc(char **argv)
{
	char	*str;
	int		i;

	i = 0;
	str = "here_doc";
	while (argv[1][i] == str[i])
		i++;
	if (i == 8)
		return (1);
	else
		return (0);
}

int	pr_hdoc(char **argv, char **envp, char **cmar)
{
	if (!access(argv[1], F_OK))
	{
		if (access(argv[1], W_OK))
		{
			put_error(argv[1], errno);
			return (errno);
		}
	}
	save_doc();
	if (check_commands(argv, envp, cmar, -1))
		return (errno);
	
}
