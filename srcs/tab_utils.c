/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elcesped <elcesped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:11:40 by mvachera          #+#    #+#             */
/*   Updated: 2023/10/25 19:12:16 by elcesped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_tab(char **tab, int count)
{
	int	i;

	i = 0;
	(void) count;
	if (ft_strcmp(tab[0], "|") == 0)
		return (ft_printf("syntax error near unexpected token `|'\n"), 0);
	while (tab[i])
	{
		if (tab[i][0] == '\'' || tab[i][0] == '\"')
			handle_quotes(tab[i]);
		i++;
	}
	return (1);
}

int	stop_str(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (i > 0)
	{
		if (str[i] != ' ' && (str[i] < 9 || str[i] > 13))
			break ;
		i--;
	}
	return (i);
}

int	is_metacaractere(char c)
{
	if (c == '|')
		return (1);
	else if (c == '<')
		return (1);
	else if (c == '>')
		return (1);
	else if (c == ' ' || (c >= 9 && c <= 13))
		return (2);
	return (0);
}

char	*cpy(char *str, int i, int j)
{
	char	*line;
	int		k;

	k = 0;
	line = malloc(sizeof(char) * (j - i + 1));
	if (!line)
		return (NULL);
	while (i < j)
	{
		if (is_metacaractere(str[i]) == 2)
		{
			line[k] = ' ';
			k++;
			while (is_metacaractere(str[i]) == 2)
				i++;
		}
		line[k] = str[i];
		i++;
		k++;
	}
	line[k] = '\0';
	return (line);
}
