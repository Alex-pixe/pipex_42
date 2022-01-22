/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exc_cmd2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 21:37:55 by cbridget          #+#    #+#             */
/*   Updated: 2022/01/22 21:38:40 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "libft.h"

void	fprocess_h2(char **argv, char ***cmar, char **envp, int **pfds)
{
	int	j;
	int	argc;

	argc = save_argc(argv);
	j = save_j(0);
	if (j != 0 && j != (argc - 4))
		exc_cmdc(cmar[j], envp, pfds, j);
	else
	{
		cl_pfds(pfds, j);
		if (j == 0)
			exc_cmd(argv[1], cmar[0], envp, pfds[0]);
		else if (j == (argc - 4))
			exc_cmd2(argv[argc - 1], cmar[argc - 4],
				envp, pfds[argc - 5]);
	}
	j++;
	printf("%d, j = %d\n", argc, j);
}

int	**fprocess_h(int argc)
{
	int	**pfds;
	int	j;

	j = 0;
	pfds = cr_pfd((void *)0, argc);
	if (!pfds)
		return ((void *)0);
	while (j < (argc - 4))
	{
		if (pipe(pfds[j]) < 0)
		{
			cr_pfd(pfds, argc);
			return ((void *)0);
		}
		j++;
	}
	return (pfds);
}

void	cl_pfds(int **pfds, int j)
{
	int	i;

	i = 0;
	while (pfds[i])
	{
		if ((i != 0 || j != 0) && i != j - 1)
		{
			close(pfds[i][0]);
			close(pfds[i][1]);
		}
		i++;
	}
}

int	**cr_pfd(int **pfds, int argc)
{
	int	**tmp;

	if (!pfds)
	{
		tmp = malloc(sizeof(int *) * (argc - 3));
		if (!tmp)
			return ((void *)0);
		tmp[0] = malloc(sizeof(int) * ((argc - 4) * 2));
		if (!tmp[0])
		{
			free(tmp);
			return ((void *)0);
		}
		cr_pfd2(tmp, argc);
		return (tmp);
	}
	else
	{
		free(pfds[0]);
		free(pfds);
		return ((void *)0);
	}
}

void	cr_pfd2(int **tmp, int argc)
{
	int	i;

	i = 1;
	while (i < (argc - 4))
	{
		tmp[i] = tmp[0] + i * 2;
		i++;
	}
	tmp[i] = (void *)0;
}
