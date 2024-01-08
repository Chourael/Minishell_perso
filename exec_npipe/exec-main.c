/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec-main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chourael <chourael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 20:42:41 by chchour           #+#    #+#             */
/*   Updated: 2024/01/08 13:46:10 by chourael         ###   ########.fr       */
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

int	ft_callall(t_exec *exec, char ***cmds, char *heardoc)
{
	int	i;

	if (ft_firstcmd(exec, cmds, heardoc) == -1)
		return (-1);
	if ((i = ft_middlecmd(exec, cmds)) == -1)
		return (-1);
	printf("3 i = %d \n", i);
	if (ft_lastcmd(exec, cmds, i) == -1)
		return (-1);
	return (0);
}

int	ft_exec(t_exec *exec, char ***cmds, char *heardoc)
{
	printf("start ft_exec\n");
	exec->pipes = ft_makepipes((len(cmds) + 1));
	if (len(cmds) == 1)
	{
		printf("starting 1cmd \n");
		if (ft_1cmd(exec, cmds, heardoc) == -1)
			return (-1);
		ft_closepipes(exec->pipes, (len(cmds) + 1));
		ft_freepipes(exec->pipes, (len(cmds) + 1));
		printf("end ft_exec\n");
		return (0);
	}
	if (ft_callall(exec, cmds, heardoc) == -1)
		return (-1);
	ft_closepipes(exec->pipes, (len(cmds) + 1));
	ft_freepipes(exec->pipes, (len(cmds) + 1));
	printf("end ft_exec\n");
	return(0);
}

int	main(void)
{
	// char	*ls[] = {"/usr/bin/ls", "-l", NULL};
	// char	*grep[] = {"/usr/bin/grep", "misterwhite", NULL};
	char	*wc[] = {"/usr/bin/wc", "-l", NULL};
	char	*echo[] = {"/usr/bin/echo", "This is a test input", NULL};
	// char	*cat[] = {"/usr/bin/cat", "exec-main.c", NULL};
	// char	*sed[] = {"/usr/bin/sed", "s/occuyasu/misterwhite/", NULL};
	// char	*tee[] = {"/usr/bin/tee", "output.txt", NULL};
	char	**cmds[] = {echo, wc, NULL};
	// char	heardoc[] = "yo occuyasu\nnot display\ni have the goods occuyasu\noccuyasu\nFIN";
	char	*heardoc = NULL;
	t_exec	exec;

	exec.stdout = dup(STDOUT_FILENO);
	exec.redirect = malloc(sizeof(int) * 2);
	exec.redirect[0] = 0;
	exec.redirect[1] = 0;
	// exec.redirect[0] = open("input.txt", O_RDONLY);
	// exec.redirect[1] = open("output.txt", O_WRONLY);
	if (ft_exec(&exec, cmds, heardoc) == -1)
		return (1);
	free(exec.redirect);
	return (0);
}
