/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libstuff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chourael <chourael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:51:09 by chourael          #+#    #+#             */
/*   Updated: 2023/12/20 11:57:00 by chourael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <true_moat.h>

static char	*ft_norm(void)
{
	char	*s3;

	s3 = malloc(sizeof(char) * 1);
	if (!s3)
		return (NULL);
	s3[0] = '\0';
	return (s3);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	int		c1;
	int		c2;
	int		size;

	size = ft_strlen(s1) + ft_strlen(s2);
	if (ft_strlen(s1) < 1 && ft_strlen(s2) < 1)
	{
		s3 = ft_norm ();
		return (s3);
	}
	s3 = malloc(sizeof(char) * (size + 1));
	if (!s3)
		return (NULL);
	c1 = -1;
	while (s1[++c1] != '\0')
		s3[c1] = s1[c1];
	c2 = -1;
	while (s2[++c2] != '\0')
	{
		s3[c1] = s2[c2];
		c1++;
	}
	s3[c1] = '\0';
	return (s3);
}

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
