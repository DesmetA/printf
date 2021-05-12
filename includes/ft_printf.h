/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesmet <adesmet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 11:56:05 by adesmet           #+#    #+#             */
/*   Updated: 2021/05/05 17:40:20 by adesmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <wchar.h>

# define FLAGS			"0-"
# define FLAG_0 1
# define FLAG_MINUS 2
# define SPECIFIERS		"cspdiuxX%"

typedef struct s_tag
{
    unsigned char   flag;
    int             width;
    int             precision;
    char            specifier;

}               t_tag;

int     ft_printf(const char *, ...);
int     ft_print(const char **toParse ,va_list ap);


void ft_get_flags(const char **toParse, t_tag *tags);
void ft_get_width(const char **toParse, t_tag *tags, va_list ap);
void ft_get_precision(const char **toParse, t_tag *tags, va_list ap);
void ft_parse(const char **toParse, t_tag *tags, va_list ap);

int ft_print_cp(t_tag tags, va_list ap);
int ft_print_s(t_tag tags, va_list ap);
int ft_print_di(t_tag tags, va_list ap);
int ft_print_u(t_tag tags, va_list ap);
int ft_print_pxX(t_tag tags, va_list ap);

void    ft_pad(int size, char zero_space);
char    *ft_precision(char *s, int prc);
char    *ft_width(char *s, t_tag tags);

int	    ft_count_digit(unsigned int n, unsigned int base);
char    *ft_utoa_base(unsigned int n, char* base);

char                    *ft_ditos(t_tag tags, va_list ap);
char                    *ft_utos(t_tag tags, va_list ap);
char                    *ft_xtos(t_tag tags, va_list ap);

#endif