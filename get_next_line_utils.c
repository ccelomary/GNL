/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-omar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 17:44:25 by mel-omar          #+#    #+#             */
/*   Updated: 2020/02/06 16:33:10 by mel-omar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_realloc(char **buffer, size_t old_size, size_t new_size)
{
	char	*new_buff;
	size_t	iter;

	iter = 0;
	new_buff = malloc(sizeof(char *) * (old_size + new_size));
	while (iter < old_size)
	{
		new_buff[iter] = (*buffer)[iter];
		iter++;
	}
	while (iter < new_size)
	{
		new_buff[iter] = 0;
		iter++;
	}
	if (old_size)
		free(*buffer);
	return (new_buff);
}

int			get_len(char *buffer, long current, long pos)
{
	int		iter;

	iter = 0;
	while ((iter + current) < pos && buffer[(iter + current)] != '\n')
		iter++;
	return (iter);
}

int			copy_to_line(char *buffer, char *line, int len)
{
	int		iter;

	iter = 0;
	while (iter < len)
	{
		line[iter] = buffer[iter];
		iter++;
	}
	line[len] = 0;
	if (buffer[len] == '\n')
		return (1);
	return (0);
}

long		update_buffer(char *buffer, long *current, long *pos, int fd)
{
	if (*current >= *pos)
	{
		*current = 0;
		*pos = read(fd, buffer, BUFFER_SIZE);
	}
	return (*pos);
}
