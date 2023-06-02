/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathonon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:34:52 by mathonon          #+#    #+#             */
/*   Updated: 2022/10/26 12:34:55 by mathonon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;
	const unsigned char	i = c;

	str = (const unsigned char *)s;
	while (n--)
	{
		if (*str == i)
			return ((void *)str);
		++str;
	}
	return (NULL);
}
