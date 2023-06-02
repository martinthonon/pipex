/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathonon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:48:03 by mathonon          #+#    #+#             */
/*   Updated: 2022/10/26 12:48:06 by mathonon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s, const char *set)
{
	size_t	len;

	if (!s || !set)
		return (NULL);
	while (*s && ft_strchr(set, *s))
		++s;
	len = ft_strlen(s);
	while (len && ft_strchr(set, s[len]))
		--len;
	return (ft_substr(s, 0, (len + 1)));
}
