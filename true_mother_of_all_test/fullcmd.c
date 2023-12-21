/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fullcmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchour <chchour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:16:02 by chourael          #+#    #+#             */
/*   Updated: 2023/12/21 14:15:07 by chchour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "true_moat.h"

static int	ft_tabtabsize(char **insp, int i)
{
	int	o;
	int	size;

	o = 0;
	size = -1;
	while(insp[i][o])
	{
		if (insp[i][o] == ' ' || insp[i][o] == '\0')
			size++;
		o++;
	}
	printf("tabtabsize = %d\n", size);
	return (size);
}

static int	ft_malloctabsize(t_data *data, char **insp, int tabtabsize, int i)
{
	int	o;
	int	j;
	int	tabsize;

	o = 1;
	j = 0;
	tabsize = 0;
	while (insp[i][j] != '\0' && insp[i][j++] != ' ')
	while (insp[i][j] != '\0' && insp[i][j++] != ' ')
	while (o < tabtabsize)
	{
		while(insp[i][j] != ' ' && insp[i][j])
		{
			tabsize++;
			j++;
		}
		data->fullcmd[i][o] = malloc(sizeof(char) * (tabsize + 1));
		if (data->fullcmd[i][o] == NULL)
			return (1);
		data->fullcmd[i][o][tabsize] = '\0';
		o++;
		j++;
		printf("tabsize = %d\n", tabsize);
		printf("o = %d\n", o);
	}
	return (0);
}

static int	ft_mallocfullcmd(t_data *data)
{
	int		i;
	int		tabtabsize;
	char	**inputsplited;

	i = 0;
	inputsplited = ft_split(data->input, '|', NULL);
	data->fullcmd = malloc(sizeof(char **) * (data->ncmd + 1));
	if (data->fullcmd == NULL)
		return (1);
	data->fullcmd[data->ncmd] = NULL;
	printf("tabtabtabsize = %d\n", data->ncmd);
	while (i <= data->ncmd)
	{
		tabtabsize = ft_tabtabsize(inputsplited, i);
		data->fullcmd[i] = malloc(sizeof(char *) * (tabtabsize + 1));
		if (data->fullcmd[i] == NULL)
			return (1);
		if (ft_malloctabsize(data, inputsplited, tabtabsize, i) == 1)
			return (1);
		i++;
	}
	return (0);
}

int	ft_fullcmd(t_data *data)
{
	if (ft_mallocfullcmd(data) == 1)
	{
		printf("malloc error 2\n");
		return (1);
	}
	return (0);
}
