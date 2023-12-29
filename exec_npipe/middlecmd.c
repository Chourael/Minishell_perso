/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middlecmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chourael <chourael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:07:28 by chourael          #+#    #+#             */
/*   Updated: 2023/12/28 16:33:01 by chourael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	ft_middlecmd(char ***cmds, int **pipes, int stdout)
{
	int	id;
	int	i;

	printf("start middlecmd\n");
	i = 1;
	while(cmds[i + 1] != NULL && cmds[i])
	{
		printf("start while %d\n", i);
		if ((id = fork()) == -1)
			perror("fork");
		if (id == 0)
		{
			dup2(pipes[i - 1][0], STDIN_FILENO);
			dup2(pipes[i][1], STDOUT_FILENO);
			ft_closepipes(pipes, len(cmds));
			if (execve(cmds[i][0], cmds[i], NULL) == -1)
			{
				dup2(stdout, STDOUT_FILENO);
				perror("exec");
				return (-1);
			}
		}
		else
			i++;
	}
	printf("end middlecmd\n");
	return (i);
}