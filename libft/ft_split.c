/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrangwan <rrangwan@42AbuDhabi.AE>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:15:23 by rrangwan          #+#    #+#             */
/*   Updated: 2022/07/25 20:50:25 by rrangwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_word(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		while (*str && ft_is_space(*str))
			str++;
		if (*str && !ft_is_space(*str))
		{
			i++;
			while (*str && !ft_is_space(*str))
				str++;
		}
	}
	return (i);
}

char	*ft_malloc_word(char *str)
{
	int		i;
	int		j;
	char	*mal;

	i = 0;
	j = 0;
	while (str[i] && !ft_is_space(str[i]))
		i++;
	mal = malloc((i + 1) * sizeof(char ));
	if (!mal)
		return (NULL);
	i = 0;
	while (str[i] && !ft_is_space(str[i]))
	{
		mal[j++] = str[i++];
	}
	mal[j] = '\0';
	return (mal);
}

char	**ft_split(char *str)
{
	int		i;
	char	**arr;

	i = 0;
	arr = malloc((ft_count_word(str) + 1) * sizeof( char *));
	if (!arr)
		return (NULL);
	while (*str)
	{
		while (*str && ft_is_space(*str))
			str++;
		if (*str && !ft_is_space(*str))
		{
			arr[i] = ft_malloc_word(str);
			i++;
			while (*str && !ft_is_space(*str))
				str++;
		}

	}
	arr[i] = NULL;
	return (arr);
}
