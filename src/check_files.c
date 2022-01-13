/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:28:14 by cbridget          #+#    #+#             */
/*   Updated: 2022/01/13 15:30:48 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"

int	check_arg(int argc, char **argv, char **envp, char **cmds)
{
	int	err;

	if (argc != 5)
		return (1);
	err = check_files(argv[1], argv[argc - 1]);
	if (err)
	{
		if (err == 1)
		{
			check_commands((void *)0, argv[3], envp, cmds);
			return (errno);
		}
		else if (err == 2)
		{
			check_commands(argv[2], (void *)0, envp, cmds);
			return (errno);
		}
		else
			return (errno);
	}
	if (check_commands(argv[2], argv[3], envp, cmds))
		return (errno);
	return (0);
}

int	check_files(char *file1, char *file2)
{
	int	err;

	err = 0;
	if (access(file1, F_OK | R_OK))
		err += 1;
//		return (put_error(file1, errno, 0));
	if (!access(file2, F_OK))
	{
		if (access(file2, W_OK))
			err += 2;
//			return (put_error(file2, errno, 0));
	}
	return (err);
}

int	put_error(char *name, int error, char mod)
{
	char	*str;
	int		length;

	if (!mod)
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
