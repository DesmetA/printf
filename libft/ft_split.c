/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesmet <adesmet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 20:33:37 by adesmet           #+#    #+#             */
/*   Updated: 2021/02/05 02:34:34 by adesmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_del_count(char const *s, char c)
{
	size_t	count;
	size_t	i;

	i = -1;
	count = 0;
	if (!s)
		return (0);
	while (s[++i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
		if (!s[i])
			break ;
	}
	return (count);
}

size_t			ft_word_size(char const *s, char c, int count)
{
	int i;

	i = count;
	while (s[i] != c && s[i])
		i++;
	return (i - count);
}

static	void	ft_free(char **ans, size_t i)
{
	while (i--)
		free(ans[i]);
	free(ans);
}

char			**ft_split(char const *s, char c)
{
	int		i;
	size_t	k;
	size_t	size;
	char	**ans;

	i = 0;
	k = -1;
	size = ft_del_count(s, c) + 1;
	if (!s || !(ans = (char **)ft_calloc(sizeof(char *), size)))
		return (NULL);
	while (++k < size - 1)
	{
		while (s[i] == c && s[i])
			i++;
		if (!(ans[k] = ft_substr(s, i, ft_word_size(s, c, i))))
		{
			ft_free(ans, k);
			return (NULL);
		}
		i += ft_word_size(s, c, i);
	}
	ans[k] = NULL;
	return (ans);
}
