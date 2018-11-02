/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 20:30:39 by tholzheu          #+#    #+#             */
/*   Updated: 2018/11/01 19:11:42 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_cases(char *fmt, int *count, va_list ap)
{
	t_params	*params;
	t_book		*book;

	if (init_structs(&params, &book, 0) == -1)
		return ;
	while (*fmt)
	{
		if (*fmt == '%' && *(fmt + 1) == '%' && fmt++)
			ft_putchar('%');
			/*ft_putchar_printf('%', count);*/
		else if (*fmt == '%' && fmt++)
		{
			init_structs(&params, &book, 1);
			fmt = parsing(fmt, params, book);
			print_conv(params, book, ap, count);
		}
		else
			ft_putchar(*fmt);
			/*ft_putchar_printf(*fmt, count);*/
		fmt++;
	}
	/*write(1, "\nFlags\n", 7);*/
	/*print_bits(params->flags);*/
	/*write(1, "Lmod\n", 5);*/
	/*print_bits(params->lmod);*/
	/*write(1, "Type\n", 5);*/
	/*print_bits(params->type);*/
	/*printf("width = %lu\n", book->width);*/
	/*printf("prec = %lu\n", book->prec);*/
	va_end(ap);
}

int				ft_printf(const char *fmt, ...)
{
	va_list		ap;
	int			*count;
	int			ret;

	if (!(count = (int *)malloc(sizeof(int))))
		return (0);
	*count = 0;
	va_start(ap, fmt);
	ft_cases((char *)fmt, count, ap);
	ret = *count;
	free(count);
	return (ret);
}
