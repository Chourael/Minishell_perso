/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libstuff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chourael <chourael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:51:09 by chourael          #+#    #+#             */
/*   Updated: 2023/12/12 13:55:38 by chourael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <MOAT.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i <= n && s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	c;
	size_t	i;

	c = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (c);
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (c);
}
