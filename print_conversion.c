/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 20:45:36 by tholzheu          #+#    #+#             */
/*   Updated: 2018/11/01 20:42:45 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		handle_other(t_params *params, t_book *book, va_list ap, int *count)
{
	/*if (params->type == PW5)*/
		/*continue ;*/
		/*//print_ptr(params, book, ap, count);*/
	if (params->type == PW6)
		print_str(params, book, ap, count);
	else if (params->type == PW7)
		print_char(params, book, ap, count);
}

static void		handle_signed(t_params *params, t_book *book, va_list ap, int *count)
{
	long long	nb;
	size_t		len;

	if (params->lmod == 0)
		nb = va_arg(ap, int);
	else
		nb = lmod_signed(params, ap);
	if (nb < 0)
		set_params(PW6, &params->flags);
	len = signed_nb_size(nb);
	padding_left(params, book, &len, count);
	print_signed(nb, count);
	padding_right(params, book, len, count);
}

static void		handle_unsigned(t_params *params, t_book *book, va_list ap, int *count)
{
	unsigned long long	nb;
	size_t				len;
	int					base;

	if (params->lmod == 0)
		nb = va_arg(ap, unsigned int);
	else
		nb = lmod_unsigned(params, ap);
	set_unsigned_len_and_base(params, nb, &len, &base);
	padding_left(params, book, &len, count);
	print_unsigned(nb, base, params, count);
	padding_right(params, book, len, count);
}

void			print_conv(t_params *params, t_book *book, va_list ap, int *count)
{
	if (params->type >= PW5)
		handle_other(params, book, ap, count);
	else if (params->type == PW0)
		handle_signed(params, book, ap, count);
	else
		handle_unsigned(params, book, ap, count);
}
