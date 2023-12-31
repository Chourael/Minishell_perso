/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testsignaux2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chourael <chourael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 18:02:40 by chourael          #+#    #+#             */
/*   Updated: 2023/12/31 18:07:53 by chourael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>


volatile sig_atomic_t	received_signal = 0;

void sh(int signum)
{
	received_signal = signum;
}

int	main(void)
{
	int	pid;
	int	i;

	i = 0;
	signal(SIGINT, sh);
	signal(SIGTERM, sh);
	pid = fork();
	if (pid == -1)
	{
		perror("pid");
		return (1);
	}
	if (pid == 0)
	{
		while (1)
		{
			printf("pid = %d \n", getpid());
			usleep(1000000);
			if (received_signal != 0)
			{
				printf("Received signal: %d\n", received_signal);
				received_signal = 0;
			}
		}
	}
	else
	{
		sleep(1);
		wait(NULL);
		printf("%d milisecond passed after child \n", i);
	}
}