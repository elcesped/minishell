/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_one_builtin.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:01:39 by mvachera          #+#    #+#             */
/*   Updated: 2023/10/19 20:22:47 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_builtin(t_pipex *pipex, char *str)
{
	int	i;
	int	nb_cmd;

	i = 0;
	nb_cmd = ft_count(str, '|');
	if (nb_cmd != 1)
		return (0);
	while (pipex->tab[i])
	{
		if (ft_strcmp(pipex->tab[i], "exit") == 0 && pipex->token[i] == BUILTIN)
			handle_exit(pipex, i);
		else if (ft_strcmp(pipex->tab[i], "cd") == 0
			&& pipex->token[i] == BUILTIN)
			return (manage_builtin("cd", pipex), 1);
		else if (ft_strcmp(pipex->tab[i], "unset") == 0
			&& pipex->token[i] == BUILTIN)
			return (manage_builtin("unset", pipex), 1);
		else if (ft_strcmp(pipex->tab[i], "export") == 0
			&& pipex->token[i] == BUILTIN)
			return (manage_builtin("export", pipex), 1);
		i++;
	}
	return (0);
}

void	manage_builtin(char *str, t_pipex *pipex)
{
	char	**arg;
	int		nb_arg;

	nb_arg = count_arg(pipex, str);
	arg = get_arg(str, pipex, nb_arg);
	if (ft_strcmp(str, "cd") == 0)
	{
		if (nb_arg == 0)
			chdir("/mnt/nfs/homes/mvachera");
		else if (nb_arg > 1)
			ft_printf("cd : too many arguments\n");
		else
			cd_command(arg[0]);
	}
	else if (ft_strcmp(str, "export") == 0)
	{
		if (nb_arg == 0)
			env_command(pipex);
		else
			export_command(pipex, arg[0]);
	}
	else if (ft_strcmp(str, "unset") == 0 && nb_arg > 0)
		unset_command(arg[0], pipex);
	free_memory(pipex);
}

void	handle_exit(t_pipex *pipex, int i)
{
	int	arg;

	arg = 0;
	while (pipex->tab[i])
	{
		if (pipex->token[i] == ARGUMENT && arg == 0)
		{
			arg = 1;
			ft_printf("exit : %s : numeric argument required\n",
				pipex->tab[i]);
		}
		else if (pipex->token[i] == OUT_FILES)
		{
			pipex->fd = open(pipex->tab[i], O_WRONLY | O_CREAT | O_TRUNC, 0666);
			if (pipex->fd == -1)
				return (ft_printf("Fail open out_name file\n"),
					close(pipex->pipefd[1]),
					close(pipex->pipefd[0]), exit(EXIT_FAILURE));
			close(pipex->fd);
		}
		i++;
	}
	ft_printf("exit\n");
	free_memory(pipex);
	exit(0);
}
