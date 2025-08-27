/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 21:02:58 by bmoreira          #+#    #+#             */
/*   Updated: 2025/08/27 14:57:53 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_case(char *set, char c)
{
	while (*set)
		if (*set++ == c)
			return (1);
	return (0);
}

static int	put_case(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int), "0123456789", 10));
	if (c == 'u')
		return (ft_putul(va_arg(args, unsigned int), "0123456789", 10));
	if (c == 'p')
		return (ft_putptr(va_arg(args, unsigned long)));
	if (c == 'x')
		return (ft_putul(va_arg(args, unsigned int), "0123456789abcdef", 16));
	if (c == 'X')
		return (ft_putul(va_arg(args, unsigned int), "0123456789ABCDEF", 16));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count;

	va_start(args, s);
	count = 0;
	while (*s)
	{
		if (*s == '%' && check_case("cspdiuxX", *++s))
			count += put_case(*s++, args);
		else
			count += ft_putchar(*s++);
	}
	va_end(args);
	return (count);
}
