/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 22:41:48 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/10/02 16:03:46 by vmanzoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	pf_str_conv(t_printf *p)
{
	if (*(p->format + p->i) == 's')
		putstrbuf(p, va_arg(p->ap, char *));
	else if (*(p->format + p->i) == 'c')
		putcharbuf(p, (char)va_arg(p->ap, unsigned));
	else if (*(p->format + p->i) == 'p')
		putcharbuf(p, (char)va_arg(p->ap, unsigned));
//	else if (*(p->format + p->i) == 'n')
//		putcharbuf(p, (char)va_arg(p->ap, unsigned));
}
