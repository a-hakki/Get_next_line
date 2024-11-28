/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoudani <asoudani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 20:21:25 by asoudani          #+#    #+#             */
/*   Updated: 2024/11/27 20:54:32 by asoudani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		return (0);
	}
	while (str[i])
		i++;
	return (i);
}

void	protected_alloc(char **saved, char **allocated)
{
	if (!*saved)
	{
		*saved = ft_strdup("");
		if (!*saved)
			*saved = NULL;
	}
	*allocated = malloc((size_t)BUFFER_SIZE + 1);
	if (!*allocated)
	{
		if (*saved)
			free(*saved);
		*saved = NULL;
	}
}

void	fireforce(char **saved, char **allocated)
{
	free(*saved);
	*saved = NULL;
	free(*allocated);
	allocated = NULL;
}

char	*ft_get_line(char **saved, int readen)
{
	char	*temp_saved;
	char	*pos;

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

char	*get_next_line(int fd)
{
	static char		*saved;
	char			*allocated;
	int				readen;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	protected_alloc(&saved, &allocated);
	if (!saved || !allocated)
		return (fireforce(&saved, &allocated), NULL);
	readen = 1;
	while (!(ft_strchr(saved, '\n')) && readen > 0)
	{
		readen = read(fd, allocated, BUFFER_SIZE);
		if (readen == 0)
			break ;
		if (readen == -1)
			return (fireforce(&saved, &allocated), NULL);
		allocated[readen] = '\0';
		saved = ft_strjoin(saved, allocated);
		if (!saved)
			return (fireforce(&saved, &allocated), NULL);
	}
	if (ft_strcmp(saved, "") == 0)
		return (fireforce(&saved, &allocated), NULL);
	return (free(allocated), ft_get_line(&saved, readen));
}
// int main()
// {
//     int i = 1;
//     int fd = open("files.txt", O_RDONLY | O_CREAT, 0644);
//     if (fd == -1)
//         return (0);
//     char *s = get_next_line(fd);
//     printf("[%d] : %s", i, s);
//     free(s);
//     s = get_next_line(fd);
//     printf("[%d] : %s", ++i, s);
//     free(s);
//     s = get_next_line(fd);
//     printf("[%d] : %s", ++i, s);
//     free(s);
//     s = get_next_line(fd);
//     printf("[%d] : %s", ++i, s);
//     free(s);
//     s = get_next_line(fd);
//     printf("[%d] : %s", ++i, s);
//     free(s);
//     s = get_next_line(fd);
//     printf("[%d] : %s", ++i, s);
//     free(s);
//     s = get_next_line(fd);
//     printf("[%d] : %s", ++i, s);
//     free(s);
//     s = get_next_line(fd);
//     printf("[%d] : %s", ++i, s);
//     free(s);
//     s = get_next_line(fd);
//     printf("[%d] : %s", ++i, s);
//     free(s);
//     s = get_next_line(fd);
//     printf("[%d] : %s", ++i, s);
//     free(s);
//     s = get_next_line(fd);
//     printf("[%d] : %s", ++i, s);
//     free(s);
//     s = get_next_line(fd);
//     printf("[%d] : %s", ++i, s);
//     free(s);
//     s = get_next_line(fd);
//     printf("[%d] : %s", ++i, s);
//     free(s);
//     s = get_next_line(fd);
//     printf("[%d] : %s", ++i, s);
//     free(s);
// }