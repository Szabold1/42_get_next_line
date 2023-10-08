#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s_final;
	int		s_len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	s_len = (int)(ft_strlen(s1) + ft_strlen(s2));
	s_final = (char *)malloc(s_len + 1);
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

// int	a_in_b(char a, char *b)
// {
// 	if (!b)
// 		return (0);
// 	while (*b)
// 	{
// 		if (a == *b)
// 			return (1);
// 		b++;
// 	}
// 	return (0);
// }

char	*ft_strchr(const char *str, int c)
{
	unsigned char	c_c;

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