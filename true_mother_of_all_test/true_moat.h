/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   true_moat.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchour <chchour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:55:43 by chchour           #+#    #+#             */
/*   Updated: 2023/12/14 20:47:26 by chchour          ###   ########.fr       */
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
	char	*input;
	char	**allpath;
}				t_data;

//libstuff.c
size_t	ft_strlcpy(char *dst, char *src, size_t size);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strlen(char *str);
//ft_mega_split.c
char	**ft_split(char const *s, char c, char *input);
//cmd.c
int		ft_cmd(t_data *data);

#endif