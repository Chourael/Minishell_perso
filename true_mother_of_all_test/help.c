/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chourael <chourael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:44:01 by chourael          #+#    #+#             */
/*   Updated: 2023/12/19 11:18:29 by chourael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "true_moat.h"

void	ft_help(void)
{
	printf("here is the list of what you can do here :\n");
	printf("                1: if you want to exit the program type die");
	printf(", don't worry it is probably not painful for the program\n");
	printf("                2: you can type \"cmd (n cmd separated");
	printf(" with pipe)\" to execute a cmd on the standard output\n");
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
