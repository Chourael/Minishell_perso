/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chourael <chourael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 17:19:40 by chourael          #+#    #+#             */
/*   Updated: 2023/12/30 16:45:57 by chourael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

// # include "../Marianne_libft/libft.a"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

//echo.c
void	ft_echo(char *str);

//cd.c
int		ft_cd(char *str);

#endif