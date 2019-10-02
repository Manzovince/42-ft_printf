/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_wildcard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 14:58:18 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/09/23 13:21:23 by vmanzoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	pf_wildcard(t_printf *p, int len)
{
	int		i;

	if (p->wildcard > len)
	{
		p->flag -= F_WILDCARD;
		i = p->wildcard - len;
		(p->flag & F_PLUS) ? i-- : 0;
		if (p->flag & F_ZERO)
		{
			while (i--)
				*(p->buf + p->b++) = '0';
		}
		else
		{
			while (i--)
				*(p->buf + p->b++) = ' ';
		}
		p->wildcard = 0;
	}
}
