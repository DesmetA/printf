/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesmet <adesmet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 00:34:16 by adesmet           #+#    #+#             */
/*   Updated: 2021/02/02 16:41:09 by adesmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int ans;

	if (fd < 0)
		return ;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ans = -n;
	}
	else
		ans = n;
	if (ans > 9)
	{
		ft_putnbr_fd(ans / 10, fd);
	}
	ft_putchar_fd('0' + ans % 10, fd);
}
