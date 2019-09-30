/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 18:12:04 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/09/30 15:31:24 by vmanzoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Basic version of ft_dprintf, print on given fd
*/

int		ft_dprintf(int fd, const char *format, ...)
{
	t_printf	p;

	p.format = (char *)format;
	va_start(p.ap, format);
	p.fd = fd;
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
			ft_strcat(p.buf, p.format + p.i); // REPLACE WITH PUT_IN_BUF
		p.i++;
	}
//	ft_putstr(p.buf);
	va_end(p.ap);
	return (0);
}
