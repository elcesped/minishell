/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:06:51 by mvachera          #+#    #+#             */
/*   Updated: 2023/10/23 18:56:32 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_memory(t_pipex *pipex)
{
	if (pipex->tab != NULL)
		free_map(pipex->tab);
	if (pipex->token != NULL)
		free(pipex->token);
}

void	free_pipex(t_pipex *pipex)
{
	if (pipex->tab != NULL)
		free_map(pipex->tab);
	if (pipex->token != NULL)
		free(pipex->token);
	if (pipex->cmd_args != NULL)
		free_map(pipex->cmd_args);
	// if (pipex->envp2 != NULL)
	// 	free_map(pipex->envp2);
}

void	test_print(t_pipex *pipex)
{
	int	i;

	i = 0;
	printf("Start exect :\n\n");
	printf("%d\n\n", pipex->cmd_count);
	while (pipex->cmd_args[i])
	{
		printf("%s\n\n", pipex->cmd_args[i]);
		i++;
	}
}
