/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 21:15:06 by cbridget          #+#    #+#             */
/*   Updated: 2022/01/25 13:53:38 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"

int	check_commands(char **argv, char **envp, char ***cmar, int mod)
{
	int		err;
	char	**spath;

	err = save_arco(argv, cmar);
	if (err)
		return (err);
	spath = ft_split(search_path(envp), ':');
	if (!spath)
		return (1);
	if (mod == 1)
		err = check_rights(1, spath, cmar);
	else if (mod == 2)
		err = check_rights(0, spath, cmar);
	else
	{
		err = check_rights(0, spath, cmar);
		err += check_rights(1, spath, cmar);
	}
	clean_s(spath);
	return (err);
}

int	check_rights(int num, char **spath, char ***cmar)
{
	char	*tmp;

	if (!(access(*cmar[num], F_OK | X_OK)))
		return (0);
	while (*spath)
	{
		tmp = cr_path(num, spath, cmar);
		if (!tmp)
			return (1);
		if (!(access(tmp, F_OK | X_OK)))
		{
			free(*cmar[num]);
			*cmar[num] = tmp;
			return (0);
		}
		free(tmp);
		spath++;
	}
	put_error(*cmar[num], 0);
	return (1);
}

char	*cr_path(int num, char **spath, char ***cmar)
{
	char	*tmp;
	int		length;

	length = ft_strlen(*cmar[num]);
	length += ft_strlen(*spath);
	tmp = (char *)malloc(sizeof(char) * (length + 2));
	if (!tmp)
		return ((void *)0);
	ft_strlcpy(tmp, *spath, ft_strlen(*spath) + 1);
	ft_strlcat(tmp, "/", ft_strlen(tmp) + 2);
	ft_strlcat(tmp, *cmar[num], length + 2);
	return (tmp);
}

int	save_arco(char **argv, char ***cmar)
{
	int	i;
	int	j;

	i = 0;
	j = 2;
	while (i < 2)
	{
		cmar[i] = ft_split(argv[j], ' ');
		if (!cmar[i])
			return (1);
		i++;
		j++;
	}
	return (0);
}

char	*search_path(char **env)
{
	int		i;
	char	*src;

	i = 0;
	src = "PATH";
	while (env)
	{
		while ((*env)[i] == src[i])
		{
			if (i == 3)
				return (&(*env)[i + 2]);
			i++;
		}
		i = 0;
		env++;
	}
	return ((void *)0);
}
