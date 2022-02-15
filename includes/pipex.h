/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 22:29:25 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/02/15 01:08:15 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# include <stdlib.h>

# include "libft.h"

void	error_handler(char *error_msg, char *help_msg);

#endif
