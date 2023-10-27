/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:43:12 by mvachera          #+#    #+#             */
/*   Updated: 2023/10/25 20:43:06 by mvachera         ###   ########.fr       */
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
			printf("\n");
		return ;
	}
	while (i < nb_arg - 1)
	{
		printf("%s ", arg[i]);
		i++;
	}
	printf("%s", arg[i]);
	if (choice == 1)
		printf("\n");
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
	new_envp = ft_calloc(sizeof(char *), (env_count + 2));
	if (!new_envp)
		return ;
	i = 0;
	while (i < env_count)
	{
		new_envp[i] = ft_strdup(pipex->envp[i]);
		i++;
	}
	new_envp[i] = ft_strdup(str);
	
	// if (pipex->envp != NULL)
	free_map(pipex->envp);
	pipex->envp = new_envp;
}
