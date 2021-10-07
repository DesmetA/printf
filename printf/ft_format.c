/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 19:09:07 by adesmet           #+#    #+#             */
/*   Updated: 2021/10/07 23:23:33 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

void    ft_pad(int size, char zero_space)
{
    int i;

    i = -1;
    while(++i<size)
        write(1, &zero_space, 1);
}

char *ft_prc_is_neg(char *s, int prc)
{
    char *tmp;
    char *ans;
    int size;
    int i;

    tmp = ft_substr(s, 1, ft_strlen(s) - 1);
    size = prc - ft_strlen(tmp);
    i = -1;
    if(!(ans = ft_calloc(sizeof(char), prc + 2)))
        return (NULL);
    ans[0] = '-';
    while(++i < size)
    {
        ans[i+1] = '0';
    } 
    while(i <= prc)
    {
        ans[i+1] = tmp[i-size];
        i++;
    }
    ans[i] = '\0';
    free(s);
    return (ans);    
}


char *ft_precision(char *s, int prc)
{
    char *ans;
    int size;
    int i;

    i = -1;
    size = prc - ft_strlen(s);
    if(size < 0)
        return (s);
    if(s[0] == '-')
        return ft_prc_is_neg(s, prc);
    if(!(ans = ft_calloc(sizeof(char), prc + 1)))
        return (NULL);
    while(++i < size)
    {
        ans[i] = '0';
    } 
    while(i < prc)
    {
        ans[i] = s[i-size];
        i++;
    }
    ans[i] = '\0';
    free(s);
    return (ans);
}

char *ft_width_minus(char* s, t_tag tags)
{
    char *ans;
    int i;

    i = -1;
    if (!(ans = ft_calloc(sizeof(char), tags.width + 1)))
        return (NULL);
    while(++i < (int)ft_strlen(s))
    {
        ans[i] = s[i];
    }
    while(i < tags.width)
    {
        ans[i] = ' ';
        i++;
    }
    return (ans);
}

char *ft_width_reg(char *s, t_tag tags, int fill_size, char pad)
{
    char *ans;
    char *tmp;
    int i;
    int j;

    i = -1;
    j = 0;
    tmp = s;
    if (!(ans = ft_calloc(sizeof(char), tags.width + 2)))
        return (NULL);
    if(tags.flag & FLAG_0 && s[0] == '-')
    {
        ans[0] = '-';
        tmp = ft_substr(s, 1, ft_strlen(s) - 1);
        fill_size++;
        i++;
    }
    while(++i < fill_size)
            ans[i] = pad;
    while(i < tags.width)
    {
        ans[i] = tmp[j];
        i++;
        j++;
    }
    free(s);
    return (ans);
}
char *ft_width(char *s, t_tag tags)
{
    char pad;
    int fill_size;

    fill_size = tags.width - ft_strlen(s);
    if (fill_size <= 0)
        return (s);
    pad = ((tags.flag & FLAG_0) && tags.precision < 0) ? '0' : ' ';
    if (tags.flag & FLAG_MINUS)
        return ft_width_minus(s, tags);
    else
        return ft_width_reg(s, tags, fill_size, pad);
}
  