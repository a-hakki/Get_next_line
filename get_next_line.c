#include "get_next_line.h"
char *get_next_line(int fd)
{
    static char *saved;
    char    *allocated;
    int         readen;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    protected_alloc(&saved, &allocated);
    if (!saved || !allocated)
        return (free (saved), allocated = NULL, saved = NULL, NULL);
    readen = 1;
    while (!(ft_strchr(saved, '\n')) && readen > 0)
    {
        readen = read(fd, allocated, BUFFER_SIZE);
        if (readen == 0)
            break;
        if (readen == -1)
            return (free(allocated), allocated = NULL, free(saved), saved = NULL, NULL);
        allocated[readen] = '\0';
        saved = ft_strjoin(saved, allocated);
        if (!saved)
            return (free(allocated), free(saved),allocated = NULL, saved = NULL, NULL);
    }
    free(allocated);
    allocated = NULL;
    if (ft_strcmp(saved, "") == 0)
        return (free(saved), saved = NULL, NULL);
    return (ft_get_line(&saved, readen));
}

int main()
{
    int i = 1;
    int fd = open("files.txt", O_RDONLY | O_CREAT, 0644);
    if (fd == -1)
        return (0);
    char *s = get_next_line(fd);
    printf("[%d] : %s", i, s);
    free(s);
    s = get_next_line(fd);
    printf("[%d] : %s", ++i, s);
    free(s);
    
    s = get_next_line(fd);
    printf("[%d] : %s", ++i, s);
    free(s);
    
    s = get_next_line(fd);
    printf("[%d] : %s", ++i, s);
    free(s);
    
    s = get_next_line(fd);
    printf("[%d] : %s", ++i, s);
    free(s);
    
    s = get_next_line(fd);
    printf("[%d] : %s", ++i, s);
    free(s);
    
    s = get_next_line(fd);
    printf("[%d] : %s", ++i, s);
    free(s);
    
    s = get_next_line(fd);
    printf("[%d] : %s", ++i, s);
    free(s);

    s = get_next_line(fd);
    printf("[%d] : %s", ++i, s);
    free(s);
    
    s = get_next_line(fd);
    printf("[%d] : %s", ++i, s);
    free(s);
    
    s = get_next_line(fd);
    printf("[%d] : %s", ++i, s);
    free(s);
    
    s = get_next_line(fd);
    printf("[%d] : %s", ++i, s);
    free(s);

    s = get_next_line(fd);
    printf("[%d] : %s", ++i, s);
    free(s);
    s = get_next_line(fd);
    printf("[%d] : %s", ++i, s);
    free(s);

}