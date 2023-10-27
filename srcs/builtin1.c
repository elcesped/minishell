/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:43:12 by mvachera          #+#    #+#             */
/*   Updated: 2023/10/19 20:08:33 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	echo_command(char **arg, int choice, int nb_arg)
{
	int	i;

	i = 0;
	if (nb_arg == 0)
	{
		if (choice == 1)
			ft_putstr_fd("\n", 1);
		return ;
	}
	while (arg[i + 1])
	{
		ft_putstr_fd(arg[i], 1);
		ft_putstr_fd(" ", 1);
		i++;
	}
	if (choice == 0)
		ft_putstr_fd(arg[i], 1);
	else
	{
		ft_putstr_fd(arg[i], 1);
		ft_putstr_fd("\n", 1);
	}
}

void	cd_command(char *path)
{
	char	cwd[1024];
	char	*cwd2;
	char	*absolu;

	if (path[0] == '/')
	{
		if (chdir(path) == -1)
			ft_printf("cd : no such file or directory : %s\n", path);
		return ;
	}
	if (getcwd(cwd, sizeof(cwd)) == NULL)
		return (perror("getcwd"));
	cwd2 = ft_strdup(cwd);
	if (!cwd2)
		return ;
	absolu = ft_strjoin(cwd2, path);
	if (!absolu)
		return (free(cwd2));
	if (chdir(absolu) != 0)
		ft_printf("cd : no such file or directory : %s\n", path);
	free(cwd2);
	free(absolu);
}

void	pwd_command(void)
{
	char	cwd[1024];

	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		ft_putstr_fd(cwd, 1);
		ft_putstr_fd("\n", 1);
	}
	else
		perror("getcwd");
}

void	export_command(t_pipex *pipex, char *str)
{
	char	**new_envp;
	int		env_count;
	int		i;

	if (ft_strchr(str, '=') == NULL)
		return ;
	env_count = 0;
	while (pipex->envp[env_count] != NULL)
		env_count++;
	new_envp = malloc(sizeof(char *) * (env_count + 2));
	if (!new_envp)
		return ;
	i = 0;
	while (i < env_count)
	{
		new_envp[i] = pipex->envp[i];
		i++;
	}
	new_envp[env_count] = str;
	new_envp[env_count + 1] = NULL;
	if (pipex->envp2 != NULL)
		free_map(pipex->envp2);
	pipex->envp2 = new_envp;
	pipex->envp = pipex->envp2;
}
