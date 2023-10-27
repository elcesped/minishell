/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elcesped <elcesped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:43:33 by mvachera          #+#    #+#             */
/*   Updated: 2023/10/27 15:10:35 by elcesped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//modif fonction : ajout d un element dans le prototype 
//+ ajout de quote[i] dans la fonction
void	sort_token(char **tab, int *token, int i, int *quote)

{
	while (tab[i])
	{
		if (ft_strcmp(tab[i], "|") == 0 && quote[i] == NO_QUOTE)
			token[i] = PIPE;
		else if (ft_strcmp(tab[i], "<") == 0 && quote[i] == NO_QUOTE)
			token[i] = CHEVRON_G;
		else if (ft_strcmp(tab[i], ">") == 0 && quote[i] == NO_QUOTE)
			token[i] = CHEVRON_D;
		else if (ft_strcmp(tab[i], "<<") == 0 && quote[i] == NO_QUOTE)
			token[i] = D_CHEVRON_G;
		else if (ft_strcmp(tab[i], ">>") == 0 && quote[i] == NO_QUOTE)
			token[i] = D_CHEVRON_D;
		else if (check_builtin(tab[i]) == 1)
			token[i] = BUILTIN;
		else if (i != 0 && token[i - 1] == D_CHEVRON_G)
			token[i] = HERE_DOC;
		else
			sort_token2(tab, token, i, quote);
		i++;
	}
}

//modif fonction : ajout d un element dans le prototype 
//+ ajout de quote[i] dans la fonction
void	sort_token2(char **tab, int *token, int i, int *quote)
{
	if (i != 0 && token[i - 1] == CHEVRON_G)
			token[i] = IN_FILES;
	else if (i != 0 && (token[i - 1] == CHEVRON_D
			|| token[i - 1] == D_CHEVRON_D))
			token[i] = OUT_FILES;
	else if (i != 0 && (token[i - 1] == COMMAND || token[i - 1] == ARGUMENT
			|| token[i -1] == BUILTIN) && (is_meta_string(tab[i]) == 0
			|| quote[i] == QUOTE))
			token[i] = ARGUMENT;
	else if (is_meta_string(tab[i]) == 0)
			token[i] = COMMAND;
	else if (tab[i][0] == '$') //ajout
		token[i] = VARIABLE; //ajout
	else
			token[i] = RANDOM;
}

int	check_builtin(char *str)
{
	if (ft_strcmp(str, "echo") == 0)
		return (1);
	else if (ft_strcmp(str, "echo -n") == 0)
		return (1);
	else if (ft_strcmp(str, "cd") == 0)
		return (1);
	else if (ft_strcmp(str, "pwd") == 0)
		return (1);
	else if (ft_strcmp(str, "export") == 0)
		return (1);
	else if (ft_strcmp(str, "unset") == 0)
		return (1);
	else if (ft_strcmp(str, "env") == 0)
		return (1);
	else if (ft_strcmp(str, "exit") == 0)
		return (1);
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] > s2[i] || s1[i] < s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	free_map(char **map_a_parser)
{
	int	i;

	i = 0;
	while (map_a_parser[i])
	{
		free(map_a_parser[i]);
		i++;
	}
	free(map_a_parser);
}
