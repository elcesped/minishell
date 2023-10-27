/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elcesped <elcesped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 14:54:57 by mvachera          #+#    #+#             */
/*   Updated: 2023/10/27 15:33:06 by elcesped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*tonegatif(char *str)
{
	char	c;
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			c = str[i++];
			while (str[i] && str[i] != c)
			{
				str[i] = -str[i];
				i++;
			}
//			i++;
		}
		i++;
	}
	return (str);
}

void	ft_react_to_signal(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		rl_replace_line("", 1);
		rl_on_new_line();
		rl_redisplay();
		return ;
	}
}

void	ft_interrupt(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		rl_replace_line("", 1);
		rl_redisplay();
		return ;
	}
}

int	main(int ac, char **av, char **envp)
{
	static t_pipex	pipex = {0};
	char			*str;

	(void)av;
	if (signal(SIGQUIT, SIG_IGN) == SIG_ERR)
		return (2);
	if (ac != 1)
		return (0);
	int i;
	for (i = 0; envp[i]; i++)
		;
	pipex.envp = ft_calloc(sizeof(char *), i + 1);
	for (i = 0; envp[i]; i++)
		pipex.envp[i] = ft_strdup(envp[i]);
	while (1)
	{
		if (signal(SIGINT, &ft_react_to_signal) == SIG_ERR)
			return (-1);
		else if (signal(SIGINT, &ft_react_to_signal) == 0)
			return (pipex.code_err = 130, 130);
		str = readline("> ");
		if (!str)
			break ;
		if (str)
			add_history(str);
		if (!*str)
			continue ;
		str = tonegatif(str);
		create_tab(str, &pipex);
	}
	free_map(pipex.envp);
}
