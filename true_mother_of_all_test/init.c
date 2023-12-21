/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchour <chchour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:35:10 by chourael          #+#    #+#             */
/*   Updated: 2023/12/21 14:46:59 by chchour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "true_moat.h"

void	ft_initfullcmd2tab(t_data * data, int i, int size)
{
	int	o;

	o = 0;
	while (o <= size)
	{
		data->fullcmd[i][o] = NULL;
		o++;
	}
}

void	ft_initfullcmd3tab(t_data * data)
{
	int	i;

	i = 0;
	while (i <= data->ncmd)
	{
		data->fullcmd[i] = NULL;
		i++;
	}
}

int	ft_initcmdpath(t_data *data)
{
	int	i;

	i = 0;
	data->cmdpath = malloc(sizeof(char *) * (data->ncmd + 1));
	if (data->cmdpath == NULL)
	{
		printf("malloc erro\n");
		return (1);
	}
	while (i <= data->ncmd)
	{
		data->cmdpath[i] = NULL;
		i++;
	}
	return (0);
}

int	ft_initcmds(t_data *data)
{
	int	i;

	i = 0;
	data->cmds = malloc(sizeof(char *) * (data->ncmd + 1));
	if (data->cmds == NULL)
	{
		printf("malloc error 0\n");
		return (1);
	}
	while (i <= data->ncmd)
	{
		data->cmds[i] = NULL;
		i++;
	}
	return (0);
}
