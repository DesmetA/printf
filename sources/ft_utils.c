/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesmet <adesmet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 01:19:46 by adesmet           #+#    #+#             */
/*   Updated: 2021/05/12 12:46:18 by adesmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

int	ft_count_digit(unsigned int n, unsigned int base)
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
	int i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

char    *ft_utoa_base(unsigned int n, char* base)
{
    char            *ans;
    int             size;
    unsigned int     radix;

    radix = ft_strlen(base);
    size = ft_count_digit(n, radix);
    if(!(ans = malloc(sizeof(char *) *(size + 1))))
        return (NULL);
    ans[size--] = '\0';
    while (n >= radix)
	{
		ans[size--] = base[n % radix];
		n /= radix;
	}
    ans[size] = base[n % radix];
	return (ans);
}
