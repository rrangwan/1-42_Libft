/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrangwan <rrangwan@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:13:10 by rrangwan          #+#    #+#             */
/*   Updated: 2021/12/20 16:13:12 by rrangwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = len;
	if (src < dst)
	{
		while (i--)
			*(char *)(dst + i) = *(char *)(src + i);
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
