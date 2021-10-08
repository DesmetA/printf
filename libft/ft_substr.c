/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 22:35:24 by adesmet           #+#    #+#             */
/*   Updated: 2021/10/08 14:23:22 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	len2;

	len2 = len;
	if (!s)
		return (NULL);
	if (ft_strlen(s) - start + 1 < len)
		len2 = ft_strlen(s) - start;
	if (ft_strlen(s) < start)
	{
		ptr = (char *)ft_calloc(sizeof(char), 1);
		if (!ptr)
			return (NULL);
		return (ptr);
	}
	ptr = ft_calloc(sizeof(char), len2 + 1);
	if (!ptr)
		return (NULL);
	i = -1;
	while (++i < len2)
		ptr[i] = s[start + i];
	free(s);
	return (ptr);
}
