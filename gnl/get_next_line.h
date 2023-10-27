/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:28:23 by mvachera          #+#    #+#             */
/*   Updated: 2023/09/08 22:34:44 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_lst
{
	char			*content;
	struct s_lst	*next;
}				t_lst;

char		*get_next_line(int fd, int tofree);
void		read_and_stash(int fd, t_lst **stash);
void		lst_new(t_lst **stash, char *buf, int readed);
void		extract_to_line(t_lst *stash, char **line);
void		clean_node(t_lst **stash);
int			found_newline(t_lst *stash);
t_lst		*g_l_n(t_lst *stash);
void		len_line(t_lst *stash, char **line);
void		free_stash(t_lst *stash);
int			len(const char *str);

#endif