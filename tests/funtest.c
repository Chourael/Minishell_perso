/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funtest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chourael <chourael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 12:21:57 by chchour           #+#    #+#             */
/*   Updated: 2023/12/10 17:21:48 by chourael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
//#include <readline/readline.h>
// #include <readline/history.h>

int	input_len(char *input)
{
	int	i;

	i = 0;
	while (input[i])
		i++;
	return (i);
}

int	verif_input(char *input)
{
	if ((input_len(input) == 5) && input[0] == 'd' && input[1] == 'e'
		&& input[2] == 'a' && input[3] == 't' && input[4] == 'h')
	{
		printf("congratulation ! you killed everyone\n");
		return (1);
	}
	else if ((input_len(input) == 5) && input[0] == 'i' && input[1] == 'm'
		&& input[2] == 'a' && input[3] == 'n' && input[4] == 'e')
		printf("imane is the best spy in the world (you may die now that you have this information)\n");
	else if ((input_len(input) == 8) && input[0] == 'c' && input[1] == 'h'
		&& input[2] == 'o' && input[3] == 'u' && input[4] == 'r'
		&& input[5] == 'a' && input[6] == 'e' && input[7] == 'l')
		printf("chourael is the god emperor of humanity\n");
	else if ((input_len(input) == 10) && input[0] == 'm' && input[1] == 'i'
		&& input[2] == 'n' && input[3] == 'i' && input[4] == 's'
		&& input[5] == 'h' && input[6] == 'e' && input[7] == 'l'
		&& input[8] == 'l' && input[9] == 'e')
		printf("minishell is a mininighmare for 42 students\n");
	else
	{
		printf("you wrote %s\n", input);
		printf("try some names that you know !\n");
		printf("to end the program enter \"death\"\n");
	}
	return (0);
}

int	main(void)
{
	char	*user_input;

	user_input = NULL;
	while (1)
	{
		user_input = readline("input here : ");
		if (verif_input(user_input) == 1)
		{
			free(user_input);
			return (0);
		}
	}
}
