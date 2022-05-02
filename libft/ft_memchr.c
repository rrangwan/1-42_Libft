/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrangwan <rrangwan@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:12:06 by rrangwan          #+#    #+#             */
/*   Updated: 2022/01/01 11:49:00 by rrangwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	v;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	v = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == v)
			return ((void *)&ptr[i]);
		i++;
	}
	return (NULL);
}
