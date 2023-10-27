/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 20:41:01 by mvachera          #+#    #+#             */
/*   Updated: 2023/10/23 20:31:04 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**find_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
			return (ft_split(envp[i] + 5, ':'));
		i++;
	}
	return (NULL);
}

void	je_souffre_trop(t_pipex *pipex)
{
	pipex->str_end = str_johnny(pipex->limiteur, "\n");
	if (!pipex->str_end)
		return (ft_printf("Function str_johnny fail\n"),
			free(pipex->limiteur), exit(1));
}

void	ft_here_doc(t_pipex *pipex)
{
	char	*str;
	int		fd;

	je_souffre_trop(pipex);
	fd = open(pipex->file_here_doc, O_RDWR | O_CREAT, 0664);
	if (fd == -1)
		return (ft_printf("Fail open here_doc\n"), exit(EXIT_FAILURE));
	while (1)
	{
		str = get_next_line(0, 0);
		if (!str)
			break ;
		if (!ft_strcmp(str, pipex->str_end))
		{
			free(str);
			break ;
		}
		ft_putstr_fd(str, fd);
		free(str);
	}
	get_next_line(0, 1);
	close(fd);
}
