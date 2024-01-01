/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchour <chchour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 14:17:34 by chourael          #+#    #+#             */
/*   Updated: 2024/01/01 15:32:05 by chchour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "../Marianne_libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <fcntl.h>
# include <sys/stat.h>

typedef struct s_exec
{
	int		**pipes;
	int		*redirect;
	int		stdout;
}				t_exec;

//exec-main.c
int		ft_callall(t_exec *exec, char ***cmds, char *heardoc);
int		ft_exec(t_exec *exec, char ***cmds, char *heardoc);
int		len(char ***cmds);

//1cmd.c
int		ft_1cmd(t_exec *exec, char ***cmds, char *heardoc);

//middlecmd.c
int		ft_middlecmd(t_exec *exec, char ***cmds);

//firstcmd.c
int		ft_firstcmd(t_exec *exec, char ***cmds, char *heardoc);

//lastcmd.c
int		ft_lastcmd(t_exec *exec, char ***cmds, int i);

//malloc-close_pipes.c
void	ft_closepipes(int	**pipes, int size);
void	ft_freepipes(int **pipes, int size);
int		**ft_mallocpipes(int size);
int		**ft_makepipes(int size);

#endif