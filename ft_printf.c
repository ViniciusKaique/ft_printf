/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinpache <vinpache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 11:10:31 by vinpache          #+#    #+#             */
/*   Updated: 2025/07/29 15:20:37 by vinpache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(char c)
{
	int	len;

	len = write(1, &c, 1);
	return (len);
}

int	ft_print_ptr(va_list *ptr)
{
	unsigned long int	address;
	int					len;

	address = va_arg(*ptr, unsigned long int);
	if (address == 0)
		len = write(1, "(nil)", 5);
	else
	{
		len = write(1, "0x", 2);
		len += ft_print_adr(address);
	}
	return (len);
}

int	ft_checker(char c, va_list *ptr)
{
	int					len;

	len = 0;
	if (c == 'c')
		len += ft_print_char(va_arg(*ptr, int));
	else if (c == 's')
		len += ft_print_str(va_arg(*ptr, char *));
	else if (c == 'd' || c == 'i')
		len += ft_print_number(va_arg(*ptr, int));
	else if (c == 'u')
		len += ft_print_unsigned(va_arg(*ptr, unsigned int));
	else if (c == 'x')
		len += ft_print_hex(va_arg(*ptr, unsigned int), 1);
	else if (c == 'X')
		len += ft_print_hex(va_arg(*ptr, unsigned int), 2);
	else if (c == 'p')
		len += ft_print_ptr(ptr);
	else if (c == '%')
		len += write(1, "%", 1);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	int		i;
	va_list	ptr;

	len = 0;
	i = 0;
	va_start(ptr, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			len += ft_checker(*format, &ptr);
		}
		else
			len += write(1, format, 1);
		format++;
	}
	va_end(ptr);
	return (len);
}
