/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 22:48:18 by bzari             #+#    #+#             */
/*   Updated: 2025/11/21 22:59:03 by bzari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_hexlen(unsigned int	n)
{
	int	l;

	l = 0;
	while (n != 0)
	{
		n /= 16;
		l++;
	}
	return (l);
}

void	ft_hex(unsigned int n, const char str)
{
	if (n >= 16)
	{
		ft_hex(n / 16, str);
		ft_hex(n % 16, str);
	}
	else
	{
		if (n <= 9)
			ft_putchar(n + '0');
		else
		{
			if (str == 'x')
				ft_putchar("0123456789abcdef"[n]);
			if (str == 'X')
				ft_putchar("0123456789ABCDEF"[n]);
		}
	}
}

int ft_puthex(unsigned int n, const char str)
{
	if (n == 0)
		return (write(1,'0',1));
	else
		ft_hex(n,str);
	return (ft_hexlen(n));
}
