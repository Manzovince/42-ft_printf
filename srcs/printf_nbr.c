/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 22:44:36 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/09/13 21:28:17 by vmanzoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_printf_nbr(t_printf *p)
{
	if (*(p->format + p->i) == 'd' || *(p->format + p->i) == 'i')
		putstrbuf(p, ft_itoa(va_arg(p->ap, int)));
	if (*(p->format + p->i) == 'f')
		putstrbuf(p, ft_ftoap(va_arg(p->ap, double), p->afterpoint));
//	if (*(p->format + p->i) == 'b')
//		ft_print_bits(va_arg(p->ap, int), 16);
}
