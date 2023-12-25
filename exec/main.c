/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chourael <chourael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:15:23 by chourael          #+#    #+#             */
/*   Updated: 2023/12/25 13:34:13 by chourael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>

int	ft_len(char ***cmds)
{
	int	i;

	i = 0;
	while (cmds[i])
		i++;
	return (i);
}

int	ft_cmds(char ***cmds)
{
	int	id;
	int		pipe1[2];
	int		pipe2[2];
	int saved_stdin = dup(STDIN_FILENO);
	int saved_stdout = dup(STDOUT_FILENO);
	int	i;

	printf("start cmds\n");
	if (pipe(pipe1) == -1 || pipe(pipe2) == -1)
		perror("pipe");
	i = 0;
	while (cmds[i] != NULL)
	{
		if ((id = fork()) == -1)
			perror("fork");
		if (id == 0)
		{
			if (i == 0)
			{
				printf("yo1 i = %d\n", i);
				dup2(pipe1[1], STDOUT_FILENO);
			}
			else if (i > 0 && cmds[i + 1] != NULL)
			{
				if (i % 2 == 1)
				{
					printf("yo2 i = %d\n", i);
					dup2(saved_stdin, STDIN_FILENO);
					if (dup2(pipe1[0], STDIN_FILENO) == - 1)
						perror("dup");
					dup2(saved_stdout, STDOUT_FILENO);
					if (dup2(pipe2[1], STDOUT_FILENO) == - 1)
						perror("dup");
				}
				else
				{
					printf("yo3 i = %d\n", i);;
					dup2(saved_stdin, STDIN_FILENO);
					if (dup2(pipe2[0], STDIN_FILENO) == - 1)
						perror("dup");
					dup2(saved_stdout, STDOUT_FILENO);
					if (dup2(pipe1[1], STDOUT_FILENO) == - 1)
						perror("dup");
				}
			}
			else if (cmds[i + 1] == NULL)
			{
				if (i % 2 == 0)
				{
					printf("yo4 i = %d\n", i);
					dup2(saved_stdin, STDIN_FILENO);
					if (dup2(pipe2[0], STDIN_FILENO) == -1)
						perror("dup");
				}
				else
				{
					printf("yo5\n i = %d", i);
					dup2(saved_stdin, STDIN_FILENO);
					if (dup2(pipe1[0], STDIN_FILENO) == -1)
						perror("dup");
				}
			}
			close(pipe1[0]);
			close(pipe1[1]);
			close(pipe2[0]);
			close(pipe2[1]);
			if (execve(cmds[i][0], cmds[i], NULL) == 1)
				perror("exec");
			return (1);
		}
		else
		{
			waitpid(id, 0, 0);
			i++;
		}
	}
	close(pipe1[0]);
	close(pipe1[1]);
	close(pipe2[0]);
	close(pipe2[1]);
	printf("end cmds\n");
	return (0);
}

int	ft_2cmd(char ***cmds)
{
	int	id;
	int		pipe_id[2];

	printf("start 2cmd\n");
	if (pipe(pipe_id) == -1 )
		perror("pipe");
	if ((id = fork()) == -1)
		perror("fork");
	if (id == 0)
	{
		close(pipe_id[0]);
		dup2(pipe_id[1], STDOUT_FILENO);
		close(pipe_id[1]);
		if (execve(cmds[0][0], cmds[0], NULL) == -1)
		{
			perror("execve");
			return (1);
		}
	}
	wait(NULL);
	if ((id = fork()) == -1)
		perror("fork");
	if (id == 0)
	{
		close(pipe_id[1]);
		dup2(pipe_id[0], STDIN_FILENO);
		close(pipe_id[0]);
		if (execve(cmds[1][0], cmds[1], NULL) == -1)
		{
			perror("execve");
			return (1);
		}
	}
	close(pipe_id[0]);
	close(pipe_id[1]);
	printf("end 2cmd\n");
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

int main()
{
	// char	*cmd[] = {"/usr/bin/ls", "-l", NULL};
	char	*cmd1[] = {"/usr/bin/grep", "test", NULL};
	// char	*cmd2[] = {"/usr/bin/wc", "-l", NULL};
	char	*cmd3[] = {"/usr/bin/echo", "This is a test input", NULL};
	char	*cmd4[] = {"/usr/bin/cat", NULL};
	char	*cmd5[] = {"usr/bin/sed", "s/test/replaced", NULL};
	char	*cmd6[] = {"/usrbin/tee", "output.txt", NULL};
	char	**cmds[] = {cmd3, cmd4, cmd1, cmd5, cmd6, NULL};

	printf("start main\n");
	if (ft_len(cmds) < 1)
		return (0);
	else if (ft_len(cmds) == 1)
		ft_1cmd(cmds);
	else if (ft_len(cmds) == 2)
		ft_2cmd(cmds);
	else if (ft_len(cmds) > 2)
		ft_cmds(cmds);
	printf("end main\n");
}
