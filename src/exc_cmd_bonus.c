/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exc_cmd_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 14:13:57 by cbridget          #+#    #+#             */
/*   Updated: 2022/01/20 16:01:02 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "libft.h"

void	exc_cmd(char *nfile, char **cmar, char **envp, int *pfd)
{
	int	fd;

	close(pfd[0]);
	fd = open(nfile, O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE);
	dup2(fd, STDIN_FILENO);
	dup2(pfd[1], STDOUT_FILENO);
	close(fd);
	close(pfd[1]);
	execve(cmar[0], cmar, envp);
	exit(EXIT_FAILURE);
}

void	exc_cmd2(char *nfile, char **cmar, char **envp, int *pfd)
{
	int	fd;

	close(pfd[1]);
	fd = open(nfile, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd == -1)
		exit(EXIT_FAILURE);
	dup2(fd, STDOUT_FILENO);
	dup2(pfd[0], STDIN_FILENO);
	close(fd);
	close(pfd[0]);
	execve(cmar[0], cmar, envp);
	exit(EXIT_FAILURE);
}

void	exc_cmdc(char **cmar, char **envp, int **pfds, int j)
{
	int	nfd;
	int	i;

	nfd = 0;
	i = 0;
	while (pfds[nfd])
		nfd++;
	while (i < nfd)
	{
		if (i == (j - 1))
			close(pfds[i][1]);
		else if (i == j)
			close(pfds[i][0]);
		else
		{
			close(pfds[i][0]);
			close(pfds[i][1]);
		}
		i++;
	}
	dup2(pfds[j][1], STDOUT_FILENO);
	dup2(pfds[j - 1][0], STDIN_FILENO);
	close(pfds[j][1]);
	close(pfds[j - 1][0]);
	execve(cmar[0], cmar, envp);
	exit(EXIT_FAILURE);
}

int	fprocess(int argc, char **argv, char ***cmar, char **envp)
{
	int		**pfds;
	int		j;
	pid_t	ptmp;

	j = 0;
	pfds = cr_pfd((void *)0, argc);
	if (!pfds)
		return (1);
	while (j < (argc - 4))
	{
		if (pipe(pfds[j]) < 0)
		{
			cr_pfd(pfds, argc);
			return (1);
		}
		j++;
	}
	j = 0;
	while (j < (argc - 3))
	{
		ptmp = fork();
		if (ptmp < 0)
		{
			cl_pfds(pfds, -1);
			cr_pfd(pfds, argc);
			return (1);
		}
		if (ptmp == 0)
		{
			if (j != 0 && j != (argc - 4))
				exc_cmdc(cmar[j], envp, pfds, j);
			else
			{
				cl_pfds(pfds, j);
				if (j == 0)
					exc_cmd(argv[1], cmar[0], envp, pfds[0]);
				else if (j == (argc - 4))
					exc_cmd2(argv[argc - 1], cmar[argc - 4], envp, pfds[argc - 5]);
			}
		}
		j++;
	}
	cl_pfds(pfds, -1);
	waitpid(ptmp, &j, 0);
	return (j);
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
	int	i;

	i = 1;
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
		while (i < (argc - 4))
		{
			tmp[i] = tmp[0] + i * 2;
			i++;
		}
		tmp[i] = (void *)0;
		return (tmp);
	}
	else
	{
		free(pfds[0]);
		free(pfds);
		return ((void *)0);
	}
}
