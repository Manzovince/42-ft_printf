/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 22:44:36 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/10/02 15:26:52 by vmanzoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	pf_di_lenmod(t_printf *p)
{
	if (p->flag & F_SHORT)
		putstrbuf(p, ft_itoa((short)va_arg(p->ap, int)));
	else if (p->flag & F_SHORT2)
		putstrbuf(p, ft_itoa((int)((char)va_arg(p->ap, int))));
	else if (p->flag & F_LONG)
		putstrbuf(p, ft_itoa(va_arg(p->ap, long)));
	else if (p->flag & F_LONG2)
		putstrbuf(p, ft_itoa(va_arg(p->ap, long long)));
	else
		putstrbuf(p, ft_itoa(va_arg(p->ap, int)));
}

void	pf_ouxX_lenmod(t_printf *p)
{
	if (*(p->format + p->i) == 'o')
		putstrbuf(p, ft_itoa_base(va_arg(p->ap, int), 8));
	else if (*(p->format + p->i) == 'u')
		putstrbuf(p, ft_itoa_base(va_arg(p->ap, int), 10));
	else if (*(p->format + p->i) == 'x' || *(p->format + p->i) == 'X')
		putstrbuf(p, ft_itoa_base(va_arg(p->ap, int), 16));
}

void	pf_conv_bits(t_printf *p, unsigned int bits, int size)
{
	unsigned int	mask;

	mask = 1 << (size - 1);
	while (mask)
	{
		(bits & mask) ? putcharbuf(p, '1') : putcharbuf(p, '0');
		mask >>= 1;
	}
}

void	pf_nbr_conv(t_printf *p)
{
	if (ft_strchr("di", *(p->format + p->i)))
		pf_di_lenmod(p);
	else if (ft_strchr("ouxX", *(p->format + p->i)))
		pf_ouxX_lenmod(p);
	else if (*(p->format + p->i) == 'f')
		putstrbuf(p, ft_ftoap(va_arg(p->ap, double), p->afterpoint));
	else if (*(p->format + p->i) == 'b')
		pf_conv_bits(p, va_arg(p->ap, unsigned int), 8);
}
