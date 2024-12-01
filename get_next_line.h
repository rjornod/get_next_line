/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojornod <rojornod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:58:07 by rojornod          #+#    #+#             */
/*   Updated: 2024/11/29 16:59:11 by rojornod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void	*ft_calloc(size_t num, size_t size);
void	*ft_memset(void *str, int c, size_t n);
char 	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *c );
char	*ft_strchr(const char *str, int search);
char	*update_buffer(char *buffer);
char	*ft_free(char *buffer, char *buf);
char	*extract_line(char *buffer);
char	*read_from_file(int fd, char *stash);

#endif