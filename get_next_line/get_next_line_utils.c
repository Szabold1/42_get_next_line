/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszabo <bszabo@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:14:53 by bszabo            #+#    #+#             */
/*   Updated: 2023/10/09 11:14:55 by bszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// find the first occurrence of 'c' in 'str' and return a pointer to it
char	*ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (str + i);
		i++;
	}
	return (NULL);
}

// return the length of 'str'
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

// copy 'size' - 1 characters from 'src' to 'dest' and null-terminate 'dest'
// return the length of 'src'
int	ft_strlcpy(char *src, char *dest, int size)
{
	int	i;

	if (!src || !dest)
		return (0);
	i = 0;
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

// return a pointer to a new string which is a duplicate of 'src'
char	*ft_strdup(char *src)
{
	char	*dest;
	int		src_len;

	src_len = ft_strlen(src);
	dest = (char *)malloc(sizeof(char) * (src_len + 1));
	if (!dest)
		return (NULL);
	ft_strlcpy(src, dest, src_len + 1);
	return (dest);
}

// concatenate 's1' and 's2' into a new string and return a pointer to it
char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		s1_len;
	int		s2_len;

	if (!s1 && !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(s1, str, s1_len + 1);
	ft_strlcpy(s2, str + s1_len, s2_len + 1);
	free(s1);
	return (str);
}
