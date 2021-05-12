/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesmet <adesmet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 22:35:24 by adesmet           #+#    #+#             */
/*   Updated: 2021/02/03 15:33:27 by adesmet          ###   ########.fr       */
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
		if (!(ptr = (char *)ft_calloc(sizeof(char), 1)))
			return (NULL);
		return (ptr);
	}
	if (!(ptr = ft_calloc(sizeof(char), len2 + 1)))
		return (NULL);
	i = -1;
	while (++i < len2)
		ptr[i] = s[start + i];
	return (ptr);
}
