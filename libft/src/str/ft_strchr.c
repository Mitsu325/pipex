/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 21:59:51 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/02/14 21:59:51 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The strchr() function returns a pointer to the first occurrence of the
char 'c' in string 's'.
*/
/* Return a pointer to the corresponding character,
or NULL if the character was not found.
*/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != c)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return (str);
}
