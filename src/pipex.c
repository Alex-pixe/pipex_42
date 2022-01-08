/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 18:59:35 by cbridget          #+#    #+#             */
/*   Updated: 2022/01/08 20:34:31 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"

int	main(int argc, char **argv, char **envp)
{
	char **cmds;

	cmds = cmds_m(cmds, 1);
	if (!cmds)
		return (1);
//	argc = 0;
//	check_commands(argv[1], argv[2], envp, cmds);
//	printf("%s", cmds[0]);
//	return (0);
	if (check_arg(argc, argv, envp, cmds))
		return (1);
//	printf("cmd1=%s, cmd2=%s\n", cmds[0], cmds[1]);


	pid_t testing;

	testing = fork();
	if (testing == -1)
		return (1);
	if (testing == 0)
	{
//		printf("%s\n", cmds[0]);
		char *ar[] = {cmds[0], "file1", NULL};
		execve(cmds[0], ar, envp);
		printf("failure\n");
	}
	else
	{
		int i = 0;
		while (i < 1000)
		{
			printf("here\n");
			i++;
		}
		testing = waitpid(testing, NULL, 0);
		printf("success! pidchild=%d\n", testing);
	}
	cmds_m(cmds, 0);
	return (0);
}

char	**cmds_m(char **cmds,char mod)
{
	if (mod)
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
