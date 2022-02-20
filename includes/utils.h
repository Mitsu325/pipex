/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 19:26:46 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/02/19 21:04:07 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdio.h>

void	putchar_fd(char ch, int fd);
void	putstr_fd(char *str, int fd);

char	**split(char const *s, char c);
char	*strchr(const char *s, int c);
int		ft_strlen(const char *str);
char	*strnstr(const char *str, const char *find, size_t len);
char	*substr(char const *s, int start, int len);
char	*strjoin(char *s1, char *s2);

#endif
