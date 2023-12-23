/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chourael <chourael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:15:23 by chourael          #+#    #+#             */
/*   Updated: 2023/12/23 12:13:17 by chourael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>

int main()
{
	int		file;
	int		file2;
	int		id;
	int		i;
	char	*cmd[] = {"/usr/bin/ls", "-l", NULL};
	char	*cmd1[] = {"/usr/bin/grep", "chourael", NULL};
	char	*cmd2[] = {"/usr/bin/wc", "-l", NULL};
	char	**cmds[] = {cmd, cmd1, cmd2, NULL};

	i = 0;
	while (cmds[i] != NULL)
	{
		file = open("exec.txt", O_WRONLY | O_TRUNC);
		file2 = open("exec2.txt", O_WRONLY | O_TRUNC);
		if (file == -1 || file2 == -1)
			perror("open");
		if ((id = fork()) == -1)
		{
			perror("fork");
			return (1);
		}
		if (id == 0)
		{
			if (i == 0)
			{
				printf("yo1\n");
				dup2(file, STDOUT_FILENO);
			}
			else if (i > 0 && cmds[i + 1] != NULL)
			{
				if (i % 2 == 1)
				{
					printf("yo2\n");
					if (dup2(file, STDIN_FILENO) == - 1)
						perror("dup");
					if (dup2(file2, STDOUT_FILENO) == - 1)
						perror("dup");
				}
				else
				{
					printf("yo3\n");
					if (dup2(file, STDOUT_FILENO) == - 1)
						perror("dup");
					if (dup2(file2, STDIN_FILENO) == - 1)
						perror("dup");
				}
			}
			else if (cmds[i + 1] == NULL)
			{
				if (i % 2 == 0)
				{
					printf("yo3\n");
					if (dup2(file2, STDIN_FILENO) == -1)
						perror("dup");
				}
				else
				{
					printf("yo4\n");
					if (dup2(file, STDIN_FILENO) == -1)
						perror("dup");
				}
			}
			close(file);
			close(file2);
			if (execve(cmds[i][0], cmds[i], NULL) == -1)
			{
				perror("execve");
				return (1);
			}
		}
		else
		{
			close(file);
			close(file2);
			waitpid(id, NULL, 0);
			i++;
		}
	}
}
