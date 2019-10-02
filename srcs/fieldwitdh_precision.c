/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fieldwitdh_precision.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 14:25:13 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/10/02 14:32:24 by vmanzoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Get minimal field witdh and precision
*/

void	pf_getprecision(t_printf *p)
{
	char	*c_wildcard;
	char	*c_afterpoint;

	c_wildcard = malloc(sizeof(char) * 10);
	c_afterpoint = malloc(sizeof(char) * 10);
	while (ft_isdigit(*(p->format + p->i)))
	{
		ft_strcat(c_wildcard, p->format + p->i);
		update_flag(p, F_WILDCARD);
	}
	p->wildcard = ft_atoi(c_wildcard);
	if (*(p->format + p->i) == '.')
	{
		p->i++;
		while (ft_isdigit(*(p->format + p->i)))
		{
			ft_strcat(c_afterpoint, p->format + p->i);
			p->i++;
		}
		p->afterpoint = ft_atoi(c_afterpoint);
		if (p->wildcard < p->afterpoint)
			p->wildcard = 0;
	}
}
