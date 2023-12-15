/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchour <chchour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:49:11 by chchour           #+#    #+#             */
/*   Updated: 2023/12/15 07:38:34 by chchour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "true_moat.h"

static char	*ft_fillcmd(char *input, char *cmd)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (input[i])
	{
		if (input[i] == ' ')
		{
			while (input[i] <= 'z' && input[i] >= 'a')
			{
				len++;
				i++;
			}
			break ;
		}
		i++;
	}
	cmd = malloc(sizeof(char) * len + 1);
	len = 1;
	i++;
	while (input[i] <= 'z' && input[i] >= 'a')
		cmd[len++] = input[i++];
	cmd[len] = '\0';
	return (cmd);
}

int	ft_access(t_data *data)
{
	int	i;

	i = 0;
	while (data->allpath[i])
	{
		if (access(data->allpath[i], F_OK) == 0)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_fillarg(t_data *data)
{
	int	i;
	int	o;
	int	size;

	i = 0;
	size = 1;
	while (data->input[i])
	{
		if (data->input[i] = ' ')
			size++;
		i++;	
	}
	data->cmd = malloc(sizeof(char *) * size + 1);
	i = 1;
	o = 0;
	while (data->cmd[i])
	{
		
	}
}

int	ft_exec(t_data *data)
{
	
}

int	ft_cmd(t_data *data)
{
	char	*path;
	char	*cmd;
	int		access;

	path = NULL;
	cmd = NULL;
	cmd = ft_fillcmd(data->input, cmd);
	cmd[0] = '/';
	path = getenv("PATH");
	data->allpath = ft_split(path, ':', cmd);
	access = ft_access(data);
	if (access == -1)
	{
		printf("cannot access the cmd\n")
		return (1);
	}
	ft_fillarg(data);
	ft_exec(data, access);
	return (0);
}
