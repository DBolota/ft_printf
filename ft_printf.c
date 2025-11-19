/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dubolota <dubolota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:35:26 by dubolota          #+#    #+#             */
/*   Updated: 2025/05/15 17:35:26 by dubolota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	baseconverter(size_t nbr, size_t base, char *bas)
{
	int	total;

	total = 1;
	if (nbr >= base)
		total += baseconverter(nbr / base, base, bas);
	write(1, &bas[nbr % base], 1);
	return (total);
}

int	checkformats(va_list args, char f)
{
	if (f == 'c')
		return (printchr(va_arg(args, int)));
	else if (f == 's')
		return (printstr(va_arg(args, char *)));
	else if (f == 'p')
		return (printptr(va_arg(args, unsigned long)));
	else if (f == 'd' || f == 'i')
		return (printnbr(va_arg(args, int)));
	else if (f == 'u')
		return (baseconverter(va_arg(args, unsigned int), 10, \
		"0123456789"));
	else if (f == 'x')
		return (baseconverter(va_arg(args, unsigned int), 16, \
		"0123456789abcdef"));
	else if (f == 'X')
		return (baseconverter(va_arg(args, unsigned int), 16, \
		"0123456789ABCDEF"));
	else if (f == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		fulllenght;
	va_list	args;

	i = 0;
	fulllenght = 0;
	va_start (args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			fulllenght += checkformats(args, str[i]);
		}
		else
		{
			write(1, &str[i], 1);
			fulllenght++;
		}
		i++;
	}
	va_end (args);
	return (fulllenght);
}

/* 
int	main (void)
{
	char	c = 't';
	char	*str = "teste";
	int		nbr = 125;
	ft_printf("\nVamos testar um char: %c | uma str: %s | uma percentagem: %% |\
	um numero: %i\n um ptr: %p | um uns int: %u | um hex lowc : %x | um hex upc:\
	%X", c, str, nbr, &nbr, nbr, nbr, nbr);
	return (0);
} */

/* int main()
{
	int 	a;
	int	b;
	char	*s;

	a = ft_printf("Hello World\n");
	b = printf("Hello World\n");

	printf("%d, %d\n", a, b);

        a = ft_printf("%s\n", "Banana Frita");
        b = printf("%s\n", "Banana Frita");

        printf("%d, %d\n", a, b);

	s = NULL;
        a = ft_printf("%s\n", s);
        b = printf("%s\n", s);

        printf("%d, %d\n", a, b);

        a = ft_printf("%p\n", s);
        b = printf("%p\n", s);

        printf("%d, %d\n", a, b);
        
        a = ft_printf("%c%c%c%c\n", 'I', 'v', 'a', 'n');
        b = printf("%c%c%c%c\n", 'I', 'v', 'a', 'n');

        printf("%d, %d\n", a, b);
        
        a = ft_printf("%x\n", 0xBABACA);
        b = printf("%x\n", 0xBABACA);
        
        printf("%d, %d\n", a, b);
        
        a = ft_printf("%X\n", 0xB00B5);
        b = printf("%X\n", 0xB00B5);

        printf("%d, %d\n", a, b);
        
        a = ft_printf("%X\n", -42);
        b = printf("%X\n", -42);

        printf("%d, %d\n", a, b);
        
        a = ft_printf("%%\n");
        b = printf("%%\n");

        printf("%d, %d\n", a, b);

        a = ft_printf("\t\n\v\f\r");
        b = printf("\t\n\v\f\r");

        printf("%d, %d\n", a, b);

        a = ft_printf("");
        b = printf("");

        printf("%d, %d\n", a, b);
        
        a = ft_printf("", s, s, s);
        b = printf("", s, s, s);

        a = ft_printf("%c\n", s, s, s);
        b = printf("%c\n", s, s, s);

        a = ft_printf("%c %c %c\n", s, s, s);
        b = printf("%c %c %c\n", s, s, s);


        printf("%d, %d\n", a, b);


	return (0);
} */
