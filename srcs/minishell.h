/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elcesped <elcesped@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 14:55:16 by mvachera          #+#    #+#             */
/*   Updated: 2023/10/24 14:48:38 by elcesped         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../ft_printf/ft_printf.h"
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <signal.h> //a ajouter dans la librairie

typedef struct s_pipex
{
	int		here_doc;
	char	**cmd_paths;
	char	**cmd_args;
	char	**envp;
	char	**envp2;
	char	*limiteur;
	char	*str_end;
	char	*file_here_doc;
	int		cmd_count;
	int		pipefd[2];
	int		pid[1024];
	int		prev;
	int		fd;

	char	**tab;
	int		*token;

	char	**files;
	int		*type;

	int		code_err;
}			t_pipex;

enum		e_token
{
	PIPE,
	CHEVRON_G,
	CHEVRON_D,
	D_CHEVRON_G,
	D_CHEVRON_D,
	IN_FILES,
	OUT_FILES,
	HERE_DOC,
	BUILTIN,
	COMMAND,
	ARGUMENT,
	RANDOM,
};

int			main_pipex(char *str, t_pipex *pipex);
int			ft_exec(t_pipex *pipex);
void		child_process(t_pipex *pipex, int index);
char		*get_cmd(char **tab2, t_pipex *pipex);
void		execute(t_pipex *pipex, char *command, char **tab);
char		**find_path(char **envp);
void		ft_here_doc(t_pipex *pipex);
char		*str_johnny(char *s1, char *s2);
int			ft_count(char const *s, char c);
int			nb_cmd(t_pipex *pipex);
void		je_souffre_trop(t_pipex *pipex);

void		echo_command(char **arg, int choice, int nb_arg);
void		cd_utils(char *path);
void		cd_command(char *path);
void		pwd_command(void);
void		export_command(t_pipex *pipex, char *str);
void		unset_command(char *var, t_pipex *pipex);
int			check_unset(char *var, t_pipex *pipex, int len_var);
void		env_command(t_pipex *pipex);
void		execute_builtin(char *str, t_pipex *pipex);
void		execute_builtin2(char *str, t_pipex *pipex, char **arg, int nb_arg);
char		**get_arg(char *str, t_pipex *pipex, int nb_arg);
void		get_arg2(t_pipex *pipex, int *i, int *nb_arg, char **all_arg);
int			count_arg(t_pipex *pipex, char *str);
int			handle_builtin(t_pipex *pipex, char *str);
void		manage_builtin(char *str, t_pipex *pipex);
void		handle_exit(t_pipex *pipex, int i);

char		*tonegatif(char *str);
void		ft_react_to_signal(int sig);
void		ft_interrupt(int sig);
void		create_tab(char *str, t_pipex *pipex);
void		count_nb_tab(char *str, int *count);
void		extract_to_tab(char **tab, char *str, int count);
void		extract_to_tab2(char *str, int *i, int *j);
void		letters_arg(char *str, int *j);
int			stop_str(char *str);
int			check_tab(char **tab, int count);
void		handle_quotes(char *str);
char		*handle_quotes2(char *str);
int			check_first_str(char *str);
int			is_metacaractere(char c);
char		*cpy(char *str, int i, int j);
void		sort_token(char **tab, int *token, int i);
void		sort_token2(char **tab, int *token, int i);
int			check_builtin(char *str);
void		free_memory(t_pipex *pipex);
void		free_pipex(t_pipex *pipex);
int			ft_strcmp(char *s1, char *s2);
void		free_map(char **map_a_parser);
char		**get_all_cmd(t_pipex *pipex);
void		get_all_cmd2(t_pipex *pipex, int *i, char **all_cmd);
int			check_arg(char *str, t_pipex *pipex);
char		*manage_arg(char *str, t_pipex *pipex);
int			get_len(char *str, t_pipex *pipex);
char		*ft_strcpy(char *dest, char *src);
char		*ft_strcat(char *dest, char *src);
void		parcours_cmd(t_pipex *pipex);
void		openfiles(t_pipex *pipex, char *cmd);
void		handle_in_files(t_pipex *pipex, int i);
void		handle_out_files(t_pipex *pipex, int i);
void		check_here_doc(t_pipex *pipex);

void		test_print(t_pipex *pipex);

#endif
