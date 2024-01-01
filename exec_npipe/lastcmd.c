/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lastcmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchour <chchour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 14:17:19 by chourael          #+#    #+#             */
/*   Updated: 2024/01/01 14:43:56 by chchour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static int	ft_intofile(t_exec *exec, char ***cmds, int i)
{
	dup2(exec->pipes[i - 1][0], STDIN_FILENO);
	dup2(exec->redirect[1], STDOUT_FILENO);
	ft_closepipes(exec->pipes, len(cmds));
	if (execve(cmds[i][0], cmds[i], NULL) == -1)
	{
		perror("exec");
		return (-1);
	}
	return (0);
}

static int	ft_noredirect(t_exec *exec, char ***cmds, int i)
{
	dup2(exec->pipes[i - 1][0], STDIN_FILENO);
	ft_closepipes(exec->pipes, len(cmds));
	if (execve(cmds[i][0], cmds[i], NULL) == -1)
	{
		perror("exec");
		return (-1);
	}
	return (0);
}

int	ft_lastcmd(t_exec *exec, char ***cmds, int i)
{
	int	id;

	if ((id = fork()) == -1)
	{
		perror("fork");
		return (-1);
	}
	if (id == 0)
	{
		if (exec->redirect[1] == 0)
		{
			if (ft_noredirect(exec, cmds, i) == -1)
				return (-1);
		}
		else if (exec->redirect[1] > 0)
		{
			if (ft_intofile(exec, cmds, i) == -1)
				return (-1);
		}
	}
	return (0);
}
