/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execexec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchour <chchour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:58:04 by chchour           #+#    #+#             */
/*   Updated: 2024/01/04 14:02:44 by chchour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main()
{
	char	*exec[] = {"exec", NULL};
	execve("exec", exec, NULL);
}