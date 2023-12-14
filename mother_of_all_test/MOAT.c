/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MOAT.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchour <chchour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 15:08:48 by chourael          #+#    #+#             */
/*   Updated: 2023/12/14 14:44:24 by chchour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MOAT.h"

void	ft_init(t_data *data)
{
	data->path = NULL;
	data->allpath = NULL;
	data->input = NULL;
	data->cmd = NULL;
	data->cmd_arg = NULL;
	data->ncmd_arg = 1;
}

int	ft_check_access(t_data *data)
{
	int	i;

	i = 0;
	while (data->allpath[i])
	{
		if (access(data->allpath[i], F_OK) == 0)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_makecmd(t_data *data)
{
	int	i;

	i = 1;
	data->cmd_arg = ft_split(data->input, ' ', NULL);
	while (data->cmd_arg[i])
	{
		data->cmd[i] = malloc(sizeof(char) * ft_strlen(data->cmd_arg[i]) + 1);
		ft_strlcpy(data->cmd[i], data->cmd_arg[i], ft_strlen(data->cmd_arg[i]) + 1);
		i++;
	}
}

void	ft_execdacmd(t_data *data)
{
	int	id;

	id = fork();
	if (id == 0)
	{
		if (execve(data->cmd[0], data->cmd, NULL) == 1)
			printf("exe didn't work");
	}
	waitpid(id, 0, 0);
}

int	ft_ifcmd(t_data *data)
{
	int		i;
	int		n_path;

	i = 0;
	n_path = ft_check_access(data);
	if (n_path == -1)
		return (1);
	while (data->input[i])
	{
		if (data->input[i] == ' ')
			data->ncmd_arg++;
		i++;
	}
	data->cmd = malloc(sizeof(char *) * data->ncmd_arg + 1);
	data->cmd[data->ncmd_arg] = NULL;
	data->cmd[0] = malloc(sizeof(char) * ft_strlen(data->input) + 1);
	ft_strlcpy(data->cmd[0], data->allpath[n_path], ft_strlen(data->allpath[n_path]) + 1);
	ft_makecmd(data);
	ft_execdacmd(data);
	return (0);
}
int	ft_notcmd(char *input)
{
	int	len;

	len = ft_strlen(input);
	if (len == 3)
	{
		if (ft_strncmp(input, "die", len) == 0)
			return (1);
	}
	else if (len == 5)
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

void	ft_makeinputc(char *inputc, char *input)
{
	int	i;

	i = 0;
	inputc[0] = '/';
	while (input[i])
	{
		inputc[i + 1] = input[i];
		i++;
	}
	inputc[i + 1] = '\0';
}

void	ft_interactif(t_data *data)
{
	char	*inputc;

	printf("Hello, this is chourashell version 0.8\n");
	while (1)
	{
		data->input = readline("chourashell :");
		inputc = malloc(sizeof(char) * ft_strlen(data->input) + 2);
		ft_makeinputc(inputc, data->input);
		data->allpath = ft_split(data->path, ':', inputc);
		ft_ifcmd(data);
		if (ft_notcmd(data->input) == 1)
			return ;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	ft_init(&data);
	data.path = getenv("PATH");
	if (argc == 1)
		ft_interactif(&data);
	else if (argc > 1)
	{
		printf("argv[1]%s\n", argv[1]);
		printf("non interactif mod under construction\n");
	}
}