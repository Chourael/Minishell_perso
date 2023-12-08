/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testgetcwp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchour <chchour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:18:02 by chchour           #+#    #+#             */
/*   Updated: 2023/12/08 11:25:15 by chchour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	char	*pwd = NULL;

	pwd = getcwd(NULL, 0);
	printf("pwd: %s\n", pwd);
	return (0);
}
