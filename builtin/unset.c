/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chourael <chourael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 12:16:51 by chourael          #+#    #+#             */
/*   Updated: 2024/01/07 14:10:54 by chourael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	ft_len(char **env)
{
	int	i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}

int	ft_malloccpy(char **envcpy, char **env, char **arg)
{
	int	i;
	int	o;
	int	j;

	i = 0;
	j = 0;
	while (env[i])
	{
		o = 0;
		while (arg[o])
		{
			if (ft_strncmp(env[i], arg[o], ft_strlen(arg[o])) == 0)
				i++;
			o++;
		}
		if (env[i] != NULL)
			envcpy[j] = malloc(sizeof(char) * (ft_strlen(env[i]) + 1));
		else if (env[i] == NULL)
			break ;
		if (envcpy[j] == NULL)
			return (-1);
		j++;
		i++;
	}
	return (0);
}

char	**ft_unset(char **env, char **arg, int i, int j)
{
	int		o;
	char	**envcpy;

	envcpy = malloc(sizeof(char *) * (ft_len(env) + 1));
	ft_malloccpy(envcpy, env, arg);
	while (env[i])
	{
		o = 0;
		while (arg[o])
		{
			if (ft_strncmp(env[i], arg[o], ft_strlen(arg[o])) == 0)
				i++;
			o++;
		}
		if (env[i] == NULL)
			break ;
		ft_strlcpy(envcpy[j], env[i], (ft_strlen(env[i]) + 1));
		i++;
		j++;
	}
	envcpy[j] = NULL;
	ft_freeenv(env);
	return (envcpy);
}
