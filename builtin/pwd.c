/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chourael <chourael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 17:10:48 by chourael          #+#    #+#             */
/*   Updated: 2024/01/07 11:02:07 by chourael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtin.h>

void	ft_pwd(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		// printf("env[%d] = %s \n", i, env[i]);
		if (ft_strncmp(env[i], "PWD", 3) == 0)
		{
			printf("%s \n", env[i]);
			return ;
		}
		i++;
	}
	printf("\n\n");
}
