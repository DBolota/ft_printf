/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dubolota <dubolota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 03:54:58 by dubolota          #+#    #+#             */
/*   Updated: 2025/05/16 04:03:32 by dubolota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>
# include <stdio.h>

int	printstr(char *str);
int	printchr(int c);
int	printnbr(int nbr);
int	printptr(unsigned long ptr);
int	baseconverter(size_t nbr, size_t base, char *bas);
int	checkformats(va_list args, char f);
int	ft_printf(const char *str, ...);

#endif