/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinpache <vinpache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:21:23 by vinpache          #+#    #+#             */
/*   Updated: 2025/07/29 15:02:14 by vinpache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajaidi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:36:31 by ajaidi            #+#    #+#             */
/*   Updated: 2021/11/23 18:37:08 by ajaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_number(int nb)
{
	long long	n;
	int			len;

	n = nb;
	len = 0;
	if (n < 0)
	{
		len += write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		len += ft_print_number(n / 10);
	}
	len += ft_print_char((n % 10) + '0');
	return (len);
}

int	ft_print_adr(unsigned long int nb)
{
	int	len;

	len = 0;
	if (nb >= 16)
	{
		len += ft_print_adr(nb / 16);
	}
	if ((nb % 16) < 10)
		len += ft_print_char((nb % 16) + 48);
	else
		len += ft_print_char((nb % 16) + 87);
	return (len);
}

int	ft_print_unsigned(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb >= 10)
		len += ft_print_unsigned(nb / 10);
	len += ft_print_char((nb % 10) + '0');
	return (len);
}

int	ft_print_hex(unsigned int nb, int s)
{
	int	len;

	len = 0;
	if (nb >= 16)
		len += ft_print_hex(nb / 16, s);
	if ((nb % 16) < 10)
		len += ft_print_char((nb % 16) + 48);
	else
	{
		if (s == 1)
			len += ft_print_char((nb % 16) + 87);
		else
			len += ft_print_char((nb % 16) + 55);
	}
	return (len);
}

int	ft_print_str(char *str)
{
	int	len;

	len = 0;
	if (!str)
		str = "(null)";
	while (*str)
		len += write(1, str++, 1);
	return (len);
}
