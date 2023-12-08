/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testDIR.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchour <chchour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 12:13:53 by chchour           #+#    #+#             */
/*   Updated: 2023/12/08 12:17:31 by chchour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>

int	main(void)
{
	DIR				*dir;
	struct dirent	*entry;

	dir = opendir(".");

	if (dir == NULL)
	{
		perror("Error opening directory");
		return (1);
	}
	while (1)
	{
		entry = readdir(dir);
		if (entry == NULL)
			break ;
		printf("%s\n", entry->d_name);
	}
	closedir(dir);
}
