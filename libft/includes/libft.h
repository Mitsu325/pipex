/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 21:33:53 by patricia          #+#    #+#             */
/*   Updated: 2022/02/17 19:32:22 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

void	ft_putchar_fd(char ch, int fd);
void	ft_putstr_fd(char *str, int fd);

char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
int		ft_strlen(const char *str);
char	*ft_strnstr(const char *str, const char *find, size_t len);
char	*ft_substr(char const *s, int start, int len);
char	*ft_strjoin(char *s1, char *s2);

#endif
