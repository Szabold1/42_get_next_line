/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszabo <bszabo@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:15:09 by bszabo            #+#    #+#             */
/*   Updated: 2023/10/09 11:15:18 by bszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

// File: get_next_line_utils.c
char	*ft_strchr(char *str, char c);
int		ft_strlen(char *str);
int		ft_strlcpy(char *src, char *dest, int size);
char	*ft_strdup(char *src);
char	*ft_strjoin(char *s1, char *s2);

// File: get_next_line.c
char	*get_next_line(int fd);

#endif