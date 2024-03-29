/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrangwan <rrangwan@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:04:50 by rrangwan          #+#    #+#             */
/*   Updated: 2022/01/01 11:46:48 by rrangwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nbr, size_t size)
{
	void	*ptr;

	if (size != 0 && nbr > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(nbr * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, size * nbr);
	return (ptr);
}
