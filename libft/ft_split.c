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

static int	ft_cnt_wrds(const char *str, char c)
{
	int	i;

	i = 0;
	while (*str)
	{
		while (*str && (*str == c))
			str++;
		if (*str && (*str != c))
		{
			i++;
			while (*str && (*str != c))
				str++;
		}
	}
	return (i);
}

int	ft_wrdlen(const char *str, char c)
{
	int		i;

	i = 0;
	while (*str)
	{
		if ((*str == c && (*(str - 1)) != c) || (*str != c && (*(str + 1)) == 0)
			|| (*str != c && (*(str + 1)) == c))
		{
			i++;
			return (i);
		}
		i++;
		str++;
	}
	return (i);
}

static	void	free_2d_array(char **array, int n)
{
	int	i;

	i = 0;
	while (i < n)
		free(array[i]);
	free(array);
}

char	**ft_split(const char *str, char c)
{
	int		i;
	int		words;
	int		word_len;
	char	**ret;

	words = ft_cnt_wrds(str, c);
	ret = (char **)malloc(sizeof(char *) * (words + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < words)
	{
		while (*str == c)
			str++;
		word_len = ft_wrdlen(str, c);
		ret[i] = ft_substr(str, 0, word_len);
		if (!ret[i])
			free_2d_array(ret, i);
		str += word_len;
		i++;
	}
	ret[i] = NULL;
	return (ret);
}
