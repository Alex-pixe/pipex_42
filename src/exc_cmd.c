/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exc_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:56:32 by cbridget          #+#    #+#             */
/*   Updated: 2022/01/18 13:47:35 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
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
	fd = open(nfile, O_WRONLY | O_CREAT, 0666);
	if (fd == -1)
		exit(EXIT_FAILURE);
	dup2(fd, STDOUT_FILENO);
	dup2(pfd[0], STDIN_FILENO);
	close(fd);
	close(pfd[0]);
	execve(cmar[0], cmar, envp);
	exit(EXIT_FAILURE);
}

int	fprocess(char **argv, char ***cmar, char **envp)
{
	int		pfd[2];
	int		err;
	pid_t	ptmp;

	if (pipe(pfd))
		return (1);
	ptmp = fork();
	if (ptmp == -1)
		return (1);
	if (ptmp == 0)
		exc_cmd(argv[1], cmar[0], envp, pfd);
	ptmp = fork();
	if (ptmp == -1)
		return (1);
	if (ptmp == 0)
		exc_cmd2(argv[4], cmar[1], envp, pfd);
	close(pfd[0]);
	close(pfd[1]);
	waitpid(ptmp, &err, 0);
	if (err)
		return (1);
	return (0);
}
