/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 18:12:04 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/09/30 15:32:20 by vmanzoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Basic version of ft_sprintf, print on given buffer
*/

int		ft_sprintf(char *buffer, const char *format, ...)
{
	t_printf	p;

	ft_bzero(&p, sizeof(p));
	va_start(p.ap, format);
	p.format = (char *)format;
	p.buf = malloc(sizeof(char) * PF_BUFFSIZE);
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
			putcharbuf(&p, *(p.format + p.i));
		p.i++;
	}
	ft_putstr(p.buf); // CHANGE THIS
	va_end(p.ap);
	return (p.b);
}
