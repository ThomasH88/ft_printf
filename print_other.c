/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_other.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 21:40:59 by tholzheu          #+#    #+#             */
/*   Updated: 2018/11/01 09:25:40 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		putchar_printf(char c, int *count)
{
	write(1, &c, 1);
	*count = *count + 1;
}

void		putstr_printf(char *s, int *count)
{
	size_t	len;

	len = ft_strlen(s);
	write(1, s, len);
	*count = *count + len;
}

void		print_char(t_params *params, t_book *book, va_list ap, int *count)
{
	while (book->width - 1  > 0 && param_is_on(PW5, &params->flags))
	{
		putchar_printf(' ', count);
		book->width--;
	}
	putchar_printf(va_arg(ap, int), count);
	while (book->width - 1  > 0 && param_is_on(PW2, &params->flags))
	{
		putchar_printf(' ', count);
		book->width--;
	}
}

void		print_str(t_params *params, t_book *book, va_list ap, int *count)
{
	char	*str;
	int		tmp;
	size_t	len;

	str = va_arg(ap, char *);
	len = ft_strlen(str);
	(len < book->prec) ? book->prec = len : 0;
	tmp = book->width;
	while (tmp - book->prec > 0 && param_is_on(PW5, &params->flags))
	{
		putchar_printf(' ', count);
		tmp--;
	}
	write(1, str, book->prec);
	*count = *count + book->prec;
	while (book->width - book->prec > 0 && param_is_on(PW2, &params->flags))
	{
		putchar_printf(' ', count);
		book->width--;
	}
}
