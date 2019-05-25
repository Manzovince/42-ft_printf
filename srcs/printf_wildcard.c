/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_wildcard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 14:26:50 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/05/09 22:26:02 by vmanzoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	get_printf_wildcard(t_printf *p)
{
	size_t	len;

	len = va_arg(p->ap, int);
	while (len--)
		ft_putchar(' ');
	p->format++;
}
