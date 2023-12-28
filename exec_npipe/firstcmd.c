/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   firstcmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chourael <chourael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 14:17:17 by chourael          #+#    #+#             */
/*   Updated: 2023/12/28 15:06:52 by chourael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	ft_firstcmd(char **cmd, int	*firstpipe, int stdout)
{
	int	id;

	printf("start firstcmd\n");
	if ((id = fork()) == -1)
	{
		perror("fork");
		return (-1);
	}
	if (id == 0)
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
	}
	else
		wait(NULL);
	printf("end firstcmd\n");
	return (0);
}
