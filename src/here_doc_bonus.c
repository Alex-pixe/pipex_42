/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:26:08 by cbridget          #+#    #+#             */
/*   Updated: 2022/01/25 12:55:46 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "libft.h"

int	pr_hdoc(int argc, char **argv, char **envp, char ***cmar)
{
	pid_t	ptmp;
	int		pfd[2][2];
	char	*str;

	if (argc != 6)
		return (1);
	cmar = cr_cmar((void *)0, argc);
	if (!cmar)
		return (1);
	if (pr_hdoc2(envp, argv, cmar, &str))
		return (1);
	if (open_p(pfd, argc, str, cmar))
		return (1);
	ptmp = fork();
	if (ptmp < 0)
		return (clean_d(argc, cmar, str));
	if (ptmp == 0)
		exc_cmdhd(cmar[0], envp, pfd);
	ptmp = fork();
	if (ptmp < 0)
		return (clean_d(argc, cmar, str));
	if (ptmp == 0)
		exc_cmdhd2(argv[argc - 1], cmar[1], envp, pfd);
	pr_hdoc3(pfd, argc, cmar, str);
	return (0);
}

int	pr_hdoc2(char **envp, char **argv, char ***cmar, char **str)
{
	int	argc;

	argc = save_argc(argv);
	*str = save_doc(argv);
	if (!*str)
	{
		cr_cmar(cmar, argc - 1);
		return (1);
	}
	if (!access(argv[1], F_OK))
	{
		if (access(argv[1], W_OK))
		{
			put_error(argv[1], errno);
			clean_d(argc, cmar, *str);
			return (errno);
		}
	}
	if (check_commands(argv, envp, cmar))
	{
		clean_d(argc, cmar, *str);
		return (errno);
	}
	return (0);
}

void	pr_hdoc3(int pfd[][2], int argc, char ***cmar, char *str)
{
	close(pfd[0][0]);
	close(pfd[1][0]);
	close(pfd[1][1]);
	write(pfd[0][1], str, ft_strlen(str));
	close(pfd[0][1]);
	clean_d(argc, cmar, str);
}

void	exc_cmdhd2(char *nfile, char **cmar, char **envp, int pfd[][2])
{
	int	fd;

	close(pfd[0][0]);
	close(pfd[0][1]);
	close(pfd[1][1]);
	fd = open(nfile, O_WRONLY | O_CREAT | O_APPEND, 0666);
	if (fd == -1)
		exit(EXIT_FAILURE);
	dup2(pfd[1][0], STDIN_FILENO);
	dup2(fd, STDOUT_FILENO);
	close(pfd[1][0]);
	close(fd);
	execve(cmar[0], cmar, envp);
	exit(EXIT_FAILURE);
}

void	exc_cmdhd(char **cmar, char **envp, int pfd[][2])
{
	close(pfd[0][1]);
	close(pfd[1][0]);
	dup2(pfd[0][0], STDIN_FILENO);
	dup2(pfd[1][1], STDOUT_FILENO);
	close(pfd[0][0]);
	close(pfd[1][1]);
	execve(cmar[0], cmar, envp);
	exit(EXIT_FAILURE);
}
