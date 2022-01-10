/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 18:59:35 by cbridget          #+#    #+#             */
/*   Updated: 2022/01/10 20:52:09 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"

int	main(int argc, char **argv, char **envp)
{
	char **cmds;

	cmds = NULL;
	cmds = cmds_m(cmds);
	if (!cmds)
		return (1);
//	argc = 0;
//	check_commands(argv[1], argv[2], envp, cmds);
//	printf("%s", cmds[0]);
//	return (0);
	if (check_arg(argc, argv, envp, cmds))
		return (1);
//	printf("cmd1=%s, cmd2=%s\n", cmds[0], cmds[1]);

//	int file2 = open(argv[4], O_WRONLY | O_CREAT 0666);

	int pfd_test[2];
	pid_t testing;
	int file1;

	if (pipe(pfd_test))
		return (1);
	file1 = open(argv[1], O_RDONLY);
	if (file1 == -1)
		return (1);

	testing = fork();
	if (testing == -1)
		return (1);
	if (testing == 0)
	{
//		this is a child process

//		printf("%s\n", cmds[0]);
		char *ar[] = {cmds[0], NULL};
		int file1;

		close(pfd_test[0]);
		file1 = open(argv[1], O_RDONLY);
		if (file1 == -1)
			return (1);
		dup2(file1, STDIN_FILENO);
		dup2(pfd_test[1], STDOUT_FILENO);
		close(file1);
		close(pfd_test[1]);
		execve(cmds[0], ar, envp);
		return (0);
	}
	testing = waitpid(testing, NULL, 0);
	char *str = "hi";
	read(pfd_test[0], str, 5);
	printf("str= %s\n", str);
	pid_t testing2;

	testing2 = fork();
	if (testing2 == -1)
		return (1);
	if (testing2 == 0)
	{
		char *ar1[] = {cmds[1], NULL};
		int file2;

		close(pfd_test[1]);
		file2 = open(argv[4], O_WRONLY | O_CREAT, 0666);
		if (file2 == -1)
			return (1);
		dup2(file2, STDOUT_FILENO);
		dup2(pfd_test[0], STDIN_FILENO);
		close(file2);
		close(pfd_test[0]);
		execve(cmds[1], ar1, envp);
		return (0);
	}
//	testing = waitpid(testing, NULL, 0);
	testing2 = waitpid(testing2, NULL, 0);
	printf("success! pidchild1=%d, pidchild2=%d\n", testing, testing2);
	cmds_m(cmds);
	return (0);
}

char	**cmds_m(char **cmds)
{
	if (!cmds)
	{
		cmds = (char **)malloc(sizeof(char *) * 2);
		if (!cmds)
			return ((void *)0);
		cmds[0] = (void *)0;
		cmds[1] = (void *)0;
		return (cmds);
	}
	else
	{
		if (cmds[0])
			free(cmds[0]);
		if (cmds[1])
			free(cmds[1]);
		free(cmds);
	}
	return ((void *)0);
}
