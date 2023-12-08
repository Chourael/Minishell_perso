/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testreadline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchour <chchour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:07:05 by chchour           #+#    #+#             */
/*   Updated: 2023/12/08 11:25:11 by chchour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

int	main(void)
{
	char	*user_input = NULL;

	user_input = readline("input here: ");
	printf("user input = %s\n", user_input);
	free (user_input);
}
