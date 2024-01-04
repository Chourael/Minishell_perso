/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchour <chchour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 12:16:51 by chourael          #+#    #+#             */
/*   Updated: 2024/01/04 12:44:04 by chchour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	ft_len(char **env)
{
	int i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}

int	ft_malloccpy(char **envcpy, char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		printf("i = %d \n", i);
		envcpy[i] = malloc(sizeof(char) * (ft_strlen(env[i]) + 1));
		if (envcpy[i] == NULL)
			return (-1);
		i++;
	}
	return (0);
}

//unset * don't work on bash so it sould not work here
char	**ft_unset(char **env, char **arg)
{
	int		i;
	int		o;
	int		j;
	char	**envcpy;

	i = 0;
	j = 0;
	envcpy = malloc(sizeof(char *) * (ft_len(env) + 1));
	ft_malloccpy(envcpy, env);
	while (env[i])
	{
		// printf("i = %d \n", i);
		// printf("env[%d] = %s \n", i, env[i]);
		o = 0;
		while (arg[o])
		{
			// printf("arg[%d] = %s && env[%d] = %s \n", o, arg[o], i, env[i]);
			if (ft_strncmp(env[i], arg[o], ft_strlen(arg[o])) == 0)
				i++;
			o++;
		}
		if (env[i] != NULL)
		{
			ft_strlcpy(envcpy[j], env[i], (ft_strlen(env[i]) + 1));
			// printf("envcpy[%d] = %s \n", j, envcpy[j]);
			// printf("env[%d] = %s \n", i, env[i]);
		}
		else if (env[i] == NULL)
		{
			break;
		}
		i++;
		j++;
	}
	envcpy[j] = NULL;
	ft_freeenv(env);
	free(env[1]);
	return (envcpy);
}
