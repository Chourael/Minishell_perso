/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchour <chchour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:09:09 by chourael          #+#    #+#             */
/*   Updated: 2023/12/21 16:28:29 by chchour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "true_moat.h"

static void	ft_ncmd(t_data *data)
{
	int	i;

	i = 0;
	while (data->input[i])
	{
		if (data->input[i] == '|')
			data->ncmd++;
		i++;
	}
}

static void	ft_fillcmds(t_data *data)
{
	int	i;
	int	o;
	int	j;

	i = 1;
	o = 0;
	while (data->input[i - 1] != ' ' && data->input[i])
		i++;
	while (data->input[i])
	{
		j = 0;
		while (data->input[i] != ' ' && data->input[i])
			data->cmds[o][j++] = data->input[i++];
		o++;
		while (data->input[i - 2] != '|' && data->input[i])
			i++;
	}
}

static int	ft_malloccmds(t_data *data)
{
	int	i;
	int	o;
	int	size;

	i = 1;
	o = 0;
	while (data->input[i - 1] != ' ' && data->input[i] != '\0')
		i++;
	while (data->input[i])
	{
		size = 1;
		while (data->input[i] && data->input[i++] != ' ')
			size++;
		data->cmds[o] = malloc(sizeof(char) * (size + 1));
		if (data->cmds[o] == NULL)
		{
			printf("malloc error 1\n");
			return (1);
		}
		data->cmds[o][size - 1] = '\0';
		o++;
		while (data->input[i - 2] != '|' && data->input[i])
			i++;
	}
	return (0);
}

int	ft_cmds(t_data *data)
{
	ft_ncmd(data);
	if (ft_initcmds(data) == 1)
		return (1);
	if (ft_malloccmds(data) == 1)
		return (1);
	ft_fillcmds(data);
	int	i = 0;
	while (i <= data->ncmd)
	{
		printf("cmds[%d] = %s\n", i, data->cmds[i]);
		i++;
	}
	if (ft_paths(data) == 1)
		return (1);
	if (ft_fullcmd(data) == 1)
		return (1);
	return (0);
}
