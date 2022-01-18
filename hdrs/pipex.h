/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 19:17:51 by cbridget          #+#    #+#             */
/*   Updated: 2022/01/18 13:45:04 by cbridget         ###   ########.fr       */
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

int		save_arco(char **argv, char ***cmar);
int		put_error(char *name, int error);
int		check_arg(int argc, char **argv, char **envp, char ***cmar);
int		check_files(char *file1, char *file2);
int		check_commands(char **argv, char **envp, char ***cmar, int mod);
char	*search_path(char **env);
void	clean_s(char **spath);
int		check_rights(int num, char **spath, char ***cmar);
char	***cr_cmar(char ***cmar);
void	exc_cmd(char *nfile, char **cmar, char **envp, int *pfd);
void	exc_cmd2(char *nfile, char **cmar, char **envp, int *pfd);
int		fprocess(char **argv, char ***cmar, char **envp);
char	*cr_path(int num, char **spath, char ***cmar);

#endif
