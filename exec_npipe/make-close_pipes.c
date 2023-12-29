/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make-close_pipes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chourael <chourael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 14:50:37 by chourael          #+#    #+#             */
/*   Updated: 2023/12/29 13:20:20 by chourael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	ft_freepipes(int **pipes, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(pipes[i]);
		i++;
	}
	free(pipes);
}

void	ft_closepipes(int	**pipes, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		close(pipes[i][0]);
		close(pipes[i][1]);
		i++;
	}
}

int	**ft_mallocpipes(int size)
{
	int	i;
	int	**pipes;

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
	return (pipes);
}

int	**ft_makepipes(int size)
{
	int	i;
	int	**pipes;

	i = 0;
	pipes = ft_mallocpipes(size);
	if (pipes == NULL)
		return ((int **)-1);
	while (i < size)
	{
		if (pipe(pipes[i]) == -1)
		{
			perror("pipes");
			return ((int **)-1);
		}
		i++;
	}
	return (pipes);
}