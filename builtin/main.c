/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chourael <chourael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:36:07 by chourael          #+#    #+#             */
/*   Updated: 2024/01/03 18:23:52 by chourael         ###   ########.fr       */
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

void	export_unset_env(char **env)
{
	printf("start test1\n");
	ft_env(env);
	ft_export(env, "THEBEST=Chourael");
	ft_env(env);
	ft_export(env, "THEBEST=Marianne");
	ft_env(env);
	printf("start test2\n");
	ft_export(env, "yo=mister white");
	ft_env(env);
	printf("end ests\n");
}

char	**makeenv(char **env)
{
	env[0] = malloc(sizeof(char) * 26);
	env[0] = "GAMES=totalwarwarhammer2\0";
	env[1] = malloc(sizeof(char) * 28);
	env[1] = "CHOURAEL=emperorofhumanity\0";
	env[2] = malloc(sizeof(char) * 23);
	env[2] = "MARIANNE=profesionnal\0";
	env[3] = malloc(sizeof(char) * 11);
	env[3] = "THEBEST=nana\0";
	env[4] = NULL;
	return (env);
}

int	main()
{
	char	**env;

	env = malloc(sizeof(char *) * 5);
	env = makeenv(env);
	// echotest();
	// cdtest();
	// pwdtest();
	export_unset_env(env);
	return (0);
}
