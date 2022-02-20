/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 22:29:25 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/02/19 21:29:25 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define EX_SUCCESS 0
# define EX_FAILURE 1

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define CHILD_PID 0
# define PARENT_PID 1

# define DEL 127

// Permissions file read, write and execute
# define MODE_RWE 0777

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>

# include "utils.h"
# include "process.h"
# include "error.h"
# include "path.h"

#endif
