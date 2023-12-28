/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1cmd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chourael <chourael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:10:34 by chourael          #+#    #+#             */
/*   Updated: 2023/12/28 17:12:13 by chourael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	ft_1cmd(char ***cmds)
{
	int	id;

	printf("start 1cmd\n");
	if ((id = fork()) == -1)
		perror("fork");
	if (id == 0)
	{
		if (execve(cmds[0][0], cmds[0], NULL) == -1)
		{
			perror("execve");
			return (1);
		}
	}
	printf("end 1cmd\n");
	return (0);
}