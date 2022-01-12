/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 19:17:51 by cbridget          #+#    #+#             */
/*   Updated: 2022/01/12 19:39:23 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>

# include <sys/types.h>
# include <sys/wait.h>


#include <stdio.h> //fix this

int	put_error(char *name, int error, char mod);
int	check_arg(int argc, char **argv, char **envp, char **cmds);
int	check_files(char *file1, char *file2);
int	check_commands(char *cmd1, char *cmd2, char **envp, char **cmds);
char	*search_path(char **env);
void	clean_s(char **spath);
int	check_rights(char *cmd, char **spath, char **cmds, int dx);
char	**cmds_m(char **cmds);

# endif
