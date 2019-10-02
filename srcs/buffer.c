/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 09:24:17 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/10/02 14:46:03 by vmanzoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	putcharbuf(t_printf *p, char new)
{
	((p->flag & F_WILDCARD) && !(p->flag & F_MINUS)) ? pf_wildcard(p, 1) : 0;
	*(p->buf + p->b++) = new;
	(p->flag & (F_MINUS | F_WILDCARD)) ? pf_wildcard(p, 1) : 0;
	p->b = ft_strlen(p->buf);
}

void	putstrbuf(t_printf *p, char *new)
{
	size_t	i;

	i = 0;
	apply_flag(p, new);
	(new[i] == '-' && (p->flag & F_ZERO)) ? i++ : 0;
	while (new[i])
		*(p->buf + p->b++) = new[i++];
	(MASK(p->flag,(F_MINUS | F_WILDCARD))) ? pf_wildcard(p, ft_strlen(new)) : 0;
	p->b = ft_strlen(p->buf);
}

/*
**int		main(int ac, char **av)
**{
**	t_printf	p;
**	size_t		i;
**	size_t		j;
**	char		str[100];
**
**	ft_bzero(&p, sizeof(t_printf));
**	i = 0;
**	p.b = 0;
**	while (++i < ac)
**	{
**		j = 0;
**		while (av[i][j] != '\0')
**		{
**			str[j] = av[i][j];
**			j++;
**		}
**		printf("arg:	-%s-\n", str);
**		putstrbuf(&p, str);
**		p.b = ft_strlen(p.buf);
**	}
**	printf("BUF:	-%s-", p.buf);
**	return (0);
**}
*/
