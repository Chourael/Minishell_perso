/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chourael <chourael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:35:10 by chourael          #+#    #+#             */
/*   Updated: 2023/12/20 18:15:36 by chourael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "true_moat.h"

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
		printf("malloc error\n");
		return (1);
	}
	while (i <= data->ncmd)
	{
		data->cmds[i] = NULL;
		i++;
	}
	return (0);
}
