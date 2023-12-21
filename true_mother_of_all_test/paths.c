/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchour <chchour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:25:52 by chourael          #+#    #+#             */
/*   Updated: 2023/12/21 12:36:31 by chchour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "true_moat.h"

static void	ft_cpy(t_data *data, int path, int cmd)
{
	int	i;

	i = 0;
	while (data->allpath[path][i])
	{
		data->cmdpath[cmd][i] = data->allpath[path][i];
		i++;
	}
	data->cmdpath[cmd][i] = '\0';
}

int	ft_paths(t_data *data)
{
	int	i;
	int	o;

	o = 0;
	if (ft_initcmdpath(data) == 1)
		return (1);
	while (data->cmds[o])
	{
		i = 0;
		data->allpath = ft_split(data->path, ':', data->cmds[o]);
		while (data->allpath[i])
		{
			if (access(data->allpath[i], F_OK) == 0)
			{
				data->cmdpath[o] = malloc(sizeof(char)
						* (ft_strlen(data->allpath[i]) + 1));
				ft_cpy(data, i, o);
				o++;
				break ;
			}
			i++;
			if (data->allpath[i] == NULL)
			{
				printf("acces error\n");
				return (1);
			}
		}
		free(data->allpath);
	}
	return (0);
}
