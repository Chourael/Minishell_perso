/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lastcmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chourael <chourael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 14:17:19 by chourael          #+#    #+#             */
/*   Updated: 2023/12/28 15:06:47 by chourael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	ft_lastcmd(char ***cmds, int **pipes, int i)
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
		dup2(pipes[i - 1][0], STDIN_FILENO);
		ft_closepipes(pipes, len(cmds));
		if (execve(cmds[i][0], cmds[i], NULL) == -1)
		{
			perror("exec");
			return (-1);
		}
	}
	else
	{
		printf("end last cmd\n");
		return (0);
	}
	return (0);
}
