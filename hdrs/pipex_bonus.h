/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 14:12:58 by cbridget          #+#    #+#             */
/*   Updated: 2022/01/21 15:27:51 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>

# include <stdio.h>

int		save_arco(int argc, char **argv, char ***cmar);
int		put_error(char *name, int error);
int		check_arg(int argc, char **argv, char **envp, char ***cmar);
int		check_files(char *file1, char *file2);
int		check_commands(char **argv, char **envp, char ***cmar, int mod);
char	*search_path(char **env);
void	clean_s(char **spath);
int		check_rights(int num, char **spath, char ***cmar);
char	***cr_cmar(char ***cmar, int argc);
void	exc_cmd(char *nfile, char **cmar, char **envp, int *pfd);
void	exc_cmd2(char *nfile, char **cmar, char **envp, int *pfd);
int		fprocess(int argc, char **argv, char ***cmar, char **envp);
char	*cr_path(int num, char **spath, char ***cmar);

int	save_argc(char **argv);
int	**cr_pfd(int **pfds, int argc);
void	cl_pfds(int **pfds, int j);
char	*my_realloc(char *str, int *size);
char	*save_doc(char **argv);
int	pr_hdoc(int argc, char **argv, char **envp, char ***cmar);
int	ch_hdoc(int argc, char **argv);

#endif
