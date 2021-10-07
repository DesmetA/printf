/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 12:58:33 by adesmet           #+#    #+#             */
/*   Updated: 2021/10/07 23:23:33 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

char *ft_utos(t_tag tags, va_list ap)
{
    unsigned int   n;
    char        *ret;

    n = va_arg(ap, unsigned int);
    if(n == 0 && tags.precision == 0)
        ret = ft_strdup("");
    else
    {
        ret = ft_utoa_base(n, "0123456789");
        ret = ft_precision(ret, tags.precision);
        if(tags.flag & FLAG_PLUS)
            ft_strlcat("+", ret, ft_strlen(ret) + 1);
        if(tags.flag & FLAG_SPACE)
            ft_strlcat(" ", ret, ft_strlen(ret) + 1);
    }
    return  (ret);
}

int ft_print_u(t_tag tags, va_list ap)
{
    char    *ans;
    int     ret;

    ans = ft_utos(tags, ap);
    ans = ft_width(ans, tags);
    ret = write(1, ans, ft_strlen(ans));
    free(ans);
    return (ret);
}