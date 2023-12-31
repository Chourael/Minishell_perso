/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chourael <chourael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:36:07 by chourael          #+#    #+#             */
/*   Updated: 2023/12/31 16:49:55 by chourael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	echotest(void)
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
}

void	cdtest(void)
{
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
}

void	pwdtest(void)
{
	printf("start pwd test\n");
	ft_pwd();
	printf("end pwd test\n\n");
}

void	exporttest(char **env)
{
	printf("start export test1\n");
	printf("%s \n", getenv("THEBEST"));
	ft_export(env, "THEBEST=Chourael");
	printf("%s \n", getenv("THEBEST"));
	ft_export(env, "THEBEST=Marianne");
	printf("%s \n", getenv("THEBEST"));
	ft_export(env, "THEBEST=Chourael&Marianne");
	printf("%s \n", getenv("THEBEST"));
	printf("start export test2\n");
	printf("%s \n", getenv("yo"));
	ft_export(env, "yo=mister white");
	printf("%s \n", getenv("yo"));
	printf("end export tests\n");
}

int	main())
{
	echotest();
	cdtest();
	pwdtest();
	// exporttest();
}
