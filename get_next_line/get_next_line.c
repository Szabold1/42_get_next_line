/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszabo <bszabo@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:14:19 by bszabo            #+#    #+#             */
/*   Updated: 2024/02/26 17:58:04 by bszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// read from 'fd' into 'line' until a newline is reached
// return 0 if successful, -1 if an error occurred
static int	read_line(int fd, char **line, char buffer[BUFFER_SIZE + 1])
{
	int	bytes_read;

	bytes_read = 1;
	while (!ft_strchr(*line, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (-1);
		buffer[bytes_read] = '\0';
		*line = gnl_strjoin(*line, buffer);
	}
	if (ft_strlen(*line) == 0)
		return (-1);
	return (0);
}

// cpy the 'next_line' into 'buffer' and correctly null-terminate 'line'
static void	set_next_line(char *line, char buffer[BUFFER_SIZE + 1])
{
	char	*next_line;
	int		line_end;

	next_line = ft_strchr(line, '\n');
	if (next_line)
	{
		line_end = next_line - line + 1;
		ft_strlcpy(next_line + 1, buffer, BUFFER_SIZE + 1);
	}
	else
	{
		line_end = ft_strlen(line);
		ft_strlcpy("", buffer, BUFFER_SIZE + 1);
	}
	line[line_end] = '\0';
}

// read from 'fd' and return a line from the file
char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

	line = ft_strdup(buffer);
	if (read_line(fd, &line, buffer) == -1)
		return (free(line), NULL);
	set_next_line(line, buffer);
	return (line);
}

/*
#include <fcntl.h>
#include <stdio.h>
int main(void)
{
	int fd = open("./test1.txt", O_RDONLY);
	char *line;

	while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
	close(fd);
	return (0);
}
*/