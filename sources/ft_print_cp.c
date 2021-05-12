/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesmet <adesmet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:43:58 by adesmet           #+#    #+#             */
/*   Updated: 2021/05/05 17:53:16 by adesmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int ft_print_cp(t_tag tags, va_list ap)
{
    char toPrint;

    toPrint = (char)va_arg(ap, int);
    if(toPrint == '%')
    {
        write(1, &toPrint, 1);
        return (1);
    }
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
