/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MOAT.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chourael <chourael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 15:08:48 by chourael          #+#    #+#             */
/*   Updated: 2023/12/10 17:08:05 by chourael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MOAT.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i <= n && s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_exe()
{
	if (access(argv[1], F_OK) != -1
		&& access(argv[1], R_OK) != -1 && data->fdin > -1)
		ft_exe(data, enve);
}

void	ft_interactif(char *paths)
{
	char *user_input;
	char **all_path;

	all_path = ft_split(paths, ':');
	while (1)
	{
		user_input = readline("chourashell :");
		ft_
	}
}

int	main(int argc, char **argv, char **enve)
{
	char *paths;

	paths = NULL;
	paths = getenv("PATH");
	if (argc == 1)
		ft__interactif(paths);
	else if (argc > 1)
	{
		
	}
}