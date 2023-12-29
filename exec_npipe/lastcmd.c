/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lastcmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chourael <chourael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 14:17:19 by chourael          #+#    #+#             */
/*   Updated: 2023/12/29 12:20:04 by chourael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static int	ft_intofile(char ***cmds, int **pipes, int i, int redirect)
{
	dup2(pipes[i - 1][0], STDIN_FILENO);
	dup2(redirect, STDOUT_FILENO);
	ft_closepipes(pipes, len(cmds));
	if (execve(cmds[i][0], cmds[i], NULL) == -1)
	{
		perror("exec");
		return (-1);
	}
	return (0);
}

static int	ft_noredirect(char ***cmds, int **pipes, int i)
{
	dup2(pipes[i - 1][0], STDIN_FILENO);
	ft_closepipes(pipes, len(cmds));
	if (execve(cmds[i][0], cmds[i], NULL) == -1)
	{
		perror("exec");
		return (-1);
	}
	return (0);
}

int	ft_lastcmd(char ***cmds, int **pipes, int i, int *redirection)
{
	int	id;

	printf("start lastcmd\n");
	if ((id = fork()) == -1)
	{
		perror("fork");
		return (-1);
	}
	if (id == 0)
	{
		if (redirection[1] == 0)
		{
			if (ft_noredirect(cmds, pipes, i) == -1)
				return (-1);
		}
		else if (redirection[1] > 0)
		{
			if (ft_intofile(cmds, pipes, i, redirection[1]) == -1)
				return (-1);
		}
	}
	else
		printf("end last cmd\n");
	return (0);
}
