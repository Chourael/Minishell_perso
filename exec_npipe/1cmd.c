/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1cmd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchour <chchour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:10:34 by chourael          #+#    #+#             */
/*   Updated: 2024/01/01 17:13:03 by chchour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static int	ft_cmd(char ***cmds)
{
	if (execve(cmds[0][0], cmds[0], NULL) == -1)
	{
		perror("execve");
		return (-1);
	}
	return (0);
}

static int	ft_in(t_exec *exec, char ***cmds)
{
	dup2(exec->redirect[0], STDIN_FILENO);
	if (execve(cmds[0][0], cmds[0], NULL) == -1)
	{
		perror("execve");
		return (-1);
	}
	return (0);
}

static int	ft_out(t_exec *exec, char ***cmds)
{
	dup2(exec->redirect[1], STDOUT_FILENO);
	if (execve(cmds[0][0], cmds[0], NULL) == -1)
	{
		perror("execve");
		return (-1);
	}
	return (0);
}

static int	ft_inout(t_exec *exec, char ***cmds)
{
	dup2(exec->redirect[0], STDIN_FILENO);
	dup2(exec->redirect[1], STDOUT_FILENO);
	if (execve(cmds[0][0], cmds[0], NULL) == -1)
	{
		perror("execve");
		return (-1);
	}
	return (0);
}

static int	ft_heardoc(t_exec *exec, char ***cmds, char *heardoc)
{
	int	id;

	id = fork();
	if (id == -1)
		perror("fork");
	else if (id == 0)
	{
		if (write(exec->pipes[0][1], heardoc, ft_strlen(heardoc)) == -1)
			perror("write");
		exit(0);
	}
	else if (id > 0)
	{
		char	buffer[500] = "e";

		if (dup2(exec->pipes[0][0], STDIN_FILENO) == -1)
			perror("dup2");
		read(STDIN_FILENO, buffer, sizeof(buffer));
		printf("in pipe %s \n\n", buffer);
		if (execve(cmds[0][0], cmds[0], NULL) == -1)
		{
			perror("execve");
			return (-1);
		}
	}
	return (0);
}

static int	ft_heardocout(t_exec *exec, char ***cmds, char *heardoc)
{
	dup2(exec->redirect[0], STDIN_FILENO);
	write(exec->pipes[0][1], heardoc, ft_strlen(heardoc));
	dup2(exec->pipes[0][0], STDOUT_FILENO);
	if (execve(cmds[0][0], cmds[0], NULL) == -1)
	{
		perror("execve");
		return (-1);
	}
	return (0);
}

int	ft_1cmd(t_exec *exec, char ***cmds, char *heardoc)
{
	int	id;

	if ((id = fork()) == -1)
		perror("fork");
	if (id == 0)
	{
		if (exec->redirect[0] == 0 && exec->redirect[1] == 0 && heardoc == NULL)
		{
			if (ft_cmd(cmds) == -1)
				return (-1);
		}
		else if (exec->redirect[0] > 0 && exec->redirect[1] == 0 && heardoc != NULL)
		{
			if (ft_in(exec, cmds) == -1)
				return (-1);
		}
		else if (exec->redirect[0] == 0 && exec->redirect[1] > 0 && heardoc != NULL)
		{
			if (ft_out(exec, cmds) == -1)
				return (-1);
		}
		else if (exec->redirect[0] > 0 && exec->redirect[1] > 0 && heardoc != NULL)
		{
			if (ft_inout(exec, cmds) == -1)
				return (-1);
		}
		else if (heardoc != NULL && exec->redirect[1] == 0)
		{
			if (ft_heardoc(exec, cmds, heardoc) == -1)
				return (-1);
		}
		else if (heardoc != NULL && exec->redirect[1] > 0)
		{
			if (ft_heardocout(exec, cmds, heardoc) == -1)
				return (-1);
		}
	}
	else if (id > 0)
		return (0);
	return (0);
}