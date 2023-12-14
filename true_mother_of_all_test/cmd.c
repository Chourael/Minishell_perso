/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchour <chchour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:49:11 by chchour           #+#    #+#             */
/*   Updated: 2023/12/14 21:02:13 by chchour          ###   ########.fr       */
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
			break;
		}
		i++;
	}
	cmd = malloc(sizeof(char) * len + 1);
	len = 0;
	i++;
	printf("input = %s\n", input);
	while (input[i] <= 'z' && input[i] >= 'a')
	{
		input[i++] = cmd[len++];
		printf("cmd[%d] = %c\n", len - 1, cmd[len - 1]);
		printf("input[%d] = %c\n", i - 1, input[i - 1]);
	}
	cmd[len] = '\0';
	printf("cmd = %s\n", cmd);
	return (cmd);
}

int	ft_cmd(t_data *data)
{
	char	*path;
	char	*cmd;

	path = NULL;
	cmd = NULL;
	cmd = ft_fillcmd(data->input, cmd);
	path = getenv("PATH");
	data->allpath = ft_split(path, ':', cmd);
	return (0);
}
