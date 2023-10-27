/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elcesped <elcesped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:42:31 by mvachera          #+#    #+#             */
/*   Updated: 2023/10/25 19:25:50 by elcesped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_error_syntax(char c, char d, int i)
{
	if (c == '|')
		i = 1;
	if (i == 1)
		ft_printf("syntax error near unexpected token `%c'\n", c);
	if (i == 2)
		ft_printf("syntax error near unexpected token `%c%c'\n", c, d);
	if (i == 3)
		ft_printf("syntax error near unexpected token `newline'\n");
}

int	ft_handle_size(char *tab)
{
	int	i;

	i = 0;
	if (ft_strlen(tab) == 3)
	{
		if (ft_strncmp("<<<", tab, 3) == 0)
			return (1);
		return (print_error_syntax(tab[2], 0, 1), 2);
	}
	else if (ft_strlen(tab) > 3)
	{
		if (ft_strncmp("<<", tab, 2) == 0)
		{
			if (tab[2] == '|' || tab[3] == '|')
				return (print_error_syntax('|', 0, 1), 2);
		}
		if (ft_strncmp("<<<", tab, 3) == 0)
		{
			if (tab[4] == '|')
				return (print_error_syntax(tab[3], 0, 1), 2);
			return (print_error_syntax(tab[3], tab[4], 2), 2);
		}
		return (print_error_syntax(tab[2], tab[3], 2), 2);
	}
	return (print_error_syntax(tab[0], 0, 1), 2);
}

int	ft_check_random(char **tab, int *token)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (token[i] == RANDOM && is_metacaractere(tab[i][0]) == 1)
			return (ft_handle_size(tab[i]));
		else if (tab[i + 1] && token[i] >= 0 && token[i] <= 4
			&& is_metacaractere(tab[i + 1][0]) == 1)
		{
			if (ft_strlen(tab[i + 1]) == 1)
				return (print_error_syntax(tab[i + 1][0], 0, 1), 2);
			return (print_error_syntax(tab[i + 1][0], tab[i + 1][1], 2), 2);
		}
		if (tab[i + 1] == NULL && is_metacaractere(tab[i][0]) == 1
			&& tab[i][0] != '|')
			return (print_error_syntax(0, 0, 3), 2);
		i++;
	}
	return (0);
}

void	create_tab(char *str, t_pipex *pipex)
{
	int	count;
	int	i;

	if (signal(SIGINT, &ft_interrupt) == 0)
		return ;
	if (pipex->code_err == NULL)
		pipex->code_err == 0;
	count_nb_tab(str, &count);
	if (count == 0)
		return ;
	pipex->tab = malloc(sizeof(char *) * (count + 1));
	if (!pipex->tab)
		return ;
	extract_to_tab(pipex->tab, str, count);
	if (!pipex->tab)
		return ;
	if (check_tab(pipex->tab, count) == 0)
		return (free_map(pipex->tab));
	i = 0;
	pipex->token = malloc(sizeof(int) * count);
	if (!pipex->token)
		return (free_map(pipex->tab));
	sort_token(pipex->tab, pipex->token, i);
	pipex->code_err == ft_check_random(pipex->tab, pipex->token);
	if (pipex->code_err != 0)
		return (free_map(pipex->tab), free(pipex->token));
	if (handle_builtin(pipex, str) == 0)
		main_pipex(str, pipex);
}

void	count_nb_tab(char *str, int *count)
{
	int	i;
	int	j;

	i = 0;
	(*count) = 0;
	while ((str[i] && i <= stop_str(str))) // normalement pas de leaks
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
