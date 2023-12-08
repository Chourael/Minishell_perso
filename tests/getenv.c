/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchour <chchour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:20:08 by chchour           #+#    #+#             */
/*   Updated: 2023/12/08 15:48:42 by chchour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	char	*epath;

	epath = NULL;
	epath = getenv("LOGNAME");
	printf("%s\n", epath);
}
