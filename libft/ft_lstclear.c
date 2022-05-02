/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrangwan <rrangwan@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:09:44 by rrangwan          #+#    #+#             */
/*   Updated: 2021/12/20 16:09:46 by rrangwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*a;
	t_list	*temp;

	a = *lst;
	while (a)
	{
		temp = a->next;
		ft_lstdelone(a, del);
		a = temp;
	}
	*lst = NULL;
}
