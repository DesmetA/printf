/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesmet <adesmet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 01:21:23 by adesmet           #+#    #+#             */
/*   Updated: 2021/02/03 14:58:50 by adesmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*ans;

	if (!(ans = (t_list*)malloc(sizeof(t_list *))))
		return (NULL);
	ans->content = content;
	ans->next = NULL;
	return (ans);
}
