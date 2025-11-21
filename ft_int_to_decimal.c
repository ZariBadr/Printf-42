/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_to_decimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 17:37:34 by bzari             #+#    #+#             */
/*   Updated: 2025/11/21 18:00:30 by bzari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static int      ft_intlen(int n)
{
        unsigned int    len;

        len = 0;
        if (n <= 0)
                len = 1;
        while (n)
        {
                n /= 10;
                len++;
        }
        return (len);
}

char	*ft_char(char *s,int l, unsigned int n)
{
	while (n > 0)
	{
		s[l--] = (n % 10) + '0';
		n /= 10;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	char				*s;
	int				len;
	unsigned int			number;
	int				sign;

	sign = 1;
	len = ft_intlen(n);
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (!(s))
		return (NULL);
	s[len--] = '\0';
	if (n == 0)
		s[0] = '0';
	if (n < 0)
	{
		sign *= -1;
		number = n * -1;
		s[0] = '-';
	}
	else
		number = n;
	s = ft_char(s, number, len);
	return (s);
}

int	ft_putnbr_p(int n)
{
	int	l;
	char	*num;

	num = ft_itoa(n);
	l = ft_putstr(num);
	free(num);
	return (l);
}
