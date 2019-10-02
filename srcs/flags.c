/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 14:26:50 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/10/02 13:49:53 by vmanzoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Update the flag by adding with bitwise operation
*/

void	update_flag(t_printf *p, int flag)
{
	p->flag |= flag;
	p->i++;
}

/*
** Get all flags after %
*/

void	pf_getflags(t_printf *p)
{
	p->flag = 0;
	while (ft_strchr("-0+ #*", *(p->format + p->i)))
	{
		if (*(p->format + p->i) == '+')
			update_flag(p, F_PLUS);
		if (*(p->format + p->i) == ' ')
			update_flag(p, F_SPACE);
		if (*(p->format + p->i) == '-')
			update_flag(p, F_MINUS);
		if (*(p->format + p->i) == '0')
			update_flag(p, F_ZERO);
		if (*(p->format + p->i) == '#')
			update_flag(p, F_HASH);
		if (*(p->format + p->i) == '*')
		{
			update_flag(p, F_WILDCARD);
			p->wildcard = va_arg(p->ap, int);
		}
	}
	return ;
}

/*
** Get length modifier
*/

void	pf_getlenmod(t_printf *p)
{
	if (*(p->format + p->i) == 'l')
	{
		if (*(p->format + p->i + 1) == 'l')
		{
			update_flag(p, F_LONG2);
			p->i++;
		}
		else
			update_flag(p, F_LONG);
	}
	else if (*(p->format + p->i) == 'h')
	{
		if (*(p->format + p->i + 1) == 'h')
		{
			update_flag(p, F_SHORT2);
			p->i++;
		}
		else
			update_flag(p, F_SHORT);
	}
	else if (*(p->format + p->i) == 'L')
		update_flag(p, F_LONGD);
	ft_putchar(*(p->format + p->i));
	return ;
}

/*
** Apply behavior depending of flags
*/

void	apply_flag(t_printf *p, char *new)
{
	if (new[0] == '-' && (p->flag & F_ZERO))
	{
		*(p->buf + p->b++) = '-';
		p->flag ^= F_PLUS;
	}
	else if (MASK(p->flag, (F_PLUS | F_ZERO)))
	{
		*(p->buf + p->b++) = '+';
		p->flag ^= F_PLUS;
		p->wildcard--;
	}
	if ((p->flag & F_WILDCARD) && !(p->flag & F_MINUS))
	{
		pf_wildcard(p, ft_strlen(new));
	}
	(p->flag & F_PLUS) ? *(p->buf + p->b++) = '+' : 0;
}
