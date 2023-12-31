/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.C                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chourael <chourael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 11:59:40 by chourael          #+#    #+#             */
/*   Updated: 2023/12/31 13:03:49 by chourael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

//la cmd export prend 1 seul argument, l'arg doit etre dans cette forme VARNAME=VALUE ou VARNAME="VALUE VALUE" sinon export ne fait rien
//fonctionne meme si VARNAME n'est pas en maj
//si une variable existe déjà export va la modifier et si elle n'existe pas elle vas la créé
//exemple export yeah=yeahyeah la variable yeah n'existe pas alors yeah vas etre créé et etre = a yeahyeah
//export yeah=nono la variable existe déja donc on export change juste la valeur de la variable donc yeahyeah par nono

static void	ft_make_addit(char **env, char *arg)
{
	int	i;

	while(env[i])
	{
		if (env[i] == NULL)
		{
			env[i] = malloc(sizeof(char) * (ft_strlen(arg) + 1));
			ft_strlcpy(env[i], arg);
		}
	}
}

//take what is befor the = to make the variable name (exemple if arg is THEBEST=chourael,marnianne then variable will be "THEBEST")
static char	*ft_get_var(char *arg)
{
	char *variable;
	int	i;

	i = 0;
	while(arg[i] != '=')
		i++;
	variable = malloc(sizeof(char) * (i + 1));
	i = 0;
	while(arg[i] != '=')
	{
		variable[i] = arg[i];
		i++;
	}
	variable[i] = '\0';
}

void	ft_export(char **env, char *arg)
{
	char *variable;

	variable = ft_get_var(arg);
	if (getenv(variable) == NULL)
		ft_make_addit(env, arg);
}
