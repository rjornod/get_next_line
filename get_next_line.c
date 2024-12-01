/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojornod <rojornod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:44:16 by rojornod          #+#    #+#             */
/*   Updated: 2024/11/29 16:59:22 by rojornod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
char *get_next_line(int fd)
{
	static t_list *stash == NULL;
	char *line;
	int bytes_read;



}

char	*extract_line()
{
}

char	*update_buffer()
{
}

int	main(void)
{
	int	fd;
	char 		*line;

	fd = open("example.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		printff("%s\n", line);
		free(line);
	}
	return (0);
}
