/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 01:26:17 by adesmet           #+#    #+#             */
/*   Updated: 2021/10/08 20:09:54 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

int	ft_print_s(t_tag tags, va_list ap)
{
	char	*to_print;
	int		slen;

	to_print = va_arg(ap, char *);
	if (!to_print)
		to_print = "(null)";
	if (tags.precision >= 0)
		to_print = ft_substr(to_print, 0, tags.precision);
	slen = ft_strlen(to_print);
	if (tags.flag & FLAG_MINUS)
	{
		write(1, to_print, slen);
		ft_pad(tags.width - slen, ' ');
	}
	else
	{
		ft_pad(tags.width - slen, ' ');
		write(1, to_print, slen);
	}
	if (tags.precision >= 0)
		free(to_print);
	if (tags.width <= slen)
		return (slen);
	else
		return (tags.width);
}
