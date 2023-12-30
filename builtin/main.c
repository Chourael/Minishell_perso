/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chourael <chourael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:36:07 by chourael          #+#    #+#             */
/*   Updated: 2023/12/30 17:14:10 by chourael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	main(void)
{
	printf("start echo test\n");
	ft_echo("                                                      -n yo ocuyasu");
	ft_echo("                         """"            -n yo ocuyasu");
	ft_echo("                   ''''''''''''                      -n yo ocuyasu");
	ft_echo("              yo ocuyasu");
	ft_echo("       \"yo\"\"mister\"\"white\"");
	ft_echo("            mister white\n\n\n");
	ft_echo("    -nefiejfiejfiejfiejf");
	ft_echo("yo");
	ft_echo("\"\"     -n yoy");
	printf("end echo test\n\n");

	printf("start cd test\n");
	printf("start working directory : %s\n", getcwd(NULL, 0));
	ft_cd("..");
	printf("start working directory : %s\n", getcwd(NULL, 0));
	ft_cd("exec_npipe");
	printf("start working directory : %s\n", getcwd(NULL, 0));
	ft_cd("../mother_of_all_test");
	printf("start working directory : %s\n", getcwd(NULL, 0));
	ft_cd("/home/chourael/Bureau/projet42/pipex/Libft");
	printf("start working directory : %s\n", getcwd(NULL, 0));
	ft_cd("../../../other");
	printf("start working directory : %s\n", getcwd(NULL, 0));
	ft_cd("error");
	printf("start working directory : %s\n", getcwd(NULL, 0));
	ft_cd(".");
	printf("start working directory : %s\n", getcwd(NULL, 0));
	ft_cd("/");
	printf("start working directory : %s\n", getcwd(NULL, 0));
	ft_cd(NULL);
	printf("start working directory : %s\n", getcwd(NULL, 0));
	ft_cd("/home/chourael/Bureau/projet42/minishell/Minishell_perso/builtin");
	printf("start working directory : %s\n", getcwd(NULL, 0));
	ft_cd("");
	printf("start working directory : %s\n", getcwd(NULL, 0));
	printf("end cd test\n\n");

	printf("start pwd test\n");
	ft_pwd();
	printf("end pwd test\n\n");
}
