/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 01:19:46 by adesmet           #+#    #+#             */
/*   Updated: 2021/10/08 01:12:14 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

void	ft_pad(int size, char zero_space)
{
	int	i;

	i = -1;
	while (++i < size)
		write(1, &zero_space, 1);
}

int	ft_count_digit(unsigned long long n, unsigned long long base)
{
	int	i;

	i = 1;
	while (n >= base)
	{
		n /= base;
		i++;
	}
	return (i);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

char	*ft_utoa_base(unsigned long long n, char *base)
{
	char					*ans;
	int						size;
	unsigned long long		radix;

	radix = ft_strlen(base);
	size = ft_count_digit(n, radix);
	ans = malloc((sizeof(char)) * (size + 1));
	if (!ans)
		return (NULL);
	ans[size] = '\0';
	size--;
	while (n >= radix)
	{
		ans[size--] = base[n % radix];
		n /= radix;
	}
	ans[size] = base[n % radix];
	return (ans);
}
