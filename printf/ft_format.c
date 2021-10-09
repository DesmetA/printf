/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 19:09:07 by adesmet           #+#    #+#             */
/*   Updated: 2021/10/09 15:20:19 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

char	*ft_prc_is_neg(char *s, int prc)
{
	char	*ans;
	int		size;
	int		i;

	i = 0;
	size = prc - ft_strlen(s) + 1;
	ans = ft_calloc(sizeof(char), prc + 2);
	if (!ans)
		return (NULL);
	ans[0] = '-';
	while (++i <= size)
		ans[i] = '0';
	while (i <= prc)
	{
		ans[i] = s[i - size];
		i++;
	}	
	free(s);
	return (ans);
}

char	*ft_precision(char *s, int prc)
{
	char	*ans;
	int		size;
	int		i;

	i = -1;
	size = prc - ft_strlen(s);
	if (size < 0)
		return (s);
	if (s[0] == '-')
		return (ft_prc_is_neg(s, prc));
	ans = ft_calloc(sizeof(char), prc + 1);
	if (!ans)
		return (NULL);
	while (++i < size)
		ans[i] = '0';
	while (i < prc)
	{
		ans[i] = s[i - size];
		i++;
	}
	free(s);
	return (ans);
}

char	*ft_width_minus(char *s, t_tag tags)
{
	char	*ans;
	int		i;

	i = -1;
	ans = ft_calloc(sizeof(char), tags.width + 1);
	if (!ans)
		return (NULL);
	while (++i < (int)ft_strlen(s))
		ans[i] = s[i];
	while (i < tags.width)
	{
		ans[i] = ' ';
		i++;
	}
	free(s);
	return (ans);
}

char	*ft_width_reg(char *s, t_tag tags, int fill_size, char pad)
{
	char	*ans;
	int		i;

	i = -1;
	ans = ft_calloc(sizeof(char), tags.width + 2);
	if (!ans)
		return (NULL);
	if (tags.flag & FLAG_0 && s[0] == '-')
	{
		ans[0] = '-';
		fill_size++;
		i++;
	}
	while (++i < fill_size)
		ans[i] = pad;
	while (i < tags.width)
	{
		if (tags.flag & FLAG_0 && s[0] == '-')
			ans[i] = s[i - fill_size + 1];
		else
			ans[i] = s[i - fill_size];
		i++;
	}
	free(s);
	return (ans);
}

char	*ft_width(char *s, t_tag tags)
{
	char	pad;
	int		fill_size;

	fill_size = tags.width - ft_strlen(s);
	if (fill_size <= 0)
		return (s);
	if ((tags.flag & FLAG_0) && tags.precision < 0)
		pad = '0';
	else
		pad = ' ';
	if (tags.flag & FLAG_MINUS)
		return (ft_width_minus(s, tags));
	else
		return (ft_width_reg(s, tags, fill_size, pad));
}
