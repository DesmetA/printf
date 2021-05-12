/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesmet <adesmet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 17:21:57 by adesmet           #+#    #+#             */
/*   Updated: 2021/05/09 11:50:21 by adesmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

char *ft_ditos(t_tag tags, va_list ap)
{
    int   n;
    char        *ret;

    n = va_arg(ap, int);
    if(n == 0 && tags.precision == 0)
        ret = ft_strdup("");
    else
    {
        ret = ft_itoa(n);
        ret = ft_precision(ret, tags.precision);
    }
    return  (ret);
}

int ft_print_di(t_tag tags, va_list ap)
{
    char    *ans;
    int     ret;

    ans = ft_ditos(tags, ap);
    ans = ft_width(ans, tags);
    ret = write(1, ans, ft_strlen(ans));
    free(ans);
    return (ret);
}