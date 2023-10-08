#include "get_next_line.h"

char	*handle_read(int fd, char *str, int bytes_read)
{
	char	*temp;

	temp = (char *)malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	while (!ft_strchr(str, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(temp);
			return (NULL);
		}
		temp[bytes_read] = '\0';
		str = ft_strjoin(str, temp);
		if (!str)
		{
			free(temp);
			return (NULL);
		}
	}
	free(temp);
	return (str);
}

char	*get_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	while (str[i] != '\n')
		i++;
	line = (char *)malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*rm_prev_line(char *str)
{
	int		i;
	int		j;
	char	*next_line;

	i = 0;
	while (str[i] != '\n')
		i++;
	i++;
	next_line = (char *)malloc((ft_strlen(str) - i + 1) * sizeof(char));
	if (!next_line)
		return (NULL);
	j = 0;
	while (str[i])
		next_line[j++] = str[i++];
	next_line[j] = '\0';
	free(str);
	return (next_line);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = 1;
	str = handle_read(fd, str, bytes_read);
	if (!str)
	{
		free(str);
		return (NULL);
	}
	line = get_line(str);
	if (!line)
		return (NULL);
	str = rm_prev_line(str);
	if (!str)
		return (NULL);
	return (line);
}

#include <fcntl.h>
#include <stdio.h>
int main(void)
{
	int fd = open("./test1.txt", O_RDONLY);
	char *line = get_next_line(fd);
	printf("%s", line);
	free(line);
	return (0);
}
