/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:28:03 by mvachera          #+#    #+#             */
/*   Updated: 2023/09/08 22:35:12 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Cherche le '\n' dans le noeud envoyer en parametre 
 * (le dernier de la liste du coup) de la liste chainee.*/

int	found_newline(t_lst *stash)
{
	int		i;
	t_lst	*last;

	if (stash == NULL)
		return (0);
	i = 0;
	last = g_l_n(stash);
	while (last->content[i])
	{
		if (last->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

// Retourne un pointeur sur le dernier element de la liste chainee.

t_lst	*g_l_n(t_lst *stash)
{
	t_lst	*current;

	current = stash;
	while (current && current->next)
		current = current->next;
	return (current);
}

/* Calcule le nombre de caracteres dans la ligne actuelle.
 * On inclus aussi le '\n' s'il y en a un et on alloue de la memoire avec 
 * la taille obtenue.*/

void	len_line(t_lst *stash, char **line)
{
	int	len;
	int	i;

	len = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				len++;
				break ;
			}
			i++;
			len++;
		}
		stash = stash->next;
	}
	*line = malloc(sizeof(char) * (len + 1));
}

/* On libere la stash en entier.*/

void	free_stash(t_lst *stash)
{
	t_lst	*current;
	t_lst	*next;

	current = stash;
	while (current)
	{
		free(current->content);
		next = current->next;
		free(current);
		current = next;
	}
}

int	len(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
