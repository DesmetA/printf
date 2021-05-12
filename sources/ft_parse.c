/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesmet <adesmet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 00:31:17 by adesmet           #+#    #+#             */
/*   Updated: 2021/05/12 12:02:24 by adesmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

void ft_get_flags(const char **toParse, t_tag *tags)
{
    while (**toParse && ft_strchr(FLAGS, **toParse))
    {
        if (**toParse == '0')
            tags->flag |= FLAG_0;
        if (**toParse == '-')
            tags->flag |= FLAG_MINUS;
        (*toParse)++;
    }
    if (tags->flag & FLAG_MINUS)
        tags->flag &= ~FLAG_0;
}

void ft_get_width(const char **toParse, t_tag *tags, va_list ap)
{
    int width;

    width = 0;
    if (**toParse == '*')
    {
        width = va_arg(ap, int);
        if (width < 0)
        {
            tags->flag |= FLAG_MINUS;
            tags->flag &= ~FLAG_0;
            tags->width = -width;
        }
        else
            tags->width = width;
        (*toParse)++;
    }
    else
    {
        while(ft_isdigit(**toParse))
        {
            width = (width * 10) + **toParse - '0';
            (*toParse)++;
        }
        tags->width = width;
    }
}

void ft_get_precision(const char **toParse, t_tag *tags, va_list ap)
{
    int precision;

    if (**toParse != '.')
        return ;
    (*toParse)++;
    if (**toParse == '*')
    {
        tags->precision = va_arg(ap, int);
        (*toParse)++;
    }    
    else
    {
        precision = 0;
        while(ft_isdigit(**toParse))
        {
            precision = (precision * 10) + **toParse - '0';
            (*toParse)++;
        }
        tags->precision = precision;
    }
}

void     ft_parse(const char **toParse, t_tag *tags, va_list ap)
{
    (*toParse)++;
    tags->flag = 0;
    tags->width = 0;
    tags->precision = -1;
    while(ft_isdigit(**toParse) || ft_strchr("-.*", **toParse))
    {
        ft_get_flags(toParse, tags);
        ft_get_width(toParse, tags, ap);
        ft_get_precision(toParse, tags, ap);
    }
    tags->specifier = *(ft_strchr(SPECIFIERS,**toParse));
    if(tags->precision >= 0 && tags->flag & FLAG_0)
        tags->flag &= ~FLAG_0;
}