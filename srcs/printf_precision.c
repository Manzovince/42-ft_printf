/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 14:25:13 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/05/20 16:42:21 by vmanzoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	get_printf_precision(t_printf *p)
{
	char	*cmin;
	char	*cmax;
	size_t	min;
	size_t	max;

	cmin = malloc(sizeof(char) * 10);
	cmax = malloc(sizeof(char) * 10);
	while (ft_isdigit(*(p->format + p->i)))
	{
		ft_strcat(cmin, p->format + p->i);
		p->i++;
	}
	min = ft_atoi(cmin);
	if (*p->format + p->i == '.')
	{
		p->i++;
		while (ft_isdigit(*(p->format + p->i)))
		{
			ft_strcat(cmax, p->format + p->i);
			p->i++;
		}
		max = ft_atoi(cmax);
		if (min > max)
			print_error();
	}
}
