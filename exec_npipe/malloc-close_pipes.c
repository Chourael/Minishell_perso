/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc-close_pipes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chourael <chourael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 14:50:37 by chourael          #+#    #+#             */
/*   Updated: 2023/12/28 15:06:43 by chourael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void ft_closepipes(int	**pipes, int size)
{
	int	i;

	printf("start closepipes\n");
	i = 0;
	while (i < size)
	{
		close(pipes[i][0]);
		close(pipes[i][1]);
		i++;
	}
	printf("end closepipes\n");
}

int	**ft_mallocpipes(int size)
{
	int	i;
	int	**pipes;

	printf("start mallocpipes\n");
	i = 0;
	pipes = malloc(sizeof(int *) * size);
	if (pipes == NULL)
	{
		printf("pipes error\n");
		return (NULL);
	}
	while (i < size)
	{	
		pipes[i] = malloc(sizeof(int) * 2);
		if (pipes[i] == NULL)
		{
			printf("pipes[%d] error\n", i);
			return (NULL);
		}
		i++;
	}
	printf("end mallocpipes\n");
	return (pipes);
}
