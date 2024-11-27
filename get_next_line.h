#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE

# define BUFFER_SIZE 22
#endif

# include <unistd.h>
# include <fcntl.h>
#include <stdint.h>
# include <stdio.h>
# include <string.h>
#include <string.h>
#include <stdlib.h>

char    *get_next_line(int fd);
char	*ft_strchr(const char *str, int search_str);
char	*ft_strdup(const char *str1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
void    protected_alloc(char **saved, char **allocated);
size_t	ft_strlen(const char *str);
char    *get_line(char **saved, int readen);
int	    ft_strcmp(char *s1, char *s2);

#endif