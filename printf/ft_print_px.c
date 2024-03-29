/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_px.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 13:47:22 by adesmet           #+#    #+#             */
/*   Updated: 2021/10/09 15:41:06 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

char	*ft_xtos(t_tag tags, va_list ap)
{
	unsigned int	n;
	char			*ret;
	char			*base;

	n = va_arg(ap, unsigned int);
	if (tags.specifier == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n == 0 && tags.precision == 0)
		ret = ft_strdup("");
	else
	{
		ret = ft_utoa_base(n, base);
		ret = ft_precision(ret, tags.precision);
		if (tags.flag & FLAG_HASH && tags.specifier == 'x' && \
		!(ret[0] == '0' && ret[1] == '\0'))
			ret = ft_adds(ret, "0x");
		if (tags.flag & FLAG_HASH && tags.specifier == 'X' && \
		!(ret[0] == '0' && ret[1] == '\0'))
			ret = ft_adds(ret, "0X");
	}
	return (ret);
}

char	*ft_ptos(t_tag tags, va_list ap)
{
	unsigned long long	n;
	char				*ret;
	char				*ans;

	n = va_arg(ap, unsigned long long);
	if (n == 0)
		ans = ft_strdup("0x0");
	else
	{
		ret = ft_utoa_base(n, "0123456789abcdef");
		ret = ft_precision(ret, tags.precision);
		ans = ft_adds(ret, "0x");
	}
	return (ans);
}

int	ft_print_px(t_tag tags, va_list ap)
{
	char	*ans;
	int		ret;

	if (tags.specifier == 'x' || tags.specifier == 'X')
		ans = ft_xtos(tags, ap);
	else
		ans = ft_ptos(tags, ap);
	ans = ft_width(ans, tags);
	ret = write(1, ans, ft_strlen(ans));
	free(ans);
	return (ret);
}
