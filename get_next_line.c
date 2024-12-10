/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojornod <rojornod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:14:08 by rojornod          #+#    #+#             */
/*   Updated: 2024/12/10 16:54:31 by rojornod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		return (NULL);
	}
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (free(buffer), NULL);
	line = extract_line(buffer);
	if (!line)
		return (NULL);
	buffer = trim_line(buffer);
	return (line);
}

char	*read_file(int fd, char *line)
{
	int		bytes_read;
	char	*buffer;

	if (!line)
		line = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof (char));
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		line = join_lines(line, buffer);
		if (ft_strchr(line, '\n'))
			break ;
	}
	free(buffer);
	return (line);
}

/****************************************************************************

	Extracts a single line from the buffer, 
	including the newline character if present.
****************************************************************************/
char	*extract_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] != '\n' && buffer[i])
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

/****************************************************************************
	
	Removes the first line from the buffer, allowing subsequent calls to 
	get_next_line to process the next line in the file.
	
****************************************************************************/
char	*trim_line(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

/****************************************************************************
	
	Combines two strings and manage memory properly by freeing the 
	original line after it has been joined with the buffer.
	
****************************************************************************/
char	*join_lines(char *line, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(line, buffer);
	free(line);
	return (temp);
}

int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	/**************************************/
	/*             Long File              */
	//fd = open("dracula.txt", O_RDONLY);
	/**************************************/
	/*             Long Line              */
	// fd = open("longline.txt", O_RDONLY);
	/**************************************/
	/*           Normal File              */	
	//fd = open("smalltext.txt", O_RDONLY);
	/**************************************/
	/*            User input              */
	//fd = 0;
	/**************************************/
	/*            Empty File              */	
	fd = open("nullexample.txt", O_RDONLY);
	/**************************************/
	i = 1;

	if (get_next_line(fd) == NULL)
	{
		printf("Something went wrong\n");
		return (-1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("[%d] %s", i, line);
		free(line);
		i++;
	}
	//free(line);
	close(fd);
	return (0);
}

char	*ft_strchr(char *s, int c)
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

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		sizetotal;
	char	*res;
	int		i;
	int		j;

	i = 0;
	sizetotal = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(sizeof(char) * (sizetotal + 1));
	if (!res || !s1 || !s2)
		return (NULL);
	while (s1[i] != 0)
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[sizetotal] = 0;
	return (res);
}

void	*ft_calloc(size_t element_count, size_t element_size)
{
	char	*res;

	res = malloc(element_size * element_count);
	if (!res)
		return (NULL);
	ft_bzero(res, element_size * element_count);
	return (res);
}