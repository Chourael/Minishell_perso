/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec-main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chourael <chourael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 20:42:41 by chchour           #+#    #+#             */
/*   Updated: 2023/12/28 18:16:15 by chourael         ###   ########.fr       */
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

int	callall(char ***cmds, int **pipes, int redirect)
{
	int	i;

	if (ft_firstcmd(cmds[0], pipes[0], stdout, redirect) == -1)
		return (-1);
	if ((i = ft_middlecmd(cmds, pipes, stdout)) == -1)
		return (-1);
	if (ft_lastcmd(cmds, pipes, i) == -1)
		return (-1);
}

int	ft_exec(char ***cmds, int redirect)
{
	int	**pipes;
	int	stdout;
	int	i;

	printf("start ft_exec\n");
	stdout = dup(STDOUT_FILENO);
	pipes = ft_makepipes(len(cmds));
	if (len(cmds) == 1)
	{
		if (ft_1cmd(cmds) == -1)
			return (-1);
		return (0);
	}
	if (ft_callall(cmds, pipes, redirect) == -1)
		return (-1);
	ft_closepipes(pipes, len(cmds));
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

	if (ft_exec(cmds, 0) == -1)
		return (1);
	return (0);
}
