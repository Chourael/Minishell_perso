/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec-main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chourael <chourael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 20:42:41 by chchour           #+#    #+#             */
/*   Updated: 2023/12/29 13:19:38 by chourael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	len(char ***cmds)
{
	int	i;

	i = 0;
	while (cmds[i])
		i++;
	return (i);
}

int	ft_callall(char ***cmds, int **pipes, int stdout, int *redirect)
{
	int	i;

	if (ft_firstcmd(cmds[0], pipes[0], stdout, redirect) == -1)
		return (-1);
	if ((i = ft_middlecmd(cmds, pipes, stdout)) == -1)
		return (-1);
	if (ft_lastcmd(cmds, pipes, i, redirect) == -1)
		return (-1);
	return (0);
}

int	ft_exec(char ***cmds, int *redirect)
{
	int	**pipes;
	int	stdout;

	printf("start ft_exec\n");
	stdout = dup(STDOUT_FILENO);
	pipes = ft_makepipes(len(cmds));
	if (len(cmds) == 1)
	{
		if (ft_1cmd(cmds) == -1)
			return (-1);
		return (0);
	}
	if (ft_callall(cmds, pipes, stdout, redirect) == -1)
		return (-1);
	ft_closepipes(pipes, len(cmds));
	ft_freepipes(pipes, len(cmds));
	printf("end ft_exec\n");
	return(0);
}

int	main(void)
{
	// char	*ls[] = {"/usr/bin/ls", "-l", NULL};
	char	*grep[] = {"/usr/bin/grep", "replaced", NULL};
	char	*wc[] = {"/usr/bin/wc", "-l", NULL};
	// char	*echo[] = {"/usr/bin/echo", "This is a test input", NULL};
	char	*cat[] = {"/usr/bin/cat", "exec-main.c", NULL};
	char	*sed[] = {"/usr/bin/sed", "s/if/replaced/", NULL};
	// char	*tee[] = {"/usr/bin/tee", "output.txt", NULL};
	char	**cmds[] = {cat, sed, grep, wc, NULL};
	int		*redirect;

	redirect = malloc(sizeof(int) * 2);
	redirect[0] = 0;
	redirect[1] = 0;
	redirect[0] = open("input.txt", O_RDONLY);
	// redirect[1] = open("output.txt", O_WRONLY);
	if (ft_exec(cmds, redirect) == -1)
		return (1);
	free(redirect);
	return (0);
}
