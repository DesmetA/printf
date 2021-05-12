/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesmet <adesmet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 12:58:33 by adesmet           #+#    #+#             */
/*   Updated: 2021/05/05 16:45:00 by adesmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

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