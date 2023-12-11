/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MOAT.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chourael <chourael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 16:53:52 by chourael          #+#    #+#             */
/*   Updated: 2023/12/11 17:28:27 by chourael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOAT_H
# define MOAT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

//MOAT
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		ft_interactif(char *paths);
int			if_cmd(char **all_path);
//ft_mega_split
char		**ft_split(char const *s, char c, char *input);
int			ft_strlen(char *str);

#endif