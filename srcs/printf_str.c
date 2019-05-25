/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 22:41:48 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/05/20 16:27:27 by vmanzoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_printf_str(t_printf *p)
{
	if (*(p->format + p->i) == 's')
		ft_putstr(va_arg(p->ap, char *)); // REPLACE WITH PUT_IN_BUF
	else if (*(p->format + p->i) == 'c')
		ft_putchar((char)va_arg(p->ap, unsigned)); // REPLACE WITH PUT_IN_BUF
	else if (*(p->format + p->i) == 'n') // Number of characters written by this printf.
		ft_putchar('0'); // REPLACE WITH PUT_IN_BUF
}
