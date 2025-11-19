/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_extra_func.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dubolota <dubolota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 01:01:23 by dubolota          #+#    #+#             */
/*   Updated: 2025/05/16 04:26:07 by dubolota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printstr(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[len])
		len++;
	return (write(1, str, len));
}

int	printchr(int c)
{
	write(1, &c, 1);
	return (1);
}

int	printnbr(int nbr)
{
	if (nbr < 0)
	{
		if (nbr == -2147483648)
			return (write(1, "-2147483648", 11));
		write(1, "-", 1);
		nbr *= -1;
		return (baseconverter(nbr, 10, "0123456789") + 1);
	}
	if (nbr == 0)
		return (write(1, "0", 1));
	return (baseconverter(nbr, 10, "0123456789"));
}

int	printptr(unsigned long ptr)
{
	if (!(ptr))
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	return (baseconverter(ptr, 16, \
		"0123456789abcdef") + 2);
}
