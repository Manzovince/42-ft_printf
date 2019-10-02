/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 18:12:04 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/10/02 16:48:02 by vmanzoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Basic version of ft_printf, print on standart output (fd = 1)
** % [flags] [field_width] [.precision] [length_modifier] conversion_character
*/

int		ft_printf(const char *format, ...)
{
	t_printf	p;

	ft_bzero(&p, sizeof(p));
	va_start(p.ap, format);
	p.format = (char *)format;
	p.buf = malloc(sizeof(char) * PF_BUFFSIZE);
	while (*(p.format + p.i))
	{
		(*(p.format + p.i) == '{') ? pf_getcolor(&p) : 0;
		if (*(p.format + p.i) == '%')
		{
			p.i++;
			if (!*(p.format + p.i))
				break ;
			else
				parse_flags(&p);
		}
		else
			putcharbuf(&p, *(p.format + p.i));
		p.i++;
	}
	ft_putstr(p.buf);
	va_end(p.ap);
	return (p.b);
}
