/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 09:24:25 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/05/20 17:15:28 by vmanzoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	parse_flags(t_printf *p)
{
	if (ft_isdigit(*(p->format + p->i)) || (*p->format + p->i) == '.')
		get_printf_precision(p);
	if (*(p->format + p->i) == '*')
		get_printf_wildcard(p);
	if (*(p->format + p->i) == 's')
		(p->f & F_LONG || p->f & F_LONG2) ? pf_putwstr(p) : pf_putstr(p);
	/*else if (ft_strchr("dDi", *(p->format + p->i)))
		pf_putnbr(p);
	else if (*(p->format + p->i) == 'f' || *(p->format + p->i) == 'F')
		(p->f & F_APP_PRECI && !p->precision) ? pf_putnb(p) : pf_putdouble(p);
	else if (*(p->format + p->i) == 'c' || *(p->format + p->i) == 'C')
		pf_character(p, va_arg(p->ap, unsigned));
	else if (ft_strchr("oOuUbBxX", *(p->format + p->i)))
		pf_putnb_base(ft_strchri_lu(".b..ou..x", *(p->format + p->i), -1) << 1, p);
	else if (*(p->format + p->i) == 'S')
		pf_putwstr(p);
	else if (*(p->format + p->i) == 'p')
		print_pointer_address(p);
	else if (*(p->format + p->i) == 'n')
		*va_arg(p->ap, int *) = p->len;
	else if (*(p->format + p->i) == 'm')
		ft_printf_putstr(STRERR(errno), p);
	else if (*(p->format + p->i) == '{')
		color(p);
	else
		cs_not_found(p);*/
//	else
//	{
//		ft_putchar('%'); // REPLACE WITH PUT_IN_BUF
//		ft_putchar(*(p->format + p->i)); // REPLACE WITH PUT_IN_BUF
//	}
}
