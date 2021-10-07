/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 11:55:46 by adesmet           #+#    #+#             */
/*   Updated: 2021/10/07 23:23:33 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

int     ft_print(const char **toParse ,va_list ap)
{
    t_tag tags;

    ft_parse(toParse, &tags, ap);
    if(tags.specifier == 'c' || tags.specifier == '%')
        return ft_print_cp(tags, ap);
    if(tags.specifier == 's')
        return ft_print_s(tags, ap);
    if(tags.specifier == 'p' || tags.specifier == 'x' || tags.specifier == 'X')
        return ft_print_pxX(tags, ap);
    if(tags.specifier == 'd' || tags.specifier == 'i')
        return ft_print_di(tags, ap);
    if(tags.specifier == 'u')
        return ft_print_u(tags, ap);
    return 0;
}

int     ft_printf(const char *toParse, ...)
{
    va_list ap;
    int ret;
    int ans;

    if(!toParse)
        return (-1);
    ans = 0;
    va_start(ap, toParse);
    while(*toParse)
    {
        ret = 0;
        if(*toParse == '%')
            ret = ft_print(&toParse, ap);
        else
        {
            write(1,toParse,1);
            ret++;
        }
        ans += ret;
        toParse++;
    }
    va_end(ap);
    return (ans);
}