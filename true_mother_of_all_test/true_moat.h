/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   true_moat.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chourael <chourael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:55:43 by chchour           #+#    #+#             */
/*   Updated: 2023/12/20 18:03:11 by chourael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRUE_MOAT_H
# define TRUE_MOAT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_data
{
	int		ncmd;
	char	*input;
	char	*path;
	char	**cmds;
	char	**allpath;
	char	**cmdpath;
	char	***fullcmd;
}				t_data;

//libstuff.c
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcpy(char *dst, char *src, size_t size);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);
//ft_mega_split.c
char	**ft_split(char const *s, char c, char *input);
//cmds.c
int		ft_cmds(t_data *data);
//help.c
void	ft_help(void);
//paths.c
int		ft_paths(t_data *data);
//init.c
int		ft_initcmdpath(t_data *data);
int		ft_initcmds(t_data *data);

#endif