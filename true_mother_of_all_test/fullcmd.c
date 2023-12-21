/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fullcmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchour <chchour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:16:02 by chourael          #+#    #+#             */
/*   Updated: 2023/12/21 12:38:59 by chchour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "true_moat.h"

static int	ft_tabtabsize(t_data *data, int i)
{
	int	o;
	int	size;

	o = 0;
	
}

static int	ft_mallocfullcmd(t_data *data)
{
	int	i;
	int	tabtabsize;

	i = 0;
	data->fullcmd = malloc(sizeof(char **) * (data->ncmd + 1));
	if (data->fullcmd == NULL)
	{
		printf("malloc error\n");
		return (1);
	}
	while (i <= data->ncmd)
	{
		tabtabsize = ft_tabtabsize(data, i);
		data->fullcmd[i];
	}
}

int	ft_allcmd(t_data *data)
{
	ft_mallocfullcmd(data);
}
