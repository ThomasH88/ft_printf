/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 20:45:36 by tholzheu          #+#    #+#             */
/*   Updated: 2018/11/02 16:33:36 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		handle_other(t_params *params, t_book *book, va_list ap, int *count)
{
	if (params->type == PW6)
		print_str(params, book, ap, count);
	else if (params->type == PW7)
		print_char(params, book, ap, count);
	else if (param_is_on(PW6, &params->lmod))
		print_special_char(params, book, ap, count);
	else if (param_is_on(PW7, &params->lmod))
		print_special_str(params, book, ap, count);
}

static void		handle_signed(t_params *params, t_book *book, va_list ap, int *count)
{
	long long	nb;
	size_t		len;

	if (params->lmod == 0)
		nb = va_arg(ap, int);
	else
		nb = lmod_signed(params, ap);
	if (nb == 0 && param_is_on(PW5, &params->flags) && book->prec == 0)
		return ;
	if (nb < 0)
		set_params(PW6, &params->flags);
	len = signed_nb_size(nb);
	padding_left(params, book, len, count);
	print_signed(nb, count);
	padding_right(params, book, len, count);
}

static void		handle_unsigned(t_params *params, t_book *book, va_list ap, int *count)
{
	unsigned long long	nb;
	size_t				len;
	int					base;
	int					door;

	door = 1;
	base = 10;
	if (params->type == PW5)
	{
		nb = va_arg(ap, unsigned long);
		set_params(PW0, &params->flags);
	}
	else if (params->lmod == 0)
		nb = va_arg(ap, unsigned int);
	else
		nb = lmod_unsigned(params, ap);
	if (nb == 0 && (params->type == PW3 || params->type == PW4)
		&& param_is_on(PW5, &params->flags) && book->prec == 0)
		door = 0;
	if (nb == 0 && params->type >= PW2 && params->type <= PW4)
		set_params(PW7, &params->flags);
	if (param_is_on(PW7, &params->flags) && param_is_on(PW5, &params->flags) && book->prec == 0)
		len = 0;
	else
		set_unsigned_len_and_base(params, nb, &len, &base);
	padding_left(params, book, len, count);
	if (door)
		print_unsigned(nb, base, params, count);
	padding_right(params, book, len, count);
}

void			print_conv(t_params *params, t_book *book, va_list ap, int *count)
{
	if (params->type == 0)
		return ;
	if (params->type >= PW6 || params->lmod >= PW7)
		handle_other(params, book, ap, count);
	else if (params->type == PW0)
		handle_signed(params, book, ap, count);
	else
		handle_unsigned(params, book, ap, count);
}
