/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MOAT.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chourael <chourael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 16:53:52 by chourael          #+#    #+#             */
/*   Updated: 2023/12/12 13:55:47 by chourael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOAT_H
# define MOAT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_data
{
	char 	*path;
	char 	**allpath;
	char 	*input;
	char 	**cmd;
	char 	**cmd_arg;
	int		ncmd_arg;
}				t_data;

//MOAT
int			ft_check_access(t_data *data);
void		ft_interactif(t_data *data);
void		ft_makecmd(t_data *data);
int			ft_notcmd(char *input);
void		ft_init(t_data *data);
int			if_cmd(t_data *data);
//ft_mega_split
char		**ft_split(char const *s, char c, char *input);
//libstuff
int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strlcpy(char *dst, char *src, size_t size);
int			ft_strlen(char *str);;

#endif