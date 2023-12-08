/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testchdir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchour <chchour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:20:42 by chchour           #+#    #+#             */
/*   Updated: 2023/12/08 11:51:13 by chchour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int	ft_comp(char *str)
{
	if (str[0] == 'd')
	{
		if (str[1] == 'e')
		{
			if (str[2] == 'l')
			{
				if (str[3] == 'e')
				{
					if (str[4] == 't')
					{
						if (str[5] == 'e')
							return (1);
					}
				}
			}
		}
	}
	return (0);
}

int	main(int argc, char ** argv)
{
	char	*pwd = NULL;
	int		fd1;
	int		fd2;

	if (argc < 2 || argc > 3)
		return (0);
	if (argc == 3 && ft_comp(argv[2]) == 1)
	{
		pwd = getcwd(NULL, 0);
		printf("deleting %s in %s\n", argv[1], pwd);
		unlink(argv[1]);
		chdir("/mnt/nfs/homes/chchour/Desktop/all_project/Minishell/minishell_perso/chdirtestfolder");
		pwd = getcwd(NULL, 0);
		printf("deleting %s in %s\n", argv[1], pwd);
		unlink(argv[1]);
		return (0);
	}
	pwd = getcwd(NULL, 0);
	printf("creating %s in %s\n", argv[1], pwd);
	fd1 = open(argv[1], O_RDWR | O_CREAT, S_IRWXU);
	chdir("/mnt/nfs/homes/chchour/Desktop/all_project/Minishell/minishell_perso/chdirtestfolder");
	pwd = getcwd(NULL, 0);
	printf("creating %s in %s\n", argv[1], pwd);
	fd2 = open(argv[1], O_RDWR | O_CREAT, S_IRWXU);
	return (0);
}
