/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 17:21:57 by adesmet           #+#    #+#             */
/*   Updated: 2021/10/09 15:04:56 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

char	*ft_ditos(t_tag tags, va_list ap)
{
	int		n;
	char	*ret;

	n = va_arg(ap, int);
	if (n == 0 && tags.precision == 0)
		ret = ft_strdup("");
	else
	{
		ret = ft_itoa(n);
		ret = ft_precision(ret, tags.precision);
		if ((tags.flag & FLAG_PLUS) && n >= 0)
			ret = ft_adds(ret, "+");
		if ((tags.flag & FLAG_SPACE) && n >= 0)
			ret = ft_adds(ret, " ");
	}
	return (ret);
}

int	ft_print_di(t_tag tags, va_list ap)
{
	char	*ans;
	int		ret;

	ans = ft_ditos(tags, ap);
	ans = ft_width(ans, tags);
	ret = write(1, ans, ft_strlen(ans));
	free(ans);
	return (ret);
}
