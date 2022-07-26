/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrangwan <rrangwan@42AbuDhabi.AE>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:08:40 by rrangwan          #+#    #+#             */
/*   Updated: 2022/07/25 20:59:59 by rrangwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_digits(int n)
{
	int		ret;
	long	l;

	ret = 0;
	l = n;
	if (l < 0)
	{
		ret++;
		l = -l;
	}
	while (l > 9)
	{
		ret++;
		l /= 10;
	}
	ret++;
	return (ret);
}

char	*ft_itoa(int d)
{
	int		len;
	long	n;
	char	*ret;

	len = ft_digits(d);
	n = d;
	ret = (char *)malloc(len + 1);
	if (!ret)
		return (NULL);
	if (n < 0)
	{
		ret[0] = '-';
		n = -n;
	}
	ret[len] = '\0';
	len--;
	while (n > 9)
	{
		ret[len] = '0' + (n % 10);
		n /= 10;
		len--;
	}
	ret[len] = '0' + n;
	return (ret);
}
