/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 18:59:35 by cbridget          #+#    #+#             */
/*   Updated: 2022/01/18 14:22:33 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"

int	main(int argc, char **argv, char **envp)
{
	char	***cmar;
	int		err;

	cmar = cr_cmar((void *)0);
	if (!cmar)
		return (1);
	err = check_arg(argc, argv, envp, cmar);
	if (err)
	{
		cr_cmar(cmar);
		return (err);
	}
	err = fprocess(argv, cmar, envp);
	cr_cmar(cmar);
	return (err);
}

char	***cr_cmar(char ***cmar)
{
	char	***tmp;
	int		i;

	i = 0;
	if (!cmar)
	{
		tmp = malloc(sizeof(char ***) * 2);
		if (!tmp)
			return ((void *)0);
		tmp[0] = (void *)0;
		tmp[1] = (void *)0;
		return (tmp);
	}
	else
	{
		while (i < 2)
		{
			clean_s(cmar[i]);
			i++;
		}
		free(cmar);
	}
	return ((void *)0);
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
