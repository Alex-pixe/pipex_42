/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbridget <cbridget@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 18:59:35 by cbridget          #+#    #+#             */
/*   Updated: 2022/01/17 16:20:08 by cbridget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"

// check full path!!!!
//ping -c 3 localhost | cat -e check this!

int	main(int argc, char **argv, char **envp)
{
	char ***cmar;
	int err;

	cmar = cr_cmar((void *)0);
	if (!cmar)
		return (1);
	err = check_arg(argc, argv, envp, cmar);
	if (err)
		return (err);
	err = fprocess(argv, cmar, envp);
	cr_cmar(cmar);
	return (err);
}

char	***cr_cmar(char ***cmar)
{
	char	***tmp;
	int		i;

	i = 0;
	if (!cmar)
	{
		tmp = malloc(sizeof(char ***) * 2);
		if (!tmp)
			return ((void *)0);
		tmp[0] = (void *)0;
		tmp[1] = (void *)0;
		return (tmp);
	}
	else
	{
		while (i < 2)
		{
			clean_s(cmar[i]);
			i++;
		}
		free(cmar);
	}
	return ((void *)0);
}
