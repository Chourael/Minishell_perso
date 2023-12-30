/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chourael <chourael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 11:25:17 by chourael          #+#    #+#             */
/*   Updated: 2023/12/30 16:51:28 by chourael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	ft_cd(char *str)
{
	char	*pwd;;

	pwd = NULL;
	if (str == NULL || str[0] == '\0')
	{
		if (chdir(getenv("HOME")) == -1)
		{
			perror("chdir 1");
			return (-1);
		}
	}
	else if (chdir(str) == -1)
	{
		perror("chdir 0");
		return (-1);
	}
	pwd = getcwd(NULL, 0);
	printf("working directory : %s\n", pwd);
	return (0);
}
