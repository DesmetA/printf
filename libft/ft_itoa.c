/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesmet <adesmet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 11:36:17 by adesmet           #+#    #+#             */
/*   Updated: 2021/02/03 07:58:42 by adesmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_count_digit(int n)
{
	int	i;
	int	count;

	i = 0;
	if (n <= 0)
	{
		count = -n;
		i++;
	}
	else
		count = n;
	while (count > 0)
	{
		count = count / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char	*ans;
	int		size;
	long	num;

	size = ft_count_digit(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!(ans = ft_calloc(sizeof(char), size + 1)))
		return (NULL);
	if (n < 0)
	{
		ans[0] = '-';
		num = -n;
	}
	else
		num = n;
	ans[size] = '\0';
	if (num == 0)
		ans[0] = '0';
	while (num)
	{
		ans[--size] = (num % 10) + '0';
		num = num / 10;
	}
	return (ans);
}
