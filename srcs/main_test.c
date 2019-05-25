/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 11:00:38 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/05/20 16:41:07 by vmanzoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		main(/*int ac, char **av*/)
{
	ft_printf("noflag:		%\n\n");
	ft_printf("noflag2:	%%\n");
	ft_printf("flag_h:		%h\n");
	ft_printf("char:		%c\n", 'A');
	ft_printf("str:		%s\n", "azerty");
	ft_printf("int:		%d\n", 123);
	ft_printf("2int:		%d, %d\n", 123, 456);
	ft_printf("2str:		%s, %s\n", "123", "456");
	ft_printf("4int:		%d, %d, %d, %d\n", 123, 456, 789, 000);
	ft_printf("4str:		%s, %s, %s, %s\n", "123", "456", "789", "000");
	ft_printf("%d\n", ft_printf("test_len:	"));
	ft_printf("wc:		-%*s-\n", 4, "spaces");
	ft_printf("pre:		-%14.12s-\n", "test");

	return (0);
}
