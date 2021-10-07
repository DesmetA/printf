/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 01:26:17 by adesmet           #+#    #+#             */
/*   Updated: 2021/10/07 23:23:33 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

int ft_print_s(t_tag tags, va_list ap)
{
    char    *toPrint;
    int     slen;

    toPrint = (char*)va_arg(ap, char *);
    if(!toPrint && (tags.precision >= 6 || tags.precision < 0))
        toPrint = "(null)";
    else if (!toPrint)
        toPrint = ft_strdup("");
    if(tags.precision >= 0)
        toPrint = ft_substr(toPrint,0,tags.precision);
    slen = ft_strlen(toPrint);
    if(tags.flag & FLAG_MINUS)
    {
        write(1, toPrint, slen);
        ft_pad(tags.width - slen, ' ');
    }
    else
    {
        ft_pad(tags.width - slen, ' ');
        write(1, toPrint, slen);
    }
    return (tags.width<=slen ? slen : tags.width);
}