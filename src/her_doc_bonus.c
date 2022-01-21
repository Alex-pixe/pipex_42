/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   her_doc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:26:08 by cbridget          #+#    #+#             */
/*   Updated: 2022/01/21 15:28:52by cbridget         ###   ########.fr       */
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
		return (1);
	while (argv[1][i] == str[i])
		i++;
	if (i == 9)
		return (1);
	else
		return (0);
}

int	pr_hdoc(int argc, char **argv, char **envp, char ***cmar)
{
	pid_t	ptmp;
	int		fd;
	int		pfd[2][2];
	char	*str;

	if (argc != 6)
		return (1);
	cmar = cr_cmar((void *)0, argc);
	if (!cmar)
		return (1);
	str = save_doc(argv);
	if (!str)
	{
		cr_cmar(cmar, argc - 1);
		return (1);
	}
	if (!access(argv[1], F_OK))
	{
		if (access(argv[1], W_OK))
		{
			put_error(argv[1], errno);
			cr_cmar(cmar, argc - 1);
			free(str);
			return (errno);
		}
	}
	if (check_commands(argv, envp, cmar, -1))
	{
		cr_cmar(cmar, argc - 1);
		free(str);
		return (errno);
	}
/*	int i = 0;
	while (i < 2)
	{
		int j = 0;
		char **tmp = cmar[i];
		while (tmp[j])
		{
			printf("%s\n", tmp[j]);
			j++;
		}
		i++;
	}*/


	while (i < 2)
	{
		if (pipe(pfd[i]) < 0)
		{
			cr_cmar(cmar, argc - 1);
			free(str);
			return (1);
		}
	}
	ptmp = fork();
	if (ptmp < 0)
	{
		cr_cmar(cmar, argc - 1);
		free(str);
		return (1);
	}
	if (ptmp == 0)
		exc_cmdhd(cmar[0], envp, pfd)
	ptmp = fork();
	if (ptmp < 0)
	{
		cr_cmar(cmar, argc - 1);
		free(str);
		return (1);
	}
	if (ptmp == 0)
		exc_cmdhd2(cmar[0], envp, pfd);

	return (0);
}

void	exc_cmdhd2(char **cmar, char **envp, int **pfd)
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
	close();
	close()
}

void	exc_cmdhd(char **cmar, char **envp, int **pfd)
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

char	*save_doc(char **argv)
{
	char	*str;
	int		size;
	int		i;
	int		length;

	i = 0;
	length = ft_strlen(argv[2]);
	str = my_realloc((void *)0, &size);
	if (!str)
		return (str);
	printf("%s, %d\n", argv[2], length);
	write (STDOUT_FILENO, "pipe heredoc> ", 14);
	while (1)
	{
		if (i + 1 == size)
		{
			str = my_realloc(str, &size);
			if (!str)
				return (str);
		}
		read(STDIN_FILENO, &str[i], 1);
		str[i + 1] = '\0';
		if (str[i] == '\n')
		{
			if (i >= length && !ft_strncmp(argv[2], &str[i - length], length))
			{
				if (i == length || str[i - (length + 1)] == '\n')
				{
					str[i - length] = '\0';
					break ;
				}
			}
			write (STDOUT_FILENO, "pipe heredoc> ", 14);
		}
		i++;
	}
	return (str);
}

char	*my_realloc(char *str, int *size)
{
	char	*tmp;

	if (!str)
	{
		tmp = malloc(sizeof(char) * 10);
		*size = 10;
	}
	else
	{
		tmp = malloc(sizeof(char) * (*size * 2));
		if (!tmp)
		{
			free(str);
			return (tmp);
		}
		ft_strlcpy(tmp, str, ft_strlen(str) + 1);
		*size *= 2;
	}
	return (tmp);
}
