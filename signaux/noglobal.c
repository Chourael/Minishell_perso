/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   noglobal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchour <chchour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 17:01:15 by chourael          #+#    #+#             */
/*   Updated: 2024/01/01 12:23:16 by chchour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>

void	die()
{
	printf("you got me you son of a B \n\n\njust kidding i am still imortal \n");
}

void	imortal()
{
	printf("i am imortal\n");
}

int	main(void)
{
	int	pid;
	int	i;

	i = 0;
	signal(SIGINT, imortal);
	signal(SIGTERM, die);
	pid = fork();
	if (pid == -1)
	{
		perror("pid");
		return (1);
	}
	if (pid == 0)
	{
		while(i < 100000)
		{
			printf("%d milisecond passed in %d \n", i, getpid());
			usleep(1000000);
			i += 1000;
		}
	}
	else
	{
		sleep(1);
		wait(NULL);
		printf("%d milisecond passed after child \n", i);
	}
}