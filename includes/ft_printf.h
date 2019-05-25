/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 18:14:30 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/05/09 22:47:33 by vmanzoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** -------------------------------- LIBRAIRIES ---------------------------------
*/

#include <stdarg.h>
#include "../libft/includes/libft.h"

/*
** --------------------------------- STRUCTURES --------------------------------
*/

# define BUFF_SIZE 2048


/*
** --------------------------------- STRUCTURES --------------------------------
*/

typedef struct	s_printf
{
	char		*format;
	char		buf[BUFF_SIZE];
	va_list		ap;
	size_t		i;		//ptr position in format
	int			fd;
}				t_printf;

/*
** ------------------------------- MAIN FUNCTIONS ------------------------------
*/

int		ft_printf(const char *format, ...);
void	parse_flags(t_printf *p);
void	get_printf_precision(t_printf *p);
void	get_printf_wildcard(t_printf *p);

/*
** ------------------------------- ERROR FUNCTIONS -----------------------------
*/

void	print_error();

/*
** ------------------------------ NUMBER FUNCTIONS -----------------------------
** %d %D %i %f %F %b %B %o %O %u %U %h %H %s %S %c %C
*/

void	ft_printf_nbr(t_printf *p);

/*
** ------------------------------- STR FUNCTIONS -------------------------------
** %c %s
*/

void	ft_printf_str(t_printf *p);

/*
** --------------------------------- COLOR FLAGS -------------------------------
**  %{red} %{green} %{yellow} %{blue} %{purple} %{cyan} %{eoc}
*/

void			ft_putchar_color(char c, char color);

# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define PURPLE		"\033[35m"
# define CYAN		"\033[36m"
# define EOC		"\033[36m"

#endif
