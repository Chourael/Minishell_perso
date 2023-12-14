/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchour <chchour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:57:05 by chchour           #+#    #+#             */
/*   Updated: 2023/12/14 18:51:37 by chchour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "true_moat.h"

static void	ft_init(t_data *data)
{
	data->input = NULL;
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
	}
}
