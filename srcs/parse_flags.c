/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 09:24:25 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/10/02 16:03:42 by vmanzoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Parsing flag work in this configuration :
** % [flags] [field_width] [.precision] [length_modifier] conversion_character
**
** [flags]: - 0 + ' ' # *
** [field_width]: min_field_witdh[.precision]
** [length_modifier]: h hh l ll L
** conversion_character: cCsSndiouxXOUfFeEgGb
*/

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
		pf_getprecision(p);
	if (ft_strchr("lLh", *(p->format + p->i)))
		pf_getlenmod(p);
	if (ft_strchr("csp", *(p->format + p->i)))
		pf_str_conv(p);
	else if (ft_strchr("diouxXOUfFeEgGb", *(p->format + p->i)))
		pf_nbr_conv(p);
	else
		ft_putstr("Error (parsing)");
}
