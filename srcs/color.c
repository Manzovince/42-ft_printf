/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 15:31:02 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/10/02 16:01:44 by vmanzoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	pf_getcolor(t_printf *p)
{
	char	color[10];
	int		i;
	int		j;

	i = p->i;
	j = 0;
	while (1)
	{
		if (!*(p->format + i))
			break ;
		if (*(p->format + i) == '}')
		{
			color[j++] = *(p->format + i);
			color[j] = '\0';
			break ;
		}
		color[j] = *(p->format + i);
		i++;
		j++;
	}
	if (pf_putcolor(p, color))
		p->i += j;
}

int		pf_putcolor(t_printf *p, char *color)
{
	if (!ft_strcmp(color, "{red}"))
		putstrbuf(p, RED);
	else if (!ft_strcmp(color, "{blue}"))
		putstrbuf(p, BLU);
	else if (!ft_strcmp(color, "{green}"))
		putstrbuf(p, GRN);
	else if (!ft_strcmp(color, "{yellow}"))
		putstrbuf(p, YEL);
	else if (!ft_strcmp(color, "{eoc}"))
		putstrbuf(p, RESET);
	else
		return (0);
	return (1);
}
