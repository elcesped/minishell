/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 20:05:17 by mvachera          #+#    #+#             */
/*   Updated: 2023/10/25 20:06:26 by mvachera         ###   ########.fr       */
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
