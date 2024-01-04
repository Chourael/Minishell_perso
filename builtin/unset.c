/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchour <chchour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 12:16:51 by chourael          #+#    #+#             */
/*   Updated: 2024/01/04 13:46:07 by chchour          ###   ########.fr       */
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

int	ft_malloccpy(char **envcpy, char **env, char **arg)
{
	int	i;
	int	o;
	int	j;

	i = 0;
	j = 0;
	while (env[i])
	{
		// printf("i = %d \n", i);
		o = 0;
		// printf("1env[%d] = %s \n", i, env[i]);
		while (arg[o])
		{
			// printf("arg[%d] = %s && env[%d] = %s \n", o, arg[o], i, env[i]);
			if (ft_strncmp(env[i], arg[o], ft_strlen(arg[o])) == 0)
				i++;
			o++;
		}
		// printf("2env[%d] = %s \n", i, env[i]);
		if (env[i] != NULL)
		{
			// printf("len env[%d] = %zu \n", i, ft_strlen(env[i]));
			envcpy[j] = malloc(sizeof(char) * (ft_strlen(env[i]) + 1));
		}
		else if (env[i] == NULL)
			break;
		if (envcpy[j] == NULL)
			return (-1);
		j++;
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
	// printf("len = %d \n", ft_len(arg));
	ft_malloccpy(envcpy, env, arg);
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
			// printf("env[%d] = %s && len = %zu \n", i, env[i], ft_strlen(env[i]));
			ft_strlcpy(envcpy[j], env[i], (ft_strlen(env[i]) + 1));
			// printf("envcpy[%d] = %s && len = %zu \n", j, envcpy[j], ft_strlen(envcpy[j]));
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
	return (envcpy);
}
