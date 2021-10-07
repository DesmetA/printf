/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesmet <adesmet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 19:42:05 by adesmet           #+#    #+#             */
/*   Updated: 2021/02/02 01:43:26 by adesmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_set(char const *s, char c)
{
	size_t	i;

	i = -1;
	while (s[++i] != '\0')
		if (s[i] == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	if (!s1 || !set)
		return (NULL);
	i = -1;
	j = ft_strlen(s1);
	while (ft_is_set(set, s1[++i]))
		;
	while (ft_is_set(set, s1[--j]))
		;
	return (ft_substr(s1, i, j - i + 1));
}
