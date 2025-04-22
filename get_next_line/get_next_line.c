/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 11:10:46 by sel-hime          #+#    #+#             */
/*   Updated: 2024/11/24 11:10:47 by sel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_str(char **buffer)
{
	if (buffer && *buffer)
	{
		free(*buffer);
		*buffer = NULL;
	}
}

int	isnewline(char *line)
{
	if (!line)
		return (0);
	while (*line)
	{
		if (*line == '\n')
			return (1);
		line++;
	}
	return (0);
}

char	*fill(char *remaining, char *buffer)
{
	size_t	rem;
	size_t	buf;
	char	*line;

	if (!remaining && !buffer)
		return (NULL);
	if (!remaining)
		rem = 0;
	else
		rem = ft_strlen(remaining);
	buf = ft_strlen(buffer);
	line = malloc(rem + buf + 1);
	if (!line)
	{
		free_str(&remaining);
		return (NULL);
	}
	if (remaining)
	{
		ft_strlcpy(line, remaining, rem + 1);
		free_str(&remaining);
	}
	ft_strlcpy(line + rem, buffer, buf + 1);
	return (line);
}

char	*extract(char **remaining)
{
	char	*temp;
	char	*line;
	char	*newlinepos;

	if (!remaining || !*remaining || **remaining == '\0')
		return (NULL);
	newlinepos = ft_strchr(*remaining, '\n');
	if (!newlinepos)
	{
		line = ft_strdup(*remaining);
		free_str(remaining);
	}
	else
	{
		line = ft_cpy(*remaining);
		temp = ft_strdup(newlinepos + 1);
		free_str(remaining);
		*remaining = temp;
		temp = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*remaining;
	char		*buffer;
	char		*line;
	ssize_t		bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free_str(&remaining), NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (1)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			return (free_str(&buffer), free_str(&remaining), NULL);
		buffer[bytes] = '\0';
		remaining = fill(remaining, buffer);
		if (isnewline(remaining) || bytes == 0)
			break ;
	}
	free_str(&buffer);
	line = extract(&remaining);
	if (!line && bytes == 0)
		return (free_str(&remaining), NULL);
	return (line);
}
