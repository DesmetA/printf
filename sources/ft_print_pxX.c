/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pxX.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesmet <adesmet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 13:47:22 by adesmet           #+#    #+#             */
/*   Updated: 2021/05/12 14:04:38 by adesmet          ###   ########.fr       */
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
    if(tags.specifier == 'x')
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
            printf("%s\n",ret);
    }
    return  (ret);
}

char *ft_ptos(t_tag tags, va_list ap)
{
    unsigned long long   n;
    char        *ret;

    n = va_arg(ap, unsigned long long);
    if(n == 0)
        ret = ft_strdup("(nil)");
    else
    {
        ret = ft_utoa_base(n, "0123456789abcdef");
        ret = ft_precision(ret, tags.precision);
        ret = ft_strjoin("0x", ret);
    }
    return  (ret);
}

int ft_print_pxX(t_tag tags, va_list ap)
{
    char    *ans;
    int     ret;

    if(tags.specifier == 'x' || tags.specifier == 'X')
        ans = ft_xtos(tags, ap);
    else
        ans = ft_ptos(tags, ap);
    ans = ft_width(ans, tags);
    ret = write(1, ans, ft_strlen(ans));
    free(ans);
    return (ret);
}