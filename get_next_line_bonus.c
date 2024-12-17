/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojornod <rojornod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:03:19 by rojornod          #+#    #+#             */
/*   Updated: 2024/12/17 13:27:58 by rojornod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*buffer[FD_MAX] = {NULL};
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FD_MAX)
		return (NULL);
	if (!buffer[fd])
	{
		buffer[fd] = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer[fd])
			return (NULL);
		buffer[fd][0] = '\0';
	}
	line = extract_line(buffer[fd]);
	line = read_and_join(fd, buffer[fd], line);
	if (!line || line[0] == '\0')
	{
		free(line);
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	manage_buffer(buffer[fd]);
	return (line);
}

char	*extract_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	line = malloc((get_length(buffer) + 1) * sizeof(char));
	if (!line)
		return (NULL);
	while (buffer[i] != '\0' && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*read_and_join(int fd, char *buffer, char *line)
{
	int		bytes_read;
	char	*prev_line;

	prev_line = line;
	while (ft_strchr(line, '\n') == NULL)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			buffer[0] = '\0';
			if (bytes_read == -1)
				free(prev_line);
			if (bytes_read == -1)
				return (NULL);
			else
				return (prev_line);
		}
		buffer[bytes_read] = '\0';
		line = combine_strings(prev_line, buffer);
		if (!line)
			return (free(prev_line), NULL);
		free(prev_line);
		prev_line = line;
	}
	return (line);
}

void	manage_buffer(char *buffer)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = ft_strchr(buffer, '\n');
	if (tmp == NULL)
		return ;
	tmp++;
	while (tmp[i] != '\0')
	{
		buffer[i] = tmp[i];
		i++;
	}
	buffer[i] = '\0';
}
