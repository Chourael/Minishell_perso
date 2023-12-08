/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfenve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchour <chchour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:24:58 by chchour           #+#    #+#             */
/*   Updated: 2023/12/08 15:27:30 by chchour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(int argc, char **argv, char **enve)
{
	int	i;

	if (argc == 342)
		return (0);
	if (argv[0][0] == 'w')
		return (0);
	i = 0;
	while (enve[i])
	{
		printf("%s\n", enve[i]);
		i++;
	}
}
