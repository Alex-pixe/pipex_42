/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student-21school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 14:12:58 by cbridget          #+#    #+#             */
/*   Updated: 2022/01/24 21:53:13 by cbridget         ###   ########.fr       */
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

int		save_arco(int argc, char **argv, char ***cmar);
int		put_error(char *name, int error);
int		check_arg(int argc, char **argv, char **envp, char ***cmar);
int		check_files(char *file1, char *file2);
int		check_commands(char **argv, char **envp, char ***cmar);
char	*search_path(char **env);
void	clean_s(char **spath);
int		check_rights(int num, char **spath, char ***cmar);
char	***cr_cmar(char ***cmar, int argc);
void	exc_cmd(char *nfile, char **cmar, char **envp, int *pfd);
void	exc_cmd2(char *nfile, char **cmar, char **envp, int *pfd);
void	exc_cmdc(char **cmar, char **envp, int **pfds, int j);
int		fprocess(int argc, char **argv, char ***cmar, char **envp);
char	*cr_path(int num, char **spath, char ***cmar);
int		save_argc(char **argv);
int		**cr_pfd(int **pfds, int argc);
void	cl_pfds(int **pfds, int j);
char	*my_realloc(char *str, int *size);
char	*save_doc(char **argv);
int		pr_hdoc(int argc, char **argv, char **envp, char ***cmar);
int		ch_hdoc(int argc, char **argv);
void	exc_cmdhd2(char *nfile, char **cmar, char **envp, int pfd[][2]);
void	exc_cmdhd(char **cmar, char **envp, int pfd[][2]);
int		check_commands2(int argc, char **spath, char ***cmar);
int		**fprocess_h(int argc);
void	fprocess_h2(char **argv, char ***cmar, char **envp, int **pfds);
int		save_j(int value);
void	cr_pfd2(int **tmp, int argc);
void	cr_cmar2(char ***cmar, int argc);
int		pr_hdoc2(char **envp, char **argv, char ***cmar, char **str);
int		open_p(int pfd[][2], int argc, char *str, char ***cmar);
int		clean_d(int argc, char ***cmar, char *str);
void	pr_hdoc3(int pfd[][2], int argc, char ***cmar, char *str);
int		save_doc2(char **argv, char **str, int i, int *size);

#endif
