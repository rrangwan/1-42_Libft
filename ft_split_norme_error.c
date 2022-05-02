/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrangwan <rrangwan@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:15:23 by rrangwan          #+#    #+#             */
/*   Updated: 2021/12/20 16:15:25 by rrangwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cnt_wrds(char const *s, char c)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			cnt++;
		i++;
	}
	return (cnt);
}


static int	ft_next_word_count(char const *s, char c, int i)
{
	int	count;

	count = 0;
	while (s[i] == c && s[i] != '\0')
	{
		i++;
	}
	while (s[i] != '\0' && s[i] != c)
	{
		count++;
		i++;
	}
	return (count);
}

static char	**ft_free(char **wrd, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(wrd[j]);
		j++;
	}
	free(wrd);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		k;
	int		i;
	int		j;
	char	**nxt_wrd;

	if (!s)
		return (NULL);
	k = 0;
	i = 0;
	nxt_wrd = (char **)malloc(sizeof(char *) * (ft_cnt_wrds(s, c) + 1));
	if (!nxt_wrd)
		return (NULL);
	while (i < ft_cnt_wrds(s, c))
	{
		j = 0;
		nxt_wrd[i] = malloc(ft_next_word_count(s, c, k) + 1);
		if (!nxt_wrd[i])
			return (ft_free(nxt_wrd, i));
		while (s[k] != '\0' && s[k] == c)
			k++;
		while (s[k] != '\0' && s[k] != c)
			nxt_wrd[i][j++] = s[k++];
		nxt_wrd[i][j] = '\0';
		i++;
	}
	nxt_wrd[i] = (NULL);
	return (nxt_wrd);
}
