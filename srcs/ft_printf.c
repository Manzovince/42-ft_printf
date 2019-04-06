/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 18:12:04 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/04/05 21:33:05 by vmanzoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_parse_args(const char *format, va_list args, ...)
{
	int		i;
	int		res;

	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == "%")
		{
			i++;
			if (format[i] == "b")
			{
				// On transforme en binaire
				ft_nbtobin();
				i++;
			}
			if (format[i] == "o")
			{
				//Afficher 0 + On transforme l’entier en base 8 + 1
			}
			if (format[i] == "i" || format[i] == "d")
			{
				//On transforme en base 10
			}
			if (format[i] == "u")
			{
				//On cast en unsigned int + On transforme en base 10
			}
			if (format[i] == "X")
			{
				//On écrit 0x + On transforme l’entier en base 16 + 2
			}
			if (format[i] == "c")
			{
				//putchar
			}
			if (format[i] == "s")
			{
				//putstr
			}
			if (format[i] == "%")
			{
				//Afficher %
			}
			else
				//Afficher %
		}
	}
}

int		ft_printf(const char *format, ...)
{
	t_printf	p;

	ft_bzero(&p, sizeof(p));
	p.fd = 1;
	p.format = (char *)format;
	va_start(p.param, format);
	while (*p.format)
	{
		if (*p.format == '%')
		{
			++p.format;
			parse_optionals(&p);
		}
		else
			buffer(&p, &*p.format, 1);
		++p.format;
	}
	write(p.fd, p.buff, p.buffer_index);
	va_end(p.param);
	return (p.len);
}
