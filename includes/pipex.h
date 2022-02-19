/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 22:29:25 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/02/19 11:29:43 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

# define STDIN 0
# define STDOUT 1
# define STDERR 2

// Permissions file read and write
# define MODE_RWE 0777

#include <unistd.h>
#include <fcntl.h>
# include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

# include "libft.h"

void	error_message(char *error_msg, char *help_msg);
void	error_safe_exit(char **env_path);

char	**find_env_path(char **envp);
void	free_split(char **table);

#endif
