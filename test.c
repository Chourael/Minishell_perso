/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchour <chchour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:03:52 by chchour           #+#    #+#             */
/*   Updated: 2023/12/05 14:06:12 by chchour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(int argc, char **argv, char **enve)
{
	int	i;

	i = 0;
	printf("argc = %d\n", argc);
	while (argv[i])
	{
		printf("%s\n", argv[i]);
		i++;
	}
	printf("\n\n");
	i = 0;
	while (enve[i])
	{
		printf("%s\n", enve[i]);
		i++;
	}
}
