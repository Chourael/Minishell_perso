/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   firstcmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chourael <chourael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 14:17:17 by chourael          #+#    #+#             */
/*   Updated: 2023/12/29 12:26:53 by chourael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static int	ft_fromfile(char **cmd, int *firstpipe, int stdout, int redirect)
{
	close(firstpipe[0]);
	dup2(firstpipe[1], STDOUT_FILENO);
	close(firstpipe[1]);
	dup2(redirect, STDIN_FILENO);
	if (execve(cmd[0], cmd, NULL) == -1)
	{
		dup2(stdout, STDOUT_FILENO);
		perror("exec");
		return (-1);
	}
	return (0);
}

static int	ft_noredirect(char **cmd, int *firstpipe, int stdout)
{
	close(firstpipe[0]);
	dup2(firstpipe[1], STDOUT_FILENO);
	close(firstpipe[1]);
	if (execve(cmd[0], cmd, NULL) == -1)
	{
		dup2(stdout, STDOUT_FILENO);
		perror("exec");
		return (-1);
	}
	return (0);
}

int	ft_firstcmd(char **cmd, int	*firstpipe, int stdout, int *redirect)
{
	int	id;

	if ((id = fork()) == -1)
	{
		perror("fork");
		return (-1);
	}
	if (id == 0)
	{
		if (redirect[0] == 0)
		{
			if (ft_noredirect(cmd, firstpipe, stdout) == -1)
				return (-1);
		}
		else if (redirect[0] > 0)
		{
			if (ft_fromfile(cmd, firstpipe, stdout, redirect[0]) == -1)
				return (-1);
		}
	}
	else
		wait(NULL);
	return (0);
}
