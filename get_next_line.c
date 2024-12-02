/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojornod <rojornod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:14:08 by rojornod          #+#    #+#             */
/*   Updated: 2024/12/02 16:27:11 by rojornod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*append_buffer(int fd, char *leftover, char *buffer);
static char	*extract_line(char *line);
static char	*ft_strchr(char *s, int c);

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		*line;
	char		*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(leftover);
		free(buffer);
		leftover = NULL;
		buffer = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	line = append_buffer(fd, leftover, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	leftover = extract_line(line);
	return (line);
}

static char	*extract_line(char *line_buffer)
{
	char	*leftover;
	ssize_t	i;

	i = 0;
	while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
		i++;
	if (line_buffer[i] == 0 || line_buffer[1] == 0)
		return (NULL);
	leftover = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer) - i);
	if (*leftover == 0)
	{
		free(leftover);
		leftover = NULL;
	}
	line_buffer[i + 1] = '\0';
	return (leftover);
}

static char	*append_buffer(int fd, char *leftover, char *buffer)
{
	ssize_t	bytes_read;
	char	*tmp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(leftover);
			return (NULL);
		}
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = 0;
		if (!leftover)
			leftover = ft_strdup("");
		tmp = leftover;
		leftover = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (leftover);
}

static char	*ft_strchr(char *s, int c)
{
	unsigned int	i;
	char			cc;

	cc = (char) c;
	i = 0;
	while (s[i])
	{
		if (s[i] == cc)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == cc)
		return ((char *) &s[i]);
	return (NULL);
}

int main(void)
{
    int fd = open("example.txt", O_RDONLY);
    char *line;
	int i = 0;

    while ((line = get_next_line(fd)) != NULL) {
        printf("[%d] %s",i, line);
		i++;
        free(line);
    }
    close(fd);
    return 0;
}