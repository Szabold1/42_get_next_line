#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

// helper functions
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
// int		a_in_b(char a, char *b);
char	*ft_strchr(const char *str, int c);
// main functions
char    *get_next_line(int fd);
char	*handle_read(int fd, char *str, int bytes_read);
char	*get_line(char *str);
char	*rm_prev_line(char *str);

#endif