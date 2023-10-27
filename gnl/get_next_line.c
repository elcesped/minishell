/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:27:18 by mvachera          #+#    #+#             */
/*   Updated: 2023/09/08 22:34:20 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*Fonction principale.

 * Pour read_and_stash(fd, &stash); 
	* 1. Lire depuis un fichier et ajouter ce qui a ete lu a la liste chainee.

 * Pour extract_line(stash, &line);
        * 2. Extraire dans line, ce qui se trouve dans stash.

 * Pour clean_stash(&stash);
        * 3. nettoyer la stash.*/

char	*get_next_line(int fd, int tofree)
{
	static t_lst	*stash = NULL;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (tofree)
		return (free_stash(stash), NULL);
	line = NULL;
	read_and_stash(fd, &stash);
	if (!stash)
		return (NULL);
	extract_to_line(stash, &line);
	clean_node(&stash);
	if (line[0] == '\0')
	{
		free_stash(stash);
		stash = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}

// Utilise read() pour ajouter les caractere a la variable statique (stash).

void	read_and_stash(int fd, t_lst **stash)
{
	char	*buf;
	int		readed;

	readed = 1;
	while (!found_newline(*stash) && readed != 0)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buf)
			return ;
		readed = (int)read(fd, buf, BUFFER_SIZE);
		if ((*stash == NULL && readed == 0) || readed == -1)
		{
			free(buf);
			return ;
		}
		buf[readed] = '\0';
		lst_new(stash, buf, readed);
		free(buf);
	}
}

/* Ajoute le contenu du buffer (variable temporaire) a la fin de notre variable
 * statique(stash).*/

void	lst_new(t_lst **stash, char *buf, int readed)
{
	t_lst	*new;
	t_lst	*last;
	int		i;

	new = malloc(sizeof(t_lst));
	if (!new)
		return ;
	last = g_l_n(*stash);
	i = 0;
	new->next = NULL;
	new->content = malloc(sizeof(char) * (readed + 1));
	if (!new->content)
		return ;
	while (buf[i] && i < readed)
	{
		new->content[i] = buf[i];
		i++;
	}
	new->content[i] = '\0';
	if (*stash == NULL)
	{
		*stash = new;
		return ;
	}
	last->next = new;
}

/* Extrait tout les caracteres de notre variable statique (stash) 
 * et les stockes tous dans la variable ligne.
 * S'arrete lors de la premiere occurence du caractere '\n' qu'il rencontre.*/

void	extract_to_line(t_lst *stash, char **line)
{
	int	i;
	int	j;

	if (stash == NULL)
		return ;
	j = 0;
	len_line(stash, line);
	if (*line == NULL)
		return ;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				(*line)[j++] = stash->content[i];
				break ;
			}
			(*line)[j++] = stash->content[i++];
		}
		stash = stash->next;
	}
	(*line)[j] = '\0';
}

/* Apres avoir lu la ligne, nous n'avons desormais plus besoin des caracteres.
 * Cette fonction nettoie la variable statique (stash), pour que les caracteres 
 * qui n'ont pas ete retourner a la fin de get_next_line 
 * reste dans notre varaible statique (stash).*/

void	clean_node(t_lst **stash)
{
	t_lst	*clean;
	t_lst	*last;
	int		i;
	int		j;

	clean = malloc(sizeof(t_lst));
	if (*stash == NULL || clean == NULL)
		return ;
	clean->next = NULL;
	last = g_l_n(*stash);
	i = 0;
	j = 0;
	while (last->content[i] != '\0' && last->content[i] != '\n')
		i++;
	if (last->content[i] == '\n')
		i++;
	clean->content = malloc(sizeof(char *) * ((len(last->content) - i) + 1));
	if (!clean->content)
		return ;
	while (last->content[i])
		clean->content[j++] = last->content[i++];
	clean->content[j] = '\0';
	free_stash(*stash);
	*stash = clean;
}

/*int     main(void)
{
        int             fd;
        char    *line;

        fd = open("map.ber", O_RDONLY);
        while (1)
        {
                line = get_next_line(fd);
                printf("%s", line);
                if (line == NULL)
                        break ;
                free(line);
        }
        return (0);
}*/