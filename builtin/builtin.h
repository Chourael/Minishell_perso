/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chourael <chourael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 17:19:40 by chourael          #+#    #+#             */
/*   Updated: 2024/01/03 16:34:56 by chourael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "../Marianne_libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

//echo.c
void	ft_echo(char *str);

//cd.c
int		ft_cd(char *str);

//pwd.c
void	ft_pwd(void);

//export.c
void	ft_export(char **env, char *arg);

//unset.c
int		ft_unset(char **env, char **arg);

//env.c
void	ft_env(char **env);
#endif