/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:00:11 by mvachera          #+#    #+#             */
/*   Updated: 2023/10/25 21:35:16 by mvachera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_builtin(char *str, t_pipex *pipex, int to_free)
{
	char	**arg;
	int		nb_arg;

	nb_arg = count_arg(pipex, str);
	arg = get_arg(str, pipex, nb_arg);
	if (ft_strcmp(str, "echo") == 0)
		echo_command(arg, 1, nb_arg);
	else if (ft_strcmp(str, "echo -n") == 0)
		echo_command(arg, 0, nb_arg);
	else if (ft_strcmp(str, "pwd") == 0)
		pwd_command();
	else
		execute_builtin2(str, pipex, arg, nb_arg);
	if (arg != NULL)
		free_map(arg);
	if (to_free == 0)
		free_memory(pipex);
	else
		return (free_pipex(pipex), exit(0));
}

void	execute_builtin2(char *str, t_pipex *pipex, char **arg, int nb_arg)
{
	if (ft_strcmp(str, "cd") == 0)
	{
		if (nb_arg == 0)
			chdir("/mnt/nfs/homes/mvachera");
		else if (nb_arg > 1)
			ft_printf("cd : too many arguments\n");
		else
			cd_command(arg[0]);
	}
	else if (ft_strcmp(str, "env") == 0)
	{
		if (nb_arg == 0)
			env_command(pipex);
		else
			ft_printf("env : %s : no such file or directory\n", arg[0]);
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
}

char	**get_arg(char *str, t_pipex *pipex, int nb_arg)
{
	char	**all_arg;
	int		i;

	i = 0;
	if (nb_arg == 0)
		return (NULL);
	all_arg = malloc(sizeof(char *) * (nb_arg + 1));
	if (!all_arg)
		return (NULL);
	nb_arg = 0;
	while (pipex->tab[i])
	{
		if (ft_strcmp(str, pipex->tab[i]) == 0)
		{
			get_arg2(pipex, &i, &nb_arg, all_arg);
			break ;
		}
		i++;
	}
	all_arg[nb_arg] = 0;
	return (all_arg);
}

void	get_arg2(t_pipex *pipex, int *i, int *nb_arg, char **all_arg)
{
	(*i)++;
	while (pipex->tab[*i])
	{
		if (pipex->token[*i] != ARGUMENT)
			return ;
		if (pipex->tab[i[0]][0] == '\'' || pipex->tab[i[0]][0] == '\"')
			all_arg[*nb_arg] = handle_quotes2(pipex->tab[*i]);
		else
			all_arg[*nb_arg] = ft_strdup(pipex->tab[*i]);
		if (!all_arg[*nb_arg])
		{
			while (*nb_arg >= 0)
				free(all_arg[*nb_arg--]);
			return (free(all_arg));
		}
		(*nb_arg)++;
		(*i)++;
	}
}

int	count_arg(t_pipex *pipex, char *str)
{
	int	nb;
	int	i;

	nb = 0;
	i = 0;
	while (pipex->tab[i])
	{
		if (ft_strcmp(str, pipex->tab[i]) == 0)
		{
			if (pipex->tab[i + 1] == NULL)
				return (0);
			else
			{
				i++;
				while (pipex->tab[i])
				{
					if (pipex->token[i] == ARGUMENT)
						nb++;
					i++;
				}
				break ;
			}
		}
		i++;
	}
	return (nb);
}
