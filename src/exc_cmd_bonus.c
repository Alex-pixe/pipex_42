/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exc_cmd_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 14:13:57 by cbridget          #+#    #+#             */
/*   Updated: 2022/01/25 12:33:32 by cbridget         ###   ########.fr       */
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
	i = -1;
	while (pfds[nfd])
		nfd++;
	while (++i < nfd)
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

	j = -1;
	pfds = fprocess_h(argc);
	if (!pfds)
		return (1);
	while (++j < (argc - 3))
	{
		ptmp = fork();
		if (ptmp < 0)
		{
			cl_pfds(pfds, -1);
			cr_pfd(pfds, argc);
			return (1);
		}
		save_j(j);
		if (ptmp == 0)
			fprocess_h2(argv, cmar, envp, pfds);
	}
	cl_pfds(pfds, -1);
	waitpid(ptmp, &j, 0);
	cr_pfd(pfds, argc);
	return (j);
}

int	save_j(int value)
{
	static int	j;

	if (value)
	{
		j = value;
		return (0);
	}
	else
		return (j);
}
