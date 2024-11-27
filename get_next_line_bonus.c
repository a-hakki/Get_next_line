#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	int		i;

	i = 0;
    if (!str)
    {
        return (0);
    }
    while (str[i])
		i++;
	return (i);
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

void fireforce(char **saved, char **allocated)
{
    free(*saved);
    *saved = NULL;
    free(*allocated);
    allocated = NULL;
}

char *get_next_line(int fd)
{
    static char *saved[1024];
    char    *allocated;
    int         readen;
    if ((fd < 0 || fd > 1024) || BUFFER_SIZE <= 0)
        return (NULL);
    protected_alloc(&saved[fd], &allocated);
    if (!saved[fd] || !allocated)
        return (fireforce(&saved[fd], &allocated), NULL);
    readen = 1;
    while (!(ft_strchr(saved[fd], '\n')) && readen > 0)
    {
        readen = read(fd, allocated, BUFFER_SIZE);
        if (readen == 0)
            break;
        if (readen == -1)
            return (fireforce(&saved[fd], &allocated), NULL);
        allocated[readen] = '\0';
        saved[fd] = ft_strjoin(saved[fd], allocated);
        if (!saved[fd])
            return (fireforce(&saved[fd], &allocated), NULL);
    }
    free(allocated);
    if (ft_strcmp(saved[fd], "") == 0)
        return (free(saved[fd]), saved[fd] = NULL, NULL);
    return (ft_get_line(&saved[fd], readen));
}

// int main()
// {
//     int i = 1;
//     int fd = open("files.txt", O_RDONLY | O_CREAT, 0644);
//     int fdd = open("files.txt", O_CREAT, 0644);
//     if (fd == -1 || fdd == -1)
//         return (0);
//     printf("%d        %d \n", fd, fdd);
//     char *s = get_next_line(fd);
//     printf("[%d] : %s", i, s);
//     free(s);
//     s = get_next_line(fdd);
//     printf("[%d] : %s", ++i, s);
//     free(s);
    
//     s = get_next_line(fd);
//     printf("[%d] : %s", ++i, s);
//     free(s);
    
//     s = get_next_line(fdd);
//     printf("[%d] : %s", ++i, s);
//     free(s);
    
//     s = get_next_line(fd);
//     printf("[%d] : %s", ++i, s);
//     free(s);
    
//     s = get_next_line(fdd);
//     printf("[%d] : %s", ++i, s);
//     free(s);
    
//     s = get_next_line(fd);
//     printf("[%d] : %s", ++i, s);
//     free(s);
    
//     s = get_next_line(fdd);
//     printf("[%d] : %s", ++i, s);
//     free(s);

//     s = get_next_line(fd);
//     printf("[%d] : %s", ++i, s);
//     free(s);
    
//     s = get_next_line(fdd);
//     printf("[%d] : %s", ++i, s);
//     free(s);
    
//     s = get_next_line(fd);
//     printf("[%d] : %s", ++i, s);
//     free(s);
    
//     s = get_next_line(fdd);
//     printf("[%d] : %s", ++i, s);
//     free(s);

//     s = get_next_line(fd);
//     printf("[%d] : %s", ++i, s);
//     free(s);
//     s = get_next_line(fdd);
//     printf("[%d] : %s", ++i, s);
//     free(s);

//     s = get_next_line(fd);
//     printf("[%d] : %s", ++i, s);
//     free(s);
//     s = get_next_line(fdd);
//     printf("[%d] : %s", ++i, s);
//     free(s);

//     s = get_next_line(fd);
//     printf("[%d] : %s", ++i, s);
//     free(s);
//     s = get_next_line(fdd);
//     printf("[%d] : %s", ++i, s);
//     free(s);

//     s = get_next_line(fd);
//     printf("[%d] : %s", ++i, s);
//     free(s);
//     s = get_next_line(fdd);
//     printf("[%d] : %s", ++i, s);
//     free(s);

//     s = get_next_line(fd);
//     printf("[%d] : %s", ++i, s);
//     free(s);
//     s = get_next_line(fdd);
//     printf("[%d] : %s", ++i, s);
//     free(s);

//     s = get_next_line(fd);
//     printf("[%d] : %s", ++i, s);
//     free(s);
//     s = get_next_line(fdd);
//     printf("[%d] : %s", ++i, s);
//     free(s);

//     s = get_next_line(fd);
//     printf("[%d] : %s", ++i, s);
//     free(s);
//     s = get_next_line(fdd);
//     printf("[%d] : %s", ++i, s);
//     free(s);


// }