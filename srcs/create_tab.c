/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elcesped <elcesped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:42:31 by mvachera          #+#    #+#             */
/*   Updated: 2023/10/26 19:37:00 by elcesped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	create_tab(char *str, t_pipex *pipex)
{
	int	count;
//	int	i; suppression

	pipex->quote = 0;
	if (signal(SIGINT, &ft_interrupt) == 0)
		return ;
	count_nb_tab(str, &count);
	if (count == 0)
		return ;
	pipex->tab = malloc(sizeof(char *) * (count + 1));
	if (!pipex->tab)
		return ;
	extract_to_tab(pipex->tab, str, count);
	if (!pipex->tab)
		return ;
	if (check_quotes(pipex->tab, pipex, count) != 0)//modif ici + ds la fonction
		return ;
//	i = 0; suppression
	pipex->token = malloc(sizeof(int) * count);
	if (!pipex->token)
		return (free_map(pipex->tab));
	sort_token(pipex->tab, pipex->token, 0, pipex->quote);// modif dans la fonction + i 
	if (check_random(pipex, count) != 0) // modif ici
		return (free_memory(pipex));
	free(pipex->quote); //ajout
	if (handle_builtin(pipex, str) == 0)
		main_pipex(str, pipex);
}

void	count_nb_tab(char *str, int *count)
{
	int	i;
	int	j;

	i = 0;
	(*count) = 0;
	while (str[i] && i <= stop_str(str))
	{
		while ((str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)) && str[i])
			i++;
		j = i;
		if (is_metacaractere(str[i]) == 1)
		{
			(*count)++;
			while (is_metacaractere(str[j]) == 1 && str[j])
				j++;
		}
		else if (is_metacaractere(str[i]) == 0)
		{
			(*count)++;
			letters_arg(str, &j);
		}
		i = j;
	}
}

void	extract_to_tab(char **tab, char *str, int count)
{
	int		i;
	int		j;
	int		l;
	char	*line;

	i = 0;
	l = 0;
	while (str[i] && l < count)
	{
		extract_to_tab2(str, &i, &j);
		line = cpy(str, i, j);
		tab[l] = ft_strdup(line);
		if (!tab[l])
		{
			while (l >= 0)
				free(tab[--l]);
			free(tab);
			return ;
		}
		free(line);
		l++;
		i = j;
	}
	tab[l] = 0;
}

void	extract_to_tab2(char *str, int *i, int *j)
{
	while ((str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13)) && str[*i])
		(*i)++;
	*j = *i;
	if (is_metacaractere(str[*i]) == 1)
	{
		while (is_metacaractere(str[*j]) == 1 && str[*j])
			(*j)++;
	}
	else if (is_metacaractere(str[*i]) == 0)
		letters_arg(str, j);
}

void	letters_arg(char *str, int *j)
{
	int	tmp;

	tmp = 0;
	while (is_metacaractere(str[*j]) == 0 && str[*j])
		(*j)++;
	if (is_metacaractere(str[*j]) == 2)
	{
		tmp = *j;
		while (is_metacaractere(str[tmp]) == 2 && str[tmp])
			tmp++;
		if (str[tmp] == '-')
		{
			*j = tmp;
			while (is_metacaractere(str[*j]) == 0 && str[*j])
				(*j)++;
		}
	}
}
