/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_commands_bonus2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 20:38:31 by cbridget          #+#    #+#             */
/*   Updated: 2022/01/22 20:39:04 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "libft.h"

int	save_argc(char **argv)
{
	int	argc;

	argc = 0;
	while (argv[argc])
		argc++;
	if (ch_hdoc(argc, argv))
		argc--;
	return (argc);
}

char	*search_path(char **env)
{
	int		i;
	char	*src;

	i = 0;
	src = "PATH";
	while (env)
	{
		while ((*env)[i] == src[i])
		{
			if (i == 3)
				return (&(*env)[i + 2]);
			i++;
		}
		i = 0;
		env++;
	}
	return ((void *)0);
}
