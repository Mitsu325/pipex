/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 22:08:21 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/02/19 20:12:26 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The substr() function allocates (with malloc) and returns a substring
from the string 's'.
The substring begins at index 'start' and is of maximum size 'len'. */
/* Return the substring. NULL if the allocation fails. */

#include "pipex.h"

char	*substr(char const *s, int start, int len)
{
	char	*substr;
	char	*new_str;
	int		s_len;
	int		i;

	s_len = ft_strlen(s);
	if (s == NULL || s_len < start)
		return (NULL);
	if (start + len < s_len)
		substr = (char *)malloc((len + 1) * sizeof(char));
	else
		substr = (char *)malloc((s_len - start + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	i = start;
	new_str = substr;
	while (i < (start + len) && *(s + i))
		*new_str++ = *(s + i++);
	*new_str = '\0';
	return (substr);
}
