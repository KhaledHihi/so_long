/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhihi <khhihi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:24:57 by khhihi            #+#    #+#             */
/*   Updated: 2025/02/15 17:25:21 by khhihi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	*ft_allocate(int len, long nb)
{
	char	*s;

	s = malloc(sizeof(char) * len + 1);
	if (!s)
		return (NULL);
	s[len] = '\0';
	if (nb == 0)
	{
		s[0] = '0';
		return (s);
	}
	else if (nb < 0)
	{
		nb = -nb;
		s[0] = '-';
	}
	while (nb)
	{
		s[--len] = nb % 10 + 48;
		nb = nb / 10;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	long	nb;
	int		len;
	char	*p;

	nb = n;
	len = 0;
	if (n == 0)
		len = 1;
	else if (n < 0)
		len = 1;
	while (n)
	{
		n = n / 10;
		len++;
	}
	p = ft_allocate(len, nb);
	return (p);
}
