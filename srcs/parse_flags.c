/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 09:24:25 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/09/17 13:31:20 by vmanzoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	parse_flags(t_printf *p)
{
	if (*(p->format + p->i) == '%')
	{
		putcharbuf(p, '%');
		return ;
	}
	if (ft_strchr("-0+ #*", *(p->format + p->i)))
		pf_getflags(p);
	p->afterpoint = 6;
	if (ft_isdigit(*(p->format + p->i)) || *(p->format + p->i) == '.')
		pf_precision(p);
	if (ft_strchr("cCsSn", *(p->format + p->i)))
		ft_printf_str(p);
	else if (ft_strchr("dioOxXuUfFeEgGb", *(p->format + p->i)))
		ft_printf_nbr(p);
	else
		ft_putstr("Error (parsing)");
}
