/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchour <chchour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:49:11 by chchour           #+#    #+#             */
/*   Updated: 2023/12/15 09:58:42 by chchour          ###   ########.fr       */
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

static int	ft_access(t_data *data)
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

static void	ft_fillarg(t_data *data, int access)
{
	char	**inputsplitted;
	int		i;

	i = 0;
	inputsplitted = ft_split(data->input, ' ', NULL);
	while (inputsplitted[i])
		i++;
	data->cmd = malloc(sizeof(char *) * i + 1);
	data->cmd[i] = NULL;
	i = 1;
	while (inputsplitted[i])
	{
		data->cmd[i] = malloc(sizeof(char) * ft_strlen(inputsplitted[i]) + 1);
		ft_strlcpy(data->cmd[i], inputsplitted[i],
			ft_strlen(inputsplitted[i]) + 1);
		printf("cmd[%d] = %s\n", i, data->cmd[i]);
		printf("input[%d] = %s\n", i, inputsplitted[i]);
		i++;
	}
	data->cmd[0] = malloc(sizeof(char) * ft_strlen(data->allpath[access]) + 1);
	ft_strlcpy(data->cmd[0], data->allpath[access],
		ft_strlen(data->allpath[access]) + 1);
}

static int	ft_exec(t_data *data)
{
	int	id;

	id = fork();
	if (id == 0)
	{
		if (execve(data->cmd[0], data->cmd, NULL) == 1)
		{
			printf("exe didn't work");
			return (1);
		}
	}
	waitpid(id, 0, 0);
	return (0);
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
		printf("cannot access the cmd\n");
		return (1);
	}
	ft_fillarg(data, access);
	ft_exec(data);
	return (0);
}
