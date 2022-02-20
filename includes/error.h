/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 20:53:58 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/02/20 16:12:34 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

void	cmd_not_found(char **cmd, int pid);
void	error_message(char *error_msg, char *help_msg);
void	error_safe_exit(char **env_path);
void	error_exit(void);

#endif
