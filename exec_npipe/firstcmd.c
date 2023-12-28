/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   firstcmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chourael <chourael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 14:17:17 by chourael          #+#    #+#             */
/*   Updated: 2023/12/28 18:17:12 by chourael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

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
}

int	ft_firstcmd(char **cmd, int	*firstpipe, int stdout, int redirect)
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
		if (redirect == 0)
			ft_noredirect(cmd, firstpipe, stdout);
		else if (redirect == 1)
			ft_fromfile
	}
	else
		wait(NULL);
	printf("end firstcmd\n");
	return (0);
}
