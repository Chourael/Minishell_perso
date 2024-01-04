/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchour <chchour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:36:07 by chourael          #+#    #+#             */
/*   Updated: 2024/01/04 13:24:01 by chchour          ###   ########.fr       */
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

void	ft_freeenv(char **env)
{
	int	i;

	i = 0;
	while(env[i])
	{
		// printf("freeing env[%d] = %s \n", i, env[i]);
		free(env[i]);
		i++;
	}
	// printf("freeing env \n");
	free(env);
}

void	fillit(char *env, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		env[i] = str[i];
		i++;
	}
	env[i] = '\0';
}

char	**makeenv(char **env)
{
	env[0] = malloc(sizeof(char) * 26);
	fillit(env[0], "GAMES=totalwarwarhammer2");
	env[1] = malloc(sizeof(char) * 28);
	fillit(env[1], "CHOURAEL=emperorofhumanity");
	env[2] = malloc(sizeof(char) * 23);
	fillit(env[2], "MARIANNE=profesionnal");
	env[3] = malloc(sizeof(char) * 13);
	fillit(env[3], "THEBEST=nana");
	env[4] = NULL;
	return (env);
}

void	export_unset_env(char **env)
{
	printf("start test replace\n");
	ft_env(env);
	printf("\n\n");
	env = ft_export(env, "THEBEST=Chourael");
	ft_env(env);
	printf("\n\n");
	env = ft_export(env, "THEBEST=Marianne");
	ft_env(env);
	printf("\n\n");
	printf("start test add\n");
	env = ft_export(env, "yo=mister white");
	ft_env(env);
	printf("\n\n");
	printf("start test unset\n");
	char *arg[] = {"yo", NULL};
	env = ft_unset(env, arg);
	ft_env(env);
	printf("\n\n");
	printf("start test multiple arg unset\n");
	char *args[] = {"CHOURAEL", "MARIANNE", NULL};
	env = ft_unset(env, args);
	ft_env(env);
	printf("\n\n");
	printf("end tests\n");
	ft_freeenv(env);
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
