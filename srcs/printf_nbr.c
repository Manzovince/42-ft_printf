/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 22:44:36 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/05/20 16:27:51 by vmanzoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_printf_nbr(t_printf *p)
{
	if (*(p->format + p->i) == 'd' || *(p->format + p->i) == 'i')
		ft_putstr(ft_itoa(va_arg(p->ap, int))); // REPLACE WITH PUT_IN_BUF
}
