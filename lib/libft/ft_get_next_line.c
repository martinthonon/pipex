/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathonon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:37:35 by mathonon          #+#    #+#             */
/*   Updated: 2023/03/07 16:45:51 by mathonon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_join(char *buffer, const char *str)
{
	char	*dst;

	dst = ft_strjoin(buffer, str);
	free(buffer);
	return (dst);
}

static char	*ft_clear(char *buffer)
{
	char	*dst;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		++i;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	dst = malloc((ft_strlen(buffer) - i));
	if (!dst)
		return (NULL);
	++i;
	j = 0;
	while (buffer[i])
		dst[j++] = buffer[i++];
	dst[j] = '\0';
	free(buffer);
	return (dst);
}

static char	*ft_read(const char	*buffer)
{
	char	*dst;
	int		i;

	i = 0;
	if (!buffer[0])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		++i;
	dst = malloc(i + 2);
	if (!dst)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		dst[i] = buffer[i];
		++i;
	}
	if (buffer[i] == '\n')
	{
		dst[i] = buffer[i];
		++i;
	}
	dst[i] = '\0';
	return (dst);
}

static char	*ft_init(int fd, char *buffer)
{
	char	str[BUFFER_SIZE + 1];
	int		rd;

	if (!buffer)
	{
		buffer = malloc(1);
		buffer[0] = '\0';
	}
	rd = 1;
	while (rd)
	{
		rd = read(fd, str, BUFFER_SIZE);
		if (rd < 0)
		{
			free(buffer);
			return (NULL);
		}
		str[rd] = '\0';
		buffer = ft_join(buffer, str);
		if (ft_strchr(str, '\n'))
			break ;
	}
	return (buffer);
}

char	*ft_get_next_line(int fd)
{
	char		*gnl;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	buffer = ft_init(fd, buffer);
	if (!buffer)
		return (NULL);
	gnl = ft_read(buffer);
	buffer = ft_clear(buffer);
	return (gnl);
}
