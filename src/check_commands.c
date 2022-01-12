/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 21:15:06 by cbridget          #+#    #+#             */
/*   Updated: 2022/01/06 17:55:13by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"

int	check_commands(char *cmd1, char *cmd2, char **envp, char **cmds)
{
	int		ch;
	char	*path;
	char	**spath;

	path = search_path(envp);
	if (!path)
		return (1);
	spath = ft_split(path, ':');
	if (!spath)
		return (1);
	if (!cmd1)
		ch = check_rights(cmd2, spath, cmds, 1);
	else
	{
		ch = check_rights(cmd1, spath, cmds, 0);
		ch = check_rights(cmd2, spath, cmds, 1);
	}
	clean_s(spath);
	if (ch)
		return (1);
	return (0);
}

int	check_rights(char *cmd, char **spath, char **cmds, int dx)
{
	int		length;
	char	*tmp;

	length = ft_strlen(cmd);
	if (!(access(cmd, F_OK | X_OK)))
	{
		cmds[dx] = cmd;
		return (0);
	}
	while (*spath)
	{
		length += ft_strlen(*spath);
		tmp = (char *)malloc(sizeof(char) * (length + 2));
		if (!tmp)
			return (1);
		ft_strlcpy(tmp, *spath, ft_strlen(*spath) + 1);
		ft_strlcat(tmp, "/", ft_strlen(tmp) + 2);
		ft_strlcat(tmp, cmd, length + 2);
		if (!(access(tmp, F_OK | X_OK)))
		{
			cmds[dx] = tmp;
			return (0);
		}
		free(tmp);
		spath++;
	}
	put_error(cmd, 0, 1);
	return (1);
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
//	return ("/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/munki:/opt/X11/bin");
}

void	clean_s(char **spath)
{
	char	**tmp;

	tmp = spath;
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(spath);
}
