/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 22:29:25 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/02/19 21:04:09 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define DEL 127

// Permissions file read, write and execute
# define MODE_RWE 0777

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

# include "utils.h"
# include "process.h"
# include "error.h"

void	child_process(char **argv, char **envp, int *fd);

void	parent_process(char **argv, char **envp, int *fd);

char	*find_exec_path(char *cmd, char **envp);

int		run_cmd_child(char *argv_cmd, char **envp);
int		run_cmd_parent(char *argv_cmd, char **envp);

void	error_message(char *error_msg, char *help_msg);
void	error_safe_exit(char **env_path);
void	error_exit();

char	**find_env_path(char **envp);
void	free_split(char **table);

#endif
