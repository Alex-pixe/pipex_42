/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 14:13:35 by cbridget          #+#    #+#             */
/*   Updated: 2022/01/22 21:47:34 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "libft.h"

int	main(int argc, char **argv, char **envp)
{
	char	***cmar;
	int		err;

	if (ch_hdoc(argc, argv))
		return (pr_hdoc(argc, argv, envp, (void *)0));
	cmar = cr_cmar((void *)0, argc);
	if (!cmar)
		return (1);
	err = check_arg(argc, argv, envp, cmar);
	if (err)
	{
		cr_cmar(cmar, argc);
		return (err);
	}
	err = fprocess(argc, argv, cmar, envp);
	cr_cmar(cmar, argc);
	return (err);
}

char	***cr_cmar(char ***cmar, int argc)
{
	char	***tmp;
	int		i;

	i = 0;
	if (!cmar)
	{
		tmp = malloc(sizeof(char ***) * (argc - 3));
		if (!tmp)
			return ((void *)0);
		while (i < (argc - 3))
		{
			tmp[i] = (void *)0;
			i++;
		}
		return (tmp);
	}
	else
		cr_cmar2(cmar, argc);
	return ((void *)0);
}

void	cr_cmar2(char ***cmar, int argc)
{
	int	i;

	i = 0;
	while (i < (argc - 3))
	{
		clean_s(cmar[i]);
		i++;
	}
	free(cmar);
}

void	clean_s(char **spath)
{
	char	**tmp;

	tmp = spath;
	if (tmp)
	{
		while (*tmp)
		{
			free(*tmp);
			tmp++;
		}
		free(spath);
	}
}
