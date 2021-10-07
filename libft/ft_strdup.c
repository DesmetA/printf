/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesmet <adesmet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 22:07:52 by adesmet           #+#    #+#             */
/*   Updated: 2021/02/02 01:25:46 by adesmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*s2;
	size_t	i;

	i = -1;
	if (!(s2 = (char *)(ft_calloc(sizeof(char), ft_strlen(s) + 1))))
		return (NULL);
	while (s[++i])
		s2[i] = s[i];
	return (s2);
}
