/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinpache <vinpache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 11:16:01 by vinpache          #+#    #+#             */
/*   Updated: 2025/07/29 15:19:28 by vinpache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_print_char(char c);
int	ft_print_str(char *str);
int	ft_print_number(int nb);
int	ft_print_ptr(va_list *ptr);
int	ft_checker(char c, va_list *ptr);
int	ft_printf(const char *format, ...);
int	ft_print_adr(unsigned long int nb);
int	ft_print_unsigned(unsigned int nb);
int	ft_print_hex(unsigned int nb, int s);

#endif