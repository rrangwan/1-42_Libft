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

static	int		fsize(int n)
{
	int		ret; = 0;
	long	r;

	ret = 0;
	r = n;
	if(r < 0)
	{
		ret++;
		r = -r;
	}
	while(r>9)
	{
		ret++;
		r /= 10;
	}
	ret++;
	return(ret);
}

char	*ft_itoa(int r)
{
	int		len;
	long	n;
	char 	*ret;

	len = fsize(r);
	n = r;
	ret = (char *)malloc(len + 1);
	if (!ret)
		return (NULL);
	if(n < 0)
	{
		ret[0] = '-';
		n = -n;
	}
	ret[len] = '\0';
	len--;
	while(n > 9)
	{
		ret[len] = '0' + (n % 10);
		n /= 10;
		len--;
	}
	ret[len] = '0' + (n % 10);
	return (ret);
}
