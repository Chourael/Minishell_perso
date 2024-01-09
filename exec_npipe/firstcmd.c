/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   firstcmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chourael <chourael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 14:17:17 by chourael          #+#    #+#             */
/*   Updated: 2024/01/09 11:41:10 by chourael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static int	ft_heardoc(t_exec *exec, char **cmd, char *heardoc)
{
	int	hearpipe[2];

	pipe(hearpipe);
	write(hearpipe[1], heardoc, ft_strlen(heardoc));
	dup2(hearpipe[0], STDIN_FILENO);
	close(hearpipe[0]);
	close(hearpipe[1]);
	dup2(exec->pipes[0][1], STDOUT_FILENO);
	if (execve(cmd[0], cmd, NULL) == -1)
	{
		dup2(exec->stdout, STDOUT_FILENO);
		perror("exec");
		return (-1);
	}
	return (0);
}

static int	ft_fromfile(t_exec *exec, char **cmd)
{
	dup2(exec->pipes[0][1], STDOUT_FILENO);
	dup2(exec->redirect[0], STDIN_FILENO);
	if (execve(cmd[0], cmd, NULL) == -1)
	{
		dup2(exec->stdout, STDOUT_FILENO);
		perror("exec");
		return (-1);
	}
	return (0);
}

static int	ft_noredirect(t_exec *exec, char **cmd)
{
	dup2(exec->pipes[0][1], STDOUT_FILENO);
	if (execve(cmd[0], cmd, NULL) == -1)
	{
		dup2(exec->stdout, STDOUT_FILENO);
		perror("exec");
		return (-1);
	}
	return (0);
}

int	ft_firstcmd(t_exec *exec, char ***cmds, char *heardoc)
{
	int	id;

	if ((id = fork()) == -1)
	{
		perror("fork");
		return (-1);
	}
	if (id == 0)
	{
		if (heardoc != NULL)
		{
			if (ft_heardoc(exec, cmds[0], heardoc) == -1)
				return (-1);
		}
		else if (exec->redirect[0] == 0)
		{
			if (ft_noredirect(exec, cmds[0]) == -1)
				return (-1);
		}
		else if (exec->redirect[0] > 0)
		{
			if (ft_fromfile(exec, cmds[0]) == -1)
				return (-1);
		}
	}
	else
	{
		// wait(NULL);
		return(0);
	}
	return (0);
}
