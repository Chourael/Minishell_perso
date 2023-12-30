/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfenve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chourael <chourael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:24:58 by chchour           #+#    #+#             */
/*   Updated: 2023/12/30 13:07:09 by chourael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(int argc, char **argv, char **env)
{
	int	i;

	if (argc == 342)
		return (0);
	if (argv[0][0] == 'w')
		return (0);
	i = 0;
	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
}
