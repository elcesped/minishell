/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 21:20:40 by mvachera          #+#    #+#             */
/*   Updated: 2023/10/23 21:39:37 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_unset(char *var, t_pipex *pipex, int len_var)
{
	int	i;

	i = 0;
	while (pipex->envp[i])
	{
		if (ft_strncmp(pipex->envp[i], var, len_var) == 0
			&& pipex->envp[i][len_var] == '=')
			return (1);
		i++;
	}
	return (0);
}

void	unset_command(char *var, t_pipex *pipex)
{
	int	i;
	int	j;
	int	len_envp;
	int	len_var;

	len_envp = 0;
	len_var = ft_strlen(var);
	if (ft_strchr(var, '=') != NULL || check_unset(var, pipex, len_var) == 0)
		return ;
	while (pipex->envp[len_envp])
		len_envp++;
	pipex->envp2 = malloc(sizeof(char *) * (len_envp + 1));
	if (!pipex->envp2)
		return ;
	i = 0;
	j = 0;
	while (j < len_envp && pipex->envp[i])
	{
		if (ft_strncmp(pipex->envp[i], var, len_var) == 0
			&& pipex->envp[i][len_var] == '=')
			i++;
		pipex->envp2[j] = pipex->envp[i];
		j++;
		i++;
	}
	pipex->envp2[j] = 0;
	pipex->envp = pipex->envp2;
}

void	env_command(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->envp[i])
	{
		ft_putstr_fd(pipex->envp[i], 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
}
