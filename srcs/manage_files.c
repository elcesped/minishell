/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_files.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:58:15 by mvachera          #+#    #+#             */
/*   Updated: 2023/10/23 21:22:31 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	openfiles(t_pipex *pipex, char *cmd)
{
	int	i;

	i = 0;
	while (pipex->tab[i])
	{
		if (ft_strcmp(pipex->tab[i], cmd) == 0)
		{
			handle_in_files(pipex, i);
			handle_out_files(pipex, i);
			break ;
		}
		i++;
	}
}

void	handle_in_files(t_pipex *pipex, int i)
{
	while (i >= 0 && pipex->token[i] != PIPE)
		i--;
	if (pipex->token[i] == PIPE && pipex->tab[i + 1] != NULL)
		i++;
	while (pipex->tab[i] && pipex->token[i] != PIPE)
	{
		if (pipex->token[i] == IN_FILES)
		{
			pipex->fd = open(pipex->tab[i], O_RDONLY);
			if (pipex->fd == -1)
			{
				ft_printf("%s : fail to open file\n", pipex->tab[i]);
				free_pipex(pipex);
				exit(1);
			}
			dup2(pipex->fd, 0);
		}
		i++;
	}
}

void	handle_out_files(t_pipex *pipex, int i)
{
	while (pipex->tab[i] && pipex->token[i] != PIPE)
	{
		if (pipex->token[i] == OUT_FILES)
		{
			if (i != 0 && pipex->token[i - 1] == CHEVRON_D)
				pipex->fd = open(pipex->tab[i], O_CREAT | O_RDWR | O_TRUNC,
						0666);
			else if (i != 0 && pipex->token[i - 1] == D_CHEVRON_D)
				pipex->fd = open(pipex->tab[i], O_CREAT | O_RDWR | O_APPEND,
						0666);
			if (pipex->fd == -1)
			{
				ft_printf("%s : fail to open file\n", pipex->tab[i]);
				free_pipex(pipex);
				exit(1);
			}
			dup2(pipex->fd, 1);
			close(pipex->fd);
		}
		i++;
	}
}

void	check_here_doc(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->tab[i])
	{
		if (pipex->token[i] == HERE_DOC)
		{
			ft_printf("here_doc\n");
			pipex->here_doc = 1;
			pipex->file_here_doc = "here_doc";
			pipex->limiteur = ft_strdup(pipex->tab[i]);
			if (!pipex->limiteur)
				exit(1);
		}
		i++;
	}
}

// int	openfiles(t_pipex *pipex)
// {
// 	int		i;
// 	int		fd;

// 	i = 0;
// 	fd = -1;
// 	mallocfichiers(pipex);
// 	while (pipex->files[i])
// 	{
// 		if (pipex->type[i] == IN_FILES)
// 			fd = open(pipex->files[i], O_RDONLY);
// 		if (pipex->type[i] == D_CHEVRON_G)
// 		{
// 			ft_printf("here_doc\n");
// 			pipex->here_doc = 1;
// 			pipex->limiteur = "LIMITER";
// 		}
// 		if (pipex->type[i] == CHEVRON_D)
// 			fd = open(pipex->files[i], O_CREAT | O_RDWR | O_TRUNC, 0666);
// 		if (pipex->type[i] == D_CHEVRON_D)
// 			fd = open(pipex->files[i], O_CREAT | O_RDWR | O_APPEND, 0666);
// 		if (fd == -1)
// 		{
// 			ft_printf("%s : fail to open file\n", pipex->files[i]);
// 			exit(1);
// 		}
// 		if (pipex->type[i] == IN_FILES)
// 			dup2(fd, 0);
// 		else
// 			dup2(fd, 1);
// 		close(fd);
// 		i++;
// 	}
// 	free_map(pipex->files);
// 	free(pipex->type);
// 	return (0);
// }
// else if (pipex->token[i] == HERE_DOC)
// {
// 	ft_printf("here_doc\n");
// 	pipex->here_doc = 1;
// 	pipex->limiteur = "LIMITER\n";
// }

// void	mallocfichiers(t_pipex *pipex)
// {
// 	int	i[2];

// 	i[0] = 0;
// 	i[1] = 0;
// 	while (pipex->tab[i[0]])
// 	{
// 		if (pipex->token[i[0]] == IN_FILES || pipex->token[i[0]] == OUT_FILES
// 			|| pipex->token[i[0]] == HERE_DOC)
// 			i[1]++;
// 		i[0]++;
// 	}
// 	pipex->files = ft_calloc(sizeof(char *), i[1] + 1);
// 	pipex->type = ft_calloc(sizeof(int), i[1]);
// 	i[0] = 0;
// 	i[1] = 0;
// 	while (pipex->tab[i[0]])
// 	{
// 		if (pipex->token[i[0]] == IN_FILES || pipex->token[i[0]] == OUT_FILES
// 			|| pipex->token[i[0]] == HERE_DOC)
// 		{
// 			pipex->files[i[1]] = ft_strdup(pipex->tab[i[0]]);
// 			pipex->type[i[1]++] = pipex->token[i[0]];
// 		}
// 		i[0]++;
// 	}
// }
