/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchour <chchour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 20:42:41 by chchour           #+#    #+#             */
/*   Updated: 2023/12/26 22:40:01 by chchour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>

int	len(char ***cmds)
{
	int	i;

	i = 0;
	while (cmds[i])
		i++;
	return (i);
}

void ft_closepipes(int	**pipes, int size)
{
	int	i;

	printf("start closepipes\n");
	i = 0;
	while (i < size)
	{
		close(pipes[i][0]);
		close(pipes[i][1]);
		i++;
	}
	printf("end closepipes\n");
}

int	**ft_mallocpipes(int size)
{
	int	i;
	int	**pipes;

	printf("start mallocpipes\n");
	i = 0;
	pipes = malloc(sizeof(int *) * size);
	if (pipes == NULL)
	{
		printf("pipes error\n");
		return (NULL);
	}
	while (i < size)
	{	
		pipes[i] = malloc(sizeof(int) * 2);
		if (pipes[i] == NULL)
		{
			printf("pipes[%d] error\n", i);
			return (NULL);
		}
		i++;
	}
	printf("end mallocpipes\n");
	return (pipes);
}

int	ft_firstcmd(char **cmd, int	*firstpipe, int stdout)
{
	int	id;

	printf("start firstcmd\n");
	if ((id = fork()) == -1)
	{
		perror("fork");
		return (-1);
	}
	if (id == 0)
	{
		close(firstpipe[0]);
		dup2(firstpipe[1], STDOUT_FILENO);
		close(firstpipe[1]);
		if (execve(cmd[0], cmd, NULL) == -1)
		{
			dup2(stdout, STDOUT_FILENO);
			perror("exec");
			return (-1);
		}
	}
	else
		wait(NULL);
	printf("end firstcmd\n");
	return (0);
}

int	ft_lastcmd(char ***cmds, int **pipes, int i)
{
	int	id;

	printf("start lastcmd\n");
	if ((id = fork()) == -1)
	{
		perror("fork");
		return (-1);
	}
	if (id == 0)
	{
		dup2(pipes[i - 1][0], STDIN_FILENO);
		ft_closepipes(pipes, len(cmds));
		if (execve(cmds[i][0], cmds[i], NULL) == -1)
		{
			perror("exec");
			return (-1);
		}
	}
	else
	{
		printf("end last cmd\n");
		return (0);
	}
	return (0);
}

int	ft_1cmd(char ***cmds)
{
	int	id;

	printf("start 1cmd\n");
	if ((id = fork()) == -1)
		perror("fork");
	if (id == 0)
	{
		if (execve(cmds[0][0], cmds[0], NULL) == -1)
		{
			perror("execve");
			return (1);
		}
	}
	printf("end 1cmd\n");
	return (0);
}

int	ft_exec(char ***cmds)
{
	int	i;
	int	**pipes;
	int	id;
	int	stdout;

	printf("start ft_exec\n");
	i = 0;
	stdout = dup(STDOUT_FILENO);
	pipes = ft_mallocpipes(len(cmds));
	if (pipes == NULL)
		return (-1);
	while (i < len(cmds))
	{
		if (pipe(pipes[i]) == -1)
		{
			perror("pipes");
			return (-1);
		}
		i++;
	}
	if (len(cmds) == 1)
	{
		if (ft_1cmd(cmds) == -1)
			return (-1);
		return (0);
	}
	if (ft_firstcmd(cmds[0], pipes[0], stdout) == -1)
		return (-1);
	i = 1;
	while(cmds[i + 1] != NULL && cmds[i])
	{
		printf("start while %d\n", i);
		if ((id = fork()) == -1)
			perror("fork");
		if (id == 0)
		{
			dup2(pipes[i - 1][0], STDIN_FILENO);
			dup2(pipes[i][1], STDOUT_FILENO);
			ft_closepipes(pipes, len(cmds));
			if (execve(cmds[i][0], cmds[i], NULL) == -1)
			{
				dup2(stdout, STDOUT_FILENO);
				perror("exec");
				return (-1);
			}
			return (0);
		}
		else
		{
			i++;
		}
	}
	if (ft_lastcmd(cmds, pipes, i) == -1)
		return (-1);
	ft_closepipes(pipes, len(cmds));
	printf("end ft_exec\n");
	return (0);
}

int	main(void)
{
	// char	*cmd[] = {"/usr/bin/ls", "-l", NULL};
	char	*cmd1[] = {"/usr/bin/grep", "if", NULL};
	char	*cmd2[] = {"/usr/bin/wc", "-l", NULL};
	// char	*cmd3[] = {"/usr/bin/echo", "This is a test input", NULL};
	char	*cmd4[] = {"/usr/bin/cat", "main.c", NULL};
	// char	*cmd5[] = {"usr/bin/sed", "s/test/replaced", NULL};
	char	*cmd6[] = {"/usr/bin/tee", "output.txt", NULL};
	char	**cmds[] = {cmd4, cmd1, cmd2, cmd6, NULL};

	if (ft_exec(cmds) == -1)
		return (1);
	return (0);
}