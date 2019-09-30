/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 22:41:48 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/09/16 22:43:40 by vmanzoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_printf_str(t_printf *p)
{
	if (*(p->format + p->i) == 's')
		putstrbuf(p, va_arg(p->ap, char *));
	else if (*(p->format + p->i) == 'c')
		putcharbuf(p, (char)va_arg(p->ap, unsigned));
}
