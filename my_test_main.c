/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 11:00:38 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/10/02 16:24:27 by vmanzoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

void	compare_printf()
{
	char buf[2048];

	ft_printf("			PRINTF		|	FT_PRINTF\n");
	ft_printf("---------------------------------------------------------------------------------------\n");

	ft_printf("-----------------------------------------BASIC-----------------------------------------\n");

	ft_printf("-blabla-:");
	sprintf(buf, "		-blabla-");
	ft_printf("%s		-blabla-\n", buf);

	ft_printf("noflag:");
	sprintf(buf, "			-%%-");
	ft_printf("%s			-%%-\n", buf);

	ft_printf("%%c:");
	sprintf(buf, "			-%c-", 'A');
	ft_printf("%s			-%c-\n", buf, 'A');

	ft_printf("%%s:");
	sprintf(buf, "			-%s-", "azerty");
	ft_printf("%s		-%s-\n", buf, "azerty");

	ft_printf("%%d:");
	sprintf(buf, "			-%d-", 123);
	ft_printf("%s			-%d-\n", buf, 123);

	ft_printf("%%i:");
	sprintf(buf, "			-%i-", 123);
	ft_printf("%s			-%i-\n", buf, 123);

	ft_printf("%%o:");
	sprintf(buf, "			-%o-", 123);
	ft_printf("%s			-%o-\n", buf, 123);

	ft_printf("%%u:");
	sprintf(buf, "			-%u-", 123);
	ft_printf("%s			-%u-\n", buf, 123);

	ft_printf("%%x:");
	sprintf(buf, "			-%x-", 123);
	ft_printf("%s			-%x-\n", buf, 123);

	ft_printf("%%X:");
	sprintf(buf, "			-%X-", 123);
	ft_printf("%s			-%X-\n", buf, 123);

	ft_printf("2_char:");
	sprintf(buf, "			-%c-%c-", 'A', 'B');
	ft_printf("%s			-%c-%c-\n", buf, 'A', 'B');

	ft_printf("2_int:");
	sprintf(buf, "			-%d-%d-", 123, 456);
	ft_printf("%s		-%d-%d-\n", buf, 123, 456);

	ft_printf("2_float:");
	sprintf(buf, "		-%f-%f-", 3.1415, 1.23);
	ft_printf("%s	-%f-%f-\n", buf, 3.1415, 1.23);

	ft_printf("2_str:");
	sprintf(buf, "			-%s-%s-", "123", "456");
	ft_printf("%s		-%s-%s-\n", buf, "123", "456");

	ft_printf("1int_1str:");
	sprintf(buf, "		-%d-%s-", 123, "456");
	ft_printf("%s		-%d-%s-\n", buf, 123, "456");

	ft_printf("1str_1int:");
	sprintf(buf, "		-%s-%d-", "123", 456);
	ft_printf("%s		-%s-%d-\n", buf, "123", 456);

	ft_printf("\n------------------------------------------FLAGS----------------------------------------\n");

	ft_printf("return value:");
	sprintf(buf, "	{%d}", sprintf(buf, "Test"));
	ft_printf("%s			{%d}\n", buf, ft_printf("Test"));

	ft_printf("%%10c:");
	sprintf(buf, "			-%10c-", 'A');
	ft_printf("%s		-%10c-\n", buf, 'A');

	ft_printf("%%13d:");
	sprintf(buf, "			-%13d-", 123);
	ft_printf("%s		-%13d-\n", buf, 123);

	ft_printf("%%*s (10):");
	sprintf(buf, "		-%*s-", 10, "spaces");
	ft_printf("%s		-%*s-\n", buf, 10, "spaces");

	ft_printf("%%-*s (11):");
	sprintf(buf, "		-%-*s-", 11, "spaces");
	ft_printf("%s		-%-*s-\n", buf, 11, "spaces");

	ft_printf("%%*d (12):");
	sprintf(buf, "		-%*d-", 12, 123);
	ft_printf("%s		-%*d-\n", buf, 12, 123);

	ft_printf("%%-15.4f:");
	sprintf(buf, "		-%-15.4f-", 3.141592);
	ft_printf("%s	-%-15.4f-\n", buf, 3.141592);

	ft_printf("%%05d:");
	sprintf(buf, "			-%05d-", 123);
	ft_printf("%s			-%05d-\n", buf, 123);

	ft_printf("%%5d:");
	sprintf(buf, "			-%5d-", 123);
	ft_printf("%s			-%5d-\n", buf, 123);

	ft_printf("%%+5d:");
	sprintf(buf, "			-%+5d-", 123);
	ft_printf("%s			-%+5d-\n", buf, 123);

	ft_printf("%% 5d:");
	sprintf(buf, "			-% 5d-", 123);
	ft_printf("%s			-% 5d-\n", buf, 123);

	ft_printf("%%+5d:");
	sprintf(buf, "			-%+5d-", 123);
	ft_printf("%s			-%+5d-\n", buf, 123);

	ft_printf("%%+05d:");
	sprintf(buf, "			-%+05d-", -123);
	ft_printf("%s			-%+05d-\n", buf, -123);

	ft_printf("%%d:");
	sprintf(buf, "			-%d-", -123);
	ft_printf("%s			-%d-\n", buf, -123);

	ft_printf("%%+05d:");
	sprintf(buf, "			-%+05d-", 123);
	ft_printf("%s			-%+05d-\n", buf, 123);

	ft_printf("%%.4d:");
	sprintf(buf, "			-%.4f-", 1.3);
	ft_printf("%s		-%.4f-\n", buf, 1.3);

	ft_printf("%%3.4f:");
	sprintf(buf, "			-%3.4f-", 1.23456789);
	ft_printf("%s		-%3.4f-\n", buf, 1.23456789);

	ft_printf("%%3.4f:");
	sprintf(buf, "			-%3.4f-", 1234.56789);
	ft_printf("%s		-%3.4f-\n", buf, 1234.56789);

	ft_printf("%%+.3f:");
	sprintf(buf, "			-%+.3f-", 2.5);
	ft_printf("%s		-%+.3f-\n", buf, 2.5);

	ft_printf("\n------------------------------------LENGTH MODIFIER------------------------------------\n");

	ft_printf("%%hd:");
	sprintf(buf, "			-%hd-", (short)-2);
	ft_printf("%s			-%hd-\n", buf, (short)-2);

	ft_printf("%%hhd :");
	sprintf(buf, "			-%hhd-", (char)2);
	ft_printf("%s			-%hhd-\n", buf, (char)2);

	ft_printf("%%ld :");
	sprintf(buf, "			-%ld-", (long)2);
	ft_printf("%s			-%ld-\n", buf, (long)2);

	ft_printf("%%lld :");
	sprintf(buf, "			-%lld-", (long long)2);
	ft_printf("%s			-%lld-\n", buf, (long long)2);

//	ft_printf("%%lf :");
//	sprintf(buf, "			-%lf-", (long)1.23456);
//	ft_printf("%s			-%lf-\n", buf, (long)1.23456);

//	ft_printf("%%Lf :");
//	sprintf(buf, "			-%Lf-", (long double)1.23456);
//	ft_printf("%s			-%Lf-\n", buf, (long double)1.23456);

	ft_printf("\n-----------------------------------------COLORS----------------------------------------\n");
	ft_printf("NOT WORKING ON CLASSIC PRINTF\n");

	ft_printf("red:");
	sprintf(buf, "			-{red}TEST{eoc}-");
	ft_printf("%s	-{red}TEST{eoc}-\n", buf);

	ft_printf("blue:");
	sprintf(buf, "			-{blue}TEST{eoc}-");
	ft_printf("%s	-{blue}TEST{eoc}-\n", buf);

	ft_printf("green:");
	sprintf(buf, "			-{green}TEST{eoc}-");
	ft_printf("%s	-{green}TEST{eoc}-\n", buf);

	ft_printf("yellow:");
	sprintf(buf, "			-{yellow}TEST{eoc}-");
	ft_printf("%s	-{yellow}TEST{eoc}-\n", buf);

	ft_printf("unk col:");
	sprintf(buf, "		-{unknow}TEST{eoc}-");
	ft_printf("%s	-{unknown}TEST{eoc}-\n", buf);

	ft_printf("fake col:");
	sprintf(buf, "		-{TEST}-");
	ft_printf("%s	-{TEST}-\n", buf);

	ft_printf("fake col2:");
	sprintf(buf, "		-{TEST-");
	ft_printf("%s	-{TEST-\n", buf);

	ft_printf("\n------------------------------------------BITS-----------------------------------------\n");

	ft_printf("%%b:");
	sprintf(buf, "			-%d-", 42);
	ft_printf("%s			-%b-\n", buf, 42);

	ft_printf("\n----------------------------------UNDERTEMINED BEHAVIOR--------------------------------\n");

	ft_printf("bugged:");
	sprintf(buf, "			-%%s-");
	ft_printf("%s			-%%s-\n", buf);

	ft_printf("\n\n-------------------------------------TEST FT_PRINTF-----------------------------------\n\n");

	ft_printf("%%.3e:");
	sprintf(buf, "			-%.3e-", 3.141592);
	ft_printf("%s		-%.3e-\n", buf, 3.141592);
}

int		main(/*int ac, char **av*/)
{
	compare_printf();
	return (0);
}
