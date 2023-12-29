/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chourael <chourael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:40:41 by chourael          #+#    #+#             */
/*   Updated: 2023/12/29 17:31:51 by chourael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	ft_echo(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while(str[i] == ' ' || str[i] == '\"' || str[i] == '\'')
		i++;
	if (str[i] == '-' && str[i + 1] == 'n' && str[i + 2] == ' ')
	{
			n = 1;
			i += 3;
	}
	while(str[i])
	{
		if (str[i] != '\"' && str[i] != '\'')
			write(1, &str[i], 1);
		i++;
	}
	if (n == 0)
		write(1, "\n", 1);
}