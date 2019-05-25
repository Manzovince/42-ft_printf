/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 19:18:29 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/05/06 11:19:14 by vmanzoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include <stdarg.h>
/*
int		analyse_flag(char arg)
{
	if (ft_isalnum(arg))
		ft_putnbr(ft_atoi(arg));
	return (0);
}
*/

int		ft_printf(const char *format, ...)
{
	int			i;
	va_list		ap;

	va_start(ap, format);
	i = 0;
	while (*(format + i))
	{
		if (*(format + i) == '%')
		{
			i++;
			if (*(format + i) == 's')
				ft_putstr(va_arg(ap, char *));
			else if (*(format + i) == 'c')
				ft_putchar(va_arg(ap, unsigned));
			else if (*(format + i) == 'd')
				ft_putnbr(va_arg(ap, int));
			else
			{
				ft_putchar('%');
				ft_putchar(*(format + i));
			}
		}
		else
			ft_putchar(*(format + i));
		i++;
	}
	return (0);
}

int		main(/*int ac, char **av*/)
{
	ft_printf("noflag:		%\n");
	ft_printf("noflag2:	%%\n");
	ft_printf("char:		%c\n", 'A');
	ft_printf("str:		%s\n", "azerty");
	ft_printf("int:		%d\n", 123);
	ft_printf("2int:		%d, %d\n", 123, 456);
	return (0);
}
