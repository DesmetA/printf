/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 11:56:05 by adesmet           #+#    #+#             */
/*   Updated: 2021/10/09 14:54:08 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

# define FLAGS			"0-+ #"
# define FLAG_0 1
# define FLAG_MINUS 2
# define FLAG_PLUS 4
# define FLAG_SPACE 8
# define FLAG_HASH 16
# define SPECIFIERS		"cspdiuxX%"

typedef struct s_tag
{
	unsigned char	flag;
	int				width;
	int				precision;
	char			specifier;
}t_tag;

int		ft_printf(const char *toParse, ...);
int		ft_print(const char **toParse, va_list ap);
void	ft_get_flags(const char **toParse, t_tag *tags);
void	ft_get_width(const char **toParse, t_tag *tags, va_list ap);
void	ft_get_precision(const char **toParse, t_tag *tags, va_list ap);
void	ft_parse(const char **toParse, t_tag *tags, va_list ap);
int		ft_print_cp(t_tag tags, va_list ap);
int		ft_print_s(t_tag tags, va_list ap);
int		ft_print_di(t_tag tags, va_list ap);
int		ft_print_u(t_tag tags, va_list ap);
int		ft_print_px(t_tag tags, va_list ap);
void	ft_pad(int size, char zero_space);
char	*ft_precision(char *s, int prc);
char	*ft_width(char *s, t_tag tags);
int		ft_count_digit(unsigned long long n, unsigned long long base);
char	*ft_utoa_base(unsigned long long n, char *base);
char	*ft_ditos(t_tag tags, va_list ap);
char	*ft_utos(t_tag tags, va_list ap);
char	*ft_xtos(t_tag tags, va_list ap);
char	*ft_adds(char *s, char *s2);

#endif