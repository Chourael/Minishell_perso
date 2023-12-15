/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchour <chchour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:57:05 by chchour           #+#    #+#             */
/*   Updated: 2023/12/15 11:11:24 by chchour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "true_moat.h"

static void	ft_init(t_data *data)
{
	data->input = NULL;
}

static void	ft_help(void)
{
	printf("here is the list of what you can do here :\n");
	printf("                1: if you want to exit the program type die");
	printf(", don't worry it is probably not painful for the program\n");
	printf("                2: you can type \"cmd (any cmd)\" ");
	printf("to execute a cmd on the standard output\n");
	printf("                3: you can type <> (file1 any number of cmd");
	printf(" file2) it will behive like < file1 cmd1 | cmd2 > file2\n");
	printf("                4: you can type < (file any number of cmd");
	printf(") it will behive like < file cmd1 | cmd2 \n");
	printf("                5: you can type > (any number of cmd");
	printf(" file) it will behive like cmd1 | cmd2 > file\n");
	printf("                6: finaly you can try typing any word and ");
	printf("maybe it will do something😉\n");
	printf("when using multiple cmd all must be separated with \'|\'\n");
}

int	main(void)
{
	t_data	data;

	ft_init(&data);
	printf("\033[31;1mhello and welcome to chourashell!\033[0m\n");
	printf("type help for useful info\n\n");
	while (1)
	{
		data.input = readline("chourashell :");
		if (ft_strlen(data.input) == 3 && ft_strncmp(data.input, "die", 3) == 0)
			return (0);
		else if (ft_strlen(data.input) == 3
			&& ft_strncmp(data.input, "DIE", 3) == 0)
			return (0);
		else if (ft_strlen(data.input) > 2
			&& ft_strncmp(data.input, "cmd", 3) == 0)
			ft_cmd(&data);
		else if (ft_strlen(data.input) == 4
			&& ft_strncmp(data.input, "help", 4) == 0)
			ft_help();
	}
}
