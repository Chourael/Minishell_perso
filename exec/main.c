/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chourael <chourael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:15:23 by chourael          #+#    #+#             */
/*   Updated: 2023/12/22 17:16:58 by chourael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>

int main()
{
	int		fd[2];
	int		file;
	int		id;
	int		i;
	char	*cmd[] = {"/usr/bin/ls", "-l", NULL};
	char	*cmd1[] = {"/usr/bin/grep", "chourael", NULL};
	char	**cmds[] = {cmd, cmd1, NULL};

	i = 0;
	while (cmds[i] != NULL)
	{
		file = open("exec.txt", O_WRONLY | O_TRUNC | O_CREAT, S_IRWXU);
		if (pipe(fd) == -1)
		{
			perror("pipe");
			return (1);
		}
		if ((id = fork()) == -1)
		{
			perror("fork");
			return (1);
		}
		if (id == 0)
		{
			if (i == 0)
			{
				close(fd[0]);
				close(fd[1]);
				dup2(file, STDOUT_FILENO);
				close(file);
			}
			else if (i > 0 && cmds[i + 1] != NULL)
			{
				close(fd[0]);
				close(fd[1]);
				dup2(file, STDIN_FILENO);
				dup2(file, STDOUT_FILENO);
				close(file);
			}
			else
			{
				close(fd[0]);
				close(fd[1]);
				dup2(file, STDIN_FILENO);
			}
			if (execve(cmds[i][0], cmds[i], NULL) == 1)
			{
				perror("execve");
				return (1);
			}
		}
		else
		{
			close(fd[0]);
			close(fd[1]);
			close(file);
			waitpid(id, NULL, 0);
			i++;
		}
	}
}
