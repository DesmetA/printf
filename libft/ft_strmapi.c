/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesmet <adesmet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 00:07:14 by adesmet           #+#    #+#             */
/*   Updated: 2021/02/02 01:35:33 by adesmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*ans;

	i = -1;
	if (!s || !f)
		return (NULL);
	if (!(ans = (char *)ft_calloc(sizeof(char), ft_strlen(s) + 1)))
		return (NULL);
	while (s[++i])
	{
		ans[i] = f(i, s[i]);
	}
	ans[i] = 0;
	return (ans);
}
