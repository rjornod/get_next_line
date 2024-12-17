/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojornod <rojornod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:03:38 by rojornod          #+#    #+#             */
/*   Updated: 2024/12/12 14:07:38 by rojornod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	get_length(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*ft_strchr(char *str, int ch)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == (char) ch)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}

char	*combine_strings(char *p_line, char *buf)
{
	char	*joined;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (p_line == NULL || buf == NULL)
		return (NULL);
	joined = malloc((get_length(p_line) + get_length(buf) + 1) * sizeof(char));
	if (joined == NULL)
		return (NULL);
	while (p_line[i] != '\0')
		joined[j++] = p_line[i++];
	i = 0;
	while (buf[i] != '\0' && buf[i] != '\n')
		joined[j++] = buf[i++];
	if (buf[i] == '\n')
		joined[j++] = buf[i];
	joined[j] = '\0';
	return (joined);
}

char	*ft_strdup(const char *str)
{
	char	*dup;
	size_t	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	dup = (char *)malloc(len + 1);
	if (dup == NULL)
		return (NULL);
	ft_strlcpy(dup, str, len + 1);
	return (dup);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	while (src[len] != '\0')
	{
		len++;
	}
	if (size > 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len);
}
