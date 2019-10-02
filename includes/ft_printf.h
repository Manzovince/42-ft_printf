/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 18:14:30 by vmanzoni          #+#    #+#             */
/*   Updated: 2019/10/02 16:13:42 by vmanzoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** -------------------------------- LIBRAIRIES ---------------------------------
*/

#include <stdarg.h>
#include <errno.h>
#include "../libft/includes/libft.h"

/*
** --------------------------------- DEFINES -----------------------------------
*/

# define PF_BUFFSIZE		2048
# define MASK(value, mask)	((value & mask) == mask)


/*
** ------------------------------- FLAGS MASK ----------------------------------
*/

# define F_HASH			(1 << 0)
# define F_SPACE		(1 << 1)
# define F_PLUS			(1 << 2)
# define F_MINUS    	(1 << 3)
# define F_ZERO			(1 << 4)
# define F_WILDCARD		(1 << 5)
# define F_LONGD		(1 << 6)
# define F_SHORT		(1 << 7)
# define F_SHORT2		(1 << 8)
# define F_LONG	 		(1 << 9)
# define F_LONG2		(1 << 10)
# define F_COLOR		(1 << 11)
# define F_SIZE_T		(1 << 12)
# define F_MIN_LEN		(1 << 13)
# define F_PRECI		(1 << 14)
# define F_POINTER		(1 << 15)

/*
** --------------------------------- STRUCTURES --------------------------------
*/

typedef struct	s_printf
{
	char		*format;
	char		*buf;
	va_list		ap;
	size_t		i;		// ptr position in format
	size_t		b;		// ptr position in buffer
	int			flag;
	int			fd;
	int			wildcard;
	int			afterpoint;
	char		c;
}				t_printf;

/*
** ------------------------------- MAIN FUNCTIONS ------------------------------
*/

int		ft_printf(const char *format, ...);
int		ft_sprintf(char *buffer, const char *format, ...);
int		ft_dprintf(int fd, const char *format, ...);

/*
** ------------------------------ BUFFER FUNCTIONS -----------------------------
*/

void	putcharbuf(t_printf *p, char new);
void	putstrbuf(t_printf *p, char *new);

/*
** ------------------------------- FLAGS FUNCTIONS -----------------------------
*/

void	parse_flags(t_printf *p);
void	pf_getflags(t_printf *p);
void	pf_getlenmod(t_printf *p);
void	pf_getprecision(t_printf *p);
void	pf_wildcard(t_printf *p, int len);
void	apply_flag(t_printf *p, char *new);
void 	update_flag(t_printf *p, int flag);

/*
** ------------------------------- ERROR FUNCTIONS -----------------------------
*/

void	print_error();

/*
** ------------------------------ NUMBER FUNCTIONS -----------------------------
** %d %D %i %f %F %b %B %o %O %u %U %h %H %s %S %c %C
*/

void	pf_nbr_conv(t_printf *p);

/*
** ------------------------------- STR FUNCTIONS -------------------------------
** %c %s
*/

void	pf_str_conv(t_printf *p);

/*
** ------------------------------------ COLOR ----------------------------------
**  %{red} %{green} %{yellow} %{blue} %{purple} %{cyan} %{eoc}
*/

void	pf_getcolor(t_printf *p);
int		pf_putcolor(t_printf *p, char *color);

#endif
