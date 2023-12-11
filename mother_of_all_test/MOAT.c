/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MOAT.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chourael <chourael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 15:08:48 by chourael          #+#    #+#             */
/*   Updated: 2023/12/11 18:05:07 by chourael         ###   ########.fr       */
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

int	ft_ifcmd(char **all_path)
{
	int	i;

	i = 0;
	while ((all_path[i]))
	{
		if (access(all_path[i], F_OK) == 0)
			execve(all_path[i], all_path, NULL);
		i++;
	}
	return (0);
}
int	ft_notcmd(char *input)
{
	int	len;

	len = ft_strlen(input);
	if (len == 5)
	{
		if (ft_strncmp(input, "death", len) == 0)
		{
			printf("Congratulation ! you killed the program\n");
			return (1);
		}
		else if (ft_strncmp(input, "imane", len) == 0)
			printf("imane is the best spy in the world (you may die now that you have this information)\n");
	}
	else if (len == 8)
	{
		if (ft_strncmp(input, "chourael", len) == 0)
			printf("chourael is the god emperor of humanity\n");
	}
	else if (len == 9)
	{
		if (ft_strncmp(input, "minishell", len) == 0)
			printf("minishell is a mininighmare for 42 students\n");
	}
	return (0);
}

void	ft_interactif(char *paths)
{
	char *input;
	char **all_path;

	printf("Hello, you are in the prepreprepreprealpha version of a part of minishell\n");
	while (1)
	{
		input = readline("chourashell :");
		all_path = ft_split(paths, ':', input);
		ft_ifcmd(all_path);
		if (ft_notcmd(input) == 1)
			return ;
	}
}

int	main(int argc, char **argv)
{
	char *paths;

	paths = NULL;
	paths = getenv("PATH");
	if (argc == 1)
		ft_interactif(paths);
	else if (argc > 1)
	{
		printf("argv[1]%s\n", argv[1]);
		printf("non interactif mod under construction\n");
	}
}