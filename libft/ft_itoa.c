/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrangwan <rrangwan@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:08:40 by rrangwan          #+#    #+#             */
/*   Updated: 2022/01/01 12:09:01 by rrangwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_itoa_minus(int *n, int *minus, int *temp)
{
	if (*n == -2147483648)
	{
		*n = *n + 1;
		*minus = -1;
		*temp = 1;
		*n = *n * -1;
	}
	else if (*n < 0)
	{
		*minus = -1;
		*n = *n * -1;
		*temp = 0;
	}
	else if (*n >= 0)
	{
		*minus = 1;
		*temp = 0;
	}
}

static int	ft_itoa_len(int n)
{
	int			len;

	len = 0;
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	len++;
	return (len);
}

static void	ft_itoa_write(char *finish, int len, int n, int temp)
{
	while (n > 9)
	{
		finish[len--] = (n % 10) + '0' + temp;
		n = n / 10;
		temp = 0;
	}
	finish[len] = n + '0';
}

char	*ft_itoa(int n)
{
	int			sign;
	int			temp;
	int			len;
	char		*finish;

	ft_itoa_minus(&n, &sign, &temp);
	len = ft_itoa_len(n);
	if (sign == -1)
	{
		finish = malloc((len + 2) * sizeof(char));
		if (!finish)
			return (NULL);
		len++;
		finish[0] = '-';
	}
	else
	{
		finish = malloc((len + 1) * sizeof(char));
		if (!finish)
			return (NULL);
	}
	finish[len--] = '\0';
	ft_itoa_write(finish, len, n, temp);
	return (finish);
}
