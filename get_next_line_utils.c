#include "get_next_line.h"

// TODO : get_line();
// TODO : ft_join free and allocated empty

char	*ft_strchr(const char *str, int search_str)
{
	int	i;

	i = 0;
    if (!str)
        return (NULL);
	while (str[i])
	{
		if (str[i] == (char)search_str)
			return (&((char *)str)[i]);
		i++;
	}
	if ((char)search_str == '\0')
		return (&((char *)str)[i]);
	return (NULL);
}
size_t	ft_strlen(const char *str)
{
	int		i;

	i = 0;
    if (!str)
        return (0);
	while (str[i])
		i++;
	return (i);
}
char	*ft_strdup(const char *str1)
{
	int		i;
	char	*allocated;

	i = 0;
    if (!str1)
        return (NULL);
	allocated = malloc(sizeof(char) * ft_strlen(str1) + 1);
	if (!allocated)
		return (NULL);
	while (str1[i])
	{
		allocated[i] = str1[i];
		i++;
	}
	allocated[i] = '\0';
	return (allocated);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*returned;
	size_t	slen;

	i = 0;
	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (len == 0 || start >= slen)
		return (ft_strdup(""));
	if (len > slen - start)
		len = slen - start;
	returned = (char *)malloc(sizeof(char) * (len + 1));
	if (!returned)
		return (NULL);
	while (i < len)
	{
		returned[i] = s[start + i];
		i++;
	}
	returned[i] = '\0';
	return (returned);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len1;
	int		len2;
	int		i;
	char	*returned;

    if (!s1 && !s2)
		return (NULL);             
	i = -1;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	returned = malloc(sizeof(char) * len1 + len2 + 1);
	if (!returned)
		return (free(s1), s1 = NULL, NULL);
	while (s1[++i])
		returned[i] = s1[i];
	i = 0;
	while (s2[i])
	{
		returned[len1 + i] = s2[i];
		i++;
	}
	returned[len1 + i] = '\0';
    free(s1);
	s1 = NULL;
	return (returned);
}
void  protected_alloc(char **saved, char **allocated)
{
    if (!*saved)
    {    
        *saved = ft_strdup("");
        if (!*saved)
            *saved = NULL;
    }
    *allocated = malloc((size_t) BUFFER_SIZE + 1);
    if (!*allocated)
    {
        if (*saved)
            free(*saved);
        *saved = NULL;
    }
}   
char    *ft_get_line(char **saved, int readen)
{
    char *temp_saved;
    char *pos;
    if (readen > 0)
    {
        temp_saved = *saved;
        pos = ft_strchr(temp_saved, '\n');
        *saved = ft_strdup(pos + 1);
        *(pos + 1) = '\0';
        return (temp_saved);
    }
    temp_saved = ft_strdup(*saved);
	free(*saved);
    *saved = NULL;
    return (temp_saved);
}
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (s1[i] - s2[i]);
}