/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathonon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:44:23 by mathonon          #+#    #+#             */
/*   Updated: 2022/10/26 12:44:26 by mathonon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	d;

	if (n == 0)
		return (ft_strlen(src));
	i = 0;
	d = ft_strlen(dst);
	if (d > n)
		return (ft_strlen(src) + n);
	while (src[i] && d + i < (n - 1))
	{
		dst[d + i] = src[i];
		++i;
	}
	dst[d + i] = '\0';
	return (ft_strlen(src) + d);
}
