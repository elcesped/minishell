/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 20:41:17 by mvachera          #+#    #+#             */
/*   Updated: 2023/10/23 18:13:39 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*str_johnny(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*dst;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	dst = ft_calloc(sizeof(char), (len + 1));
	if (!dst)
		return (NULL);
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dst[i] = s2[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst);
}

int	ft_count(char const *s, char c)
{
	int	i;
	int	count;
	int	m;

	i = 0;
	count = 0;
	m = 0;
	while (s[i])
	{
		if (s[i] != c && m == 0)
		{
			count++;
			m = 1;
		}
		if (s[i] == c)
			m = 0;
		i++;
	}
	return (count);
}

int	nb_cmd(t_pipex *pipex)
{
	int	i;
	int	l;

	i = 0;
	l = 0;
	while (pipex->tab[i])
	{
		if (pipex->token[i] == COMMAND || pipex->token[i] == BUILTIN)
			l++;
		i++;
	}
	return (l);
}
