/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 19:29:17 by cbridget          #+#    #+#             */
/*   Updated: 2022/01/25 12:49:42 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "libft.h"

int	open_p(int pfd[][2], int argc, char *str, char ***cmar)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (pipe(pfd[i]) < 0)
			return (clean_d(argc, cmar, str));
		i++;
	}
	return (0);
}

int	clean_d(int argc, char ***cmar, char *str)
{
	cr_cmar(cmar, argc - 1);
	free(str);
	return (1);
}

char	*save_doc(char **argv)
{
	char	*str;
	int		size;
	int		i;
	int		err;

	i = 0;
	str = my_realloc((void *)0, &size);
	if (!str)
		return (str);
	write (STDOUT_FILENO, "pipe heredoc> ", 14);
	while (1)
	{
		err = save_doc2(argv, &str, i, &size);
		if (err == 1)
			return ((void *)0);
		else if (err == 2)
			break ;
		else
			i++;
	}
	return (str);
}

int	save_doc2(char **argv, char **str, int i, int *size)
{
	int	length;

	length = ft_strlen(argv[2]);
	if (i + 1 == *size)
	{
		*str = my_realloc(*str, size);
		if (!str)
			return (1);
	}
	read(STDIN_FILENO, &(*str)[i], 1);
	(*str)[i + 1] = '\0';
	if ((*str)[i] == '\n')
	{
		if (i >= length && !ft_strncmp(argv[2], &(*str)[i - length], length))
		{
			if (i == length || (*str)[i - (length + 1)] == '\n')
			{
				(*str)[i - length] = '\0';
				return (2);
			}
		}
		write (STDOUT_FILENO, "pipe heredoc> ", 14);
	}
	return (0);
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
		free(str);
		*size *= 2;
	}
	return (tmp);
}
