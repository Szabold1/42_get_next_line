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

char	*ft_strchr(const char *str, int c)
{
	unsigned char	c_c;

	if (!str)
		return (NULL);
	c_c = (unsigned char)c;
	while (*str)
	{
		if (c_c == *str)
			return ((char *)str);
		str++;
	}
	if (c_c == '\0')
		return ((char *)str);
	return (0);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s_final;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	s_final = (char *)malloc((int)(ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (s_final == NULL)
		return (NULL);
	while (s1[i])
	{
		s_final[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		s_final[i] = s2[j];
		i++;
		j++;
	}
	s_final[i] = '\0';
	return (s_final);
}
