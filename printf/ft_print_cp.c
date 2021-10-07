/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:43:58 by adesmet           #+#    #+#             */
/*   Updated: 2021/10/07 23:23:33 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

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
