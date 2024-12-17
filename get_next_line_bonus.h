/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojornod <rojornod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:03:32 by rojornod          #+#    #+#             */
/*   Updated: 2024/12/17 13:29:22 by rojornod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# ifndef FD_MAX
#  define FD_MAX 1024
# endif
# include <stdlib.h>
# include <unistd.h>

size_t	get_length(const char *str);
char	*combine_strings(char *p_line, char *buf);
char	*ft_strchr(char *str, int ch);
char	*get_next_line(int fd);
char	*extract_line(char *buffer);
char	*read_and_join(int fd, char *buffer, char *line);
void	manage_buffer(char *buffer);
char	*ft_strdup(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);


#endif