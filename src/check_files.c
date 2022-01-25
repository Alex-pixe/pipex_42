/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:28:14 by cbridget          #+#    #+#             */
/*   Updated: 2022/01/25 13:48:30 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"

int	check_arg(int argc, char **argv, char **envp, char ***cmar)
{
	int	err;

	if (argc != 5)
		return (1);
	err = check_files(argv[1], argv[argc - 1]);
	if (err)
	{
		check_commands(argv, envp, cmar, err);
		return (err);
	}
	else if (check_commands(argv, envp, cmar, 0))
		return (4);
	return (0);
}

int	check_files(char *file1, char *file2)
{
	int	err;
	int	fd;

	err = 0;
	if (access(file1, F_OK | R_OK))
	{
		err += 1;
		put_error(file1, errno);
	}
	else if (!access(file2, F_OK))
	{
		if (access(file2, W_OK))
		{
			err += 2;
			put_error(file2, errno);
		}
	}
	if (access(file2, F_OK))
	{
		fd = open(file2, O_CREAT, 0666);
		close(fd);
	}
	return (err);
}

int	put_error(char *name, int error)
{
	char	*str;
	int		length;

	if (error)
		str = strerror(error);
	else
		str = "command not found";
	length = ft_strlen(str);
	write (2, "pipex: ", 7);
	write (2, str, length);
	write (2, ": ", 2);
	length = ft_strlen(name);
	write (2, name, length);
	write (2, "\n", 1);
	return (1);
}
