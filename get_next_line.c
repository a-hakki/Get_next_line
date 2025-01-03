/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakki <ahakki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:46:28 by ahakki            #+#    #+#             */
/*   Updated: 2024/11/28 09:56:40 by ahakki           ###   ########.fr       */
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

void	ft_free(char **saved, char **allocated)
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
		return (ft_free(&saved, &allocated), NULL);
	readen = 1;
	while (!(ft_strchr(saved, '\n')) && readen > 0)
	{
		readen = read(fd, allocated, BUFFER_SIZE);
		if (readen == 0)
			break ;
		if (readen == -1)
			return (ft_free(&saved, &allocated), NULL);
		allocated[readen] = '\0';
		saved = ft_strjoin(saved, allocated);
		if (!saved)
			return (ft_free(&saved, &allocated), NULL);
	}
	if (ft_strcmp(saved, "") == 0)
		return (ft_free(&saved, &allocated), NULL);
	return (free(allocated), ft_get_line(&saved, readen));
}
