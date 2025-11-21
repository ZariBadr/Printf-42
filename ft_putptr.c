/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 21:13:00 by bzari             #+#    #+#             */
/*   Updated: 2025/11/21 21:46:36 by bzari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_lenptr(uintptr_t n)
{
	int	l;

	l = 0;
	while (n != 0)
	{
		l++;
		n /= 16;
	}
	return (l);
}

void	ft_ptr(uintptr_t n)
{
	if (n >= 16)
	{
		ft_ptr(n / 16);
		ft_ptr(n % 16);
	}
	else 
	{
		if (nb <= 9)
			ft_putchar(n + '0');
		else
			ft_putchar("0123456789abcdef"[nb]);
	}
}

int	ft_putptr(uintptr_t p)
{
	int	printed;

	printed = 0;
	printed += write(1,"0x",2);
	if (p == 0)
		printed += write(1, "0", 1);
	else
	{
		ft_ptr(p);
		printed += ft_lenptr(p);
	}
	return (printed);
}
