/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middlecmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchour <chchour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:07:28 by chourael          #+#    #+#             */
/*   Updated: 2024/01/01 15:17:56 by chchour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	ft_middlecmd(t_exec *exec, char ***cmds)
{
	int	id;
	int	i;

	i = 2;
	while(cmds[i + 1] != NULL && cmds[i])
	{
		if ((id = fork()) == -1)
			perror("fork");
		if (id == 0)
		{
			dup2(exec->pipes[i - 1][0], STDIN_FILENO);
			dup2(exec->pipes[i][1], STDOUT_FILENO);
			ft_closepipes(exec->pipes, len(cmds));
			if (execve(cmds[i][0], cmds[i], NULL) == -1)
			{
				dup2(exec->stdout, STDOUT_FILENO);
				perror("exec");
				return (-1);
			}
		}
		else
			i++;
	}
	return (i);
}
