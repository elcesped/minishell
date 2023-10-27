/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:37:58 by mvachera          #+#    #+#             */
/*   Updated: 2023/10/17 15:52:11 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
