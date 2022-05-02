/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrangwan <rrangwan@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:12:47 by rrangwan          #+#    #+#             */
/*   Updated: 2021/12/20 16:12:48 by rrangwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ddst;
	unsigned char	*ssrc;

	i = 0;
	if ((n == 0) || (dst == src))
		return (dst);
	ddst = (unsigned char *)dst;
	ssrc = (unsigned char *)src;
	while (i < n)
	{
		ddst[i] = ssrc[i];
		i++;
	}
	dst = (void *)(ddst);
	return (dst);
}
