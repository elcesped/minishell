/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elcesped <elcesped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:11:40 by mvachera          #+#    #+#             */
/*   Updated: 2023/10/26 19:36:34 by elcesped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_random(t_pipex *pipex, int count)
{
	int	i;

	i = 0;
	if (ft_strcmp(pipex->tab[0], "|") == 0)
		return (ft_printf("syntax error near unexpected token `|'\n"), 1);
	while (pipex->tab[i])
	{
		if (pipex->token[i] == RANDOM && pipex->quote[i] == NO_QUOTE) //modif
			return (ft_handle_size(pipex->tab[i]));
		if (pipex->tab[i + 1] && is_meta_string(pipex->tab[i]) == 1
			&& is_meta_string(pipex->tab[i + 1]) == 1 && pipex->quote[i] == NO_QUOTE) //modif
		{
			if (ft_strlen(pipex->tab[i + 1]) == 1)
				return (print_error_syntax(pipex->tab[i + 1][0], 0, 1), 2);
			else
				return (print_error_syntax(pipex->tab[i + 1][0],
					pipex->tab[i + 1][1], 2), 2);
		}
		i++;
	}
	 if (pipex->token[count - 1] >= 0 && pipex->token[count - 1] <= 4 && pipex->quote[count - 1] == NO_QUOTE) //modif
		 return (ft_printf("syntax error near unexpected token `newline'\n"), 1);
	return (0);
}

int	is_meta_string(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_metacaractere(str[i]) == 1)
			return (1);
		i++;
	}
	return (0);
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
