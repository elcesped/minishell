/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elcesped <elcesped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:37:58 by mvachera          #+#    #+#             */
/*   Updated: 2023/10/26 19:33:06 by elcesped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//modif
int	check_quotes(char **tab, t_pipex *pipex, int count)
{
	int		i;
	char	*tmp;

	i = 0;
	pipex->quote = 0; //ajout
	pipex->quote = malloc(sizeof(int) * (count)); //ajout
	if (!pipex->quote) //ajout
		return (-1); //ajout
	while (tab[i])
	{
		pipex->quote[i] = NO_QUOTE; //ajout
		if (tab[i][0] == '\'' || tab[i][0] == '\"')
		{
			pipex->quote[i] = QUOTE; //ajout
			handle_quotes(tab[i]);
			tmp = handle_quotes2(tab[i]);
			free(tab[i]);
			tab[i] = tmp;
		}
		i++;
	}
	return (0);
}

void	handle_quotes(char *str)
{
	char	c;
	int		i;

	i = 0;
	c = str[i++];
	while (str[i] && str[i] != c)
	{
		str[i] = -str[i];
		i++;
	}
}

char	*handle_quotes2(char *str)
{
	char	*dest;
	int		len;
	int		i;
	int		j;

	len = 0;
	while (str[len + 1])
		len++;
	dest = malloc(sizeof(char) * len);
	if (!dest)
		return (NULL);
	j = 0;
	i = 1;
	while (j < len - 1)
	{
		dest[j] = str[i];
		j++;
		i++;
	}
	dest[j] = '\0';
	return (dest);
}
