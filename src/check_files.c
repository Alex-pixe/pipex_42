/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:28:14 by cbridget          #+#    #+#             */
/*   Updated: 2022/01/05 21:06:53 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"

int	check_arg(int argc, char **argv)
{
	if (argc != 5)
		return (1);
	if (check_files(argv[1], argv[argc - 1]))
		return (1);
	if (check_commands())
		return (1);
	return (0);
}

int	check_files(char *file1, char *file2)
{
	errno = 0;
	if (access(file1, F_OK | R_OK))
		return (put_error(file1, errno));
	if (access(file2, F_OK | W_OK))
		return (put_error(file2, errno));
	return (0);
}

int	put_error(char *name, int error)
{
	char	*str;
	int		length;

	str = strerror(error);
	length = ft_strlen(str);
	write (2, "pipex: ", 7);
	write (2, str, length);
	write (2, ": ", 2);
	length = ft_strlen(name);
	write (2, name, length);
	write (2, "\n", 1);
	return (1);
}
