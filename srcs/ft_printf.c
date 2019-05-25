/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 18:12:04 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/05/09 22:31:54 by vmanzoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Basic version of ft_printf, print on standart output (fd = 1)
*/

int		ft_printf(const char *format, ...)
{
	t_printf	p;

	p.format = (char *)format;
	va_start(p.ap, format);
	p.fd = 1;
	p.i = 0;
	while (*(p.format + p.i))
	{
		if (*(p.format + p.i) == '%')
		{
			p.i++;
			if (!*(p.format + p.i))
				break ;
			else
				parse_flags(&p);
		}
		else
			ft_putchar(*(p.format + p.i)); // REPLACE WITH PUT_IN_BUF
		p.i++;
	}
//	ft_putstr(p.buf);
	va_end(p.ap);
	return (0);
}
