/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mega_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chourael <chourael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:20:00 by jofrache          #+#    #+#             */
/*   Updated: 2023/12/19 12:17:10 by chourael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "true_moat.h"

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

static void	ft_tabhelper(char *tab, char *cmd, int i, int j)
{
	if (cmd)
	{
		tab[i] = '/';
		i++;
		while (cmd[j] != ' ' && cmd[j] != '\0')
		{
			tab[i] = cmd[j];
			i++;
			j++;
		}
	}
	tab[i] = '\0';
}

static int	ft_len(char *cmd)
{
	int	len;

	if (cmd)
		len = ft_strlen(cmd);
	else
		len = 0;
	return (len);
}

static char	*ft_tab(char const *s, char c, int *o, char *cmd)
{
	int		i;
	int		j;
	int		size;
	int		len_cmd;
	char	*tab;

	i = 0;
	j = 0;
	size = 0;
	while (s[(*o)] == c && s[(*o)])
		(*o)++;
	while (s[(*o) + size] != c && s[(*o) + size])
		size++;
	len_cmd = ft_len(cmd);
	tab = malloc(sizeof(char) * (size + len_cmd + 2));
	if (!tab)
		return (NULL);
	while (i < size)
	{
		tab[i] = s[(*o)];
		i++;
		(*o)++;
	}
	ft_tabhelper(tab, cmd, i, j);
	return (tab);
}

char	**ft_split(char const *s, char c, char *cmd)
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
		tabtab[i] = ft_tab(s, c, &o, cmd);
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
