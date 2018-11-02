/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 09:17:27 by tholzheu          #+#    #+#             */
/*   Updated: 2018/11/01 15:17:32 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		padding_adjustments(t_params *params, t_book *book, size_t *len)
{
	if ((param_is_on(PW3, &params->flags) || param_is_on(PW4, &params->flags))
		&& param_is_on(PW6, &params->flags))
		book->width--;
	if (param_is_on(PW0, &params->flags) && (params->type == PW3 || params->type == PW4))
		*len = *len + 2;
	else if (param_is_on(PW0, &params->flags) && params->type == PW2)
		*len = *len + 1;
	if (param_is_on(PW1, &params->flags))
		book->prec = book->width;
}

void		padding_left(t_params *params, t_book *book, size_t *len, int *count)
{
	size_t	tmp;

	padding_adjustments(params, book, len);
	while (!param_is_on(PW2, &params->flags) && book->width > book->prec && book->width > *len)
	{
		putchar_printf(' ', count);
		book->width--;
	}
	if (param_is_on(PW3, &params->flags) && params->flags < PW6 && (book->width--))
		putchar_printf(' ', count);
	if (param_is_on(PW6, &params->flags))
		putchar_printf('-', count);
	else if (param_is_on(PW4, &params->flags))
		putchar_printf('+', count);
	tmp = book->prec;
	while (tmp > *len)
	{
		putchar_printf('0', count);
		tmp--;
	}
}

void		padding_right(t_params *params, t_book *book, size_t len, int *count)
{
	while (param_is_on(PW2, &params->flags) && book->width > book->prec && book->width > len)
	{
		putchar_printf(' ', count);
		book->width--;
	}
}