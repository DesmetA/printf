/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesmet <adesmet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 01:26:17 by adesmet           #+#    #+#             */
/*   Updated: 2021/05/05 16:21:56 by adesmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

int ft_print_s(t_tag tags, va_list ap)
{
    char    *toPrint;
    int     slen;

    toPrint = (char*)va_arg(ap, char *);
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