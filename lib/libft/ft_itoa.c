/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathonon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:28:12 by mathonon          #+#    #+#             */
/*   Updated: 2022/10/26 12:28:36 by mathonon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_digit(int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		++i;
	while (n != 0)
	{
		n /= 10 ;
		++i;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*nstr;
	size_t		dgt;
	long int	nb;

	nb = n;
	dgt = ft_digit(n);
	if (n < 0)
	{
		nb *= -1;
		++dgt;
	}
	nstr = malloc(dgt + 1);
	if (!nstr)
		return (NULL);
	nstr[dgt] = '\0';
	while (dgt--)
	{
		nstr[dgt] = nb % 10 + '0';
		nb /= 10 ;
	}
	if (n < 0)
		nstr [0] = '-';
	return (nstr);
}
