/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chourael <chourael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 12:16:51 by chourael          #+#    #+#             */
/*   Updated: 2024/01/03 17:30:26 by chourael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static int	ft_len(char **env)
{
	int i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}

static int	ft_malloccpy(char **envcpy, char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		envcpy[i] = malloc(sizeof(char) * (ft_strlen(env[i]) + 1));
		if (envcpy[i] == NULL)
			return (-1);
		i++;
	}
	return (0);
}

//unset * don't work on bash so it sould not work here
int	ft_unset(char **env, char **arg)
{
	int	i;
	int	o;
	int	j;
	char	**envcpy;

	i = 0;
	j = 0;
	envcpy = malloc(sizeof(char *) * (ft_len(env) + 1));
	ft_malloccpy(envcpy, env);
	while (env[i])
	{
		o = 0;
		while (arg[o])
		{
			if (env[i] == arg[o])
				i++;
			o++;
		}
		ft_strlcpy(envcpy[j], env[i], ft_strlen(env[i]));
		i++;
		j++;
	}
	return (0);
}
