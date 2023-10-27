/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 21:20:40 by mvachera          #+#    #+#             */
/*   Updated: 2023/10/25 20:45:19 by mvachera         ###   ########.fr       */
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
	char	**new_envp;
	int		i;
	int		j;
	int		len_envp;
	int		len_var;

	len_envp = 0;
	len_var = ft_strlen(var);
	if (ft_strchr(var, '=') != NULL || check_unset(var, pipex, len_var) == 0)
		return ;
	while (pipex->envp[len_envp])
		len_envp++;
	new_envp = ft_calloc(sizeof(char *), (len_envp + 1));
	if (!new_envp)
		return ;
	i = 0;
	j = 0;
	while (j < len_envp && pipex->envp[i])
	{
		if (ft_strncmp(pipex->envp[i], var, len_var) == 0
			&& pipex->envp[i][len_var] == '=')
			i++;
		new_envp[j++] = ft_strdup(pipex->envp[i++]);
	}
	free_map(pipex->envp);
	pipex->envp = new_envp;
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
