/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesmet <adesmet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:43:58 by adesmet           #+#    #+#             */
/*   Updated: 2021/05/13 01:19:01 by adesmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int ft_print_cp(t_tag tags, va_list ap)
{
    char toPrint;

    if(tags.specifier == '%')
    {
        write(1, "%", 1);
        return (1);
    }
    toPrint = (char)va_arg(ap, int);
    if(tags.flag & FLAG_MINUS && tags.width > 1)
    {
        write(1, &toPrint, 1);
        ft_pad(tags.width - 1, ' ');
        return (tags.width);
    }
    else if(tags.width > 1)
    {
        ft_pad(tags.width - 1, ' ');
        write(1, &toPrint, 1);
        return (tags.width);
    }
    write(1, &toPrint, 1);
    return (1);
}
