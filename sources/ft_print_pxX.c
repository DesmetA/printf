/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pxX.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesmet <adesmet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 13:47:22 by adesmet           #+#    #+#             */
/*   Updated: 2021/05/05 16:43:59 by adesmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

char *ft_xtos(t_tag tags, va_list ap)
{
    unsigned int   n;
    char        *ret;
    char        *base;

    n = va_arg(ap, unsigned int);
    if(tags.specifier == 'x'|| tags.specifier == 'p')
        base = "0123456789abcdef";
    else
        base = "0123456789ABCDEF";
    if(n == 0 && tags.precision == 0)
        ret = ft_strdup("");
    else
    {
        ret = ft_utoa_base(n, base);
        ret = ft_precision(ret, tags.precision);
        if(tags.specifier == 'p')
            ft_strlcat("0x", ret, ft_strlen(ret) + 2);
    }
    return  (ret);
}

int ft_print_pxX(t_tag tags, va_list ap)
{
    char    *ans;
    int     ret;

    ans = ft_xtos(tags, ap);
    ans = ft_width(ans, tags);
    ret = write(1, ans, ft_strlen(ans));
    free(ans);
    return (ret);
}