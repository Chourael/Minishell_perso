/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chourael <chourael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 14:17:34 by chourael          #+#    #+#             */
/*   Updated: 2023/12/28 16:33:11 by chourael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <fcntl.h>
# include <sys/stat.h>

//exec-main.c
int		len(char ***cmds);
int		ft_1cmd(char ***cmds);
int		ft_exec(char ***cmds);
//middlecmd.c
int		ft_middlecmd(char ***cmds, int **pipes, int stdout);
//firstcmd.c
int		ft_firstcmd(char **cmd, int	*firstpipe, int stdout);
//lastcmd.c
int		ft_lastcmd(char ***cmds, int **pipes, int i);
//malloc-close_pipes.c
int		**ft_mallocpipes(int size);
void	ft_closepipes(int	**pipes, int size);

#endif