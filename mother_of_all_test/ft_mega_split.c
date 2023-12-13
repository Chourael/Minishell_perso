/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mega_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chourael <chourael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:20:00 by jofrache          #+#    #+#             */
/*   Updated: 2023/12/13 10:32:42 by chourael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MOAT.h"

static int	ft_counttab(char const *s, char c)
{
	int	i;
	int	ntab;

	i = 0;
	ntab = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			ntab++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (ntab);
}

static char	*ft_tab(char const *s, char c, int *o, char *input)
{
	int		i;
	int		size;
	int		len_input;
	int		j;
	char	*tab;

	i = 0;
	j = 0;
	size = 0;
	while (s[(*o)] == c && s[(*o)])
		(*o)++;
	while (s[(*o) + size] != c && s[(*o) + size])
		size++;
	if (input)
		len_input = ft_strlen(input);
	else
		len_input = 0;
	tab = malloc(sizeof(char) * (size + len_input + 1));
	if (!tab)
		return (NULL);
	while (i < size)
	{
		tab[i] = s[(*o)];
		i++;
		(*o)++;
	}
	if (input)
	{
		while (input[j] != ' ' && input[j] != '\0')
		{
			tab[i] = input[j];
			i++;
			j++;
		}
	}
	tab[i] = '\0';
	return (tab);
}

char	**ft_split(char const *s, char c, char *input)
{
	int		i;
	int		o;
	char	**tabtab;

	i = -1;
	o = 0;
	if (!s)
		return (NULL);
	tabtab = malloc(sizeof(char *) * (ft_counttab(s, c) + 1));
	if (!tabtab)
		return (NULL);
	while (++i < ft_counttab(s, c))
	{
		tabtab[i] = ft_tab(s, c, &o, input);
		if (!tabtab[i])
		{
			while (i >= 0)
			{
				free(tabtab[i--]);
			}
			return (NULL);
		}
	}
	return (tabtab[i] = 0, tabtab);
}
