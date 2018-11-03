/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_special.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 08:05:24 by tholzheu          #+#    #+#             */
/*   Updated: 2018/11/02 20:29:37 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_special_str(t_params *params, t_book *book, va_list ap, int *count)
{
	char	*str;
	size_t	len;

	str = strdup_wchar((wchar_t *)va_arg(ap, char *), &len);
	if (str == NULL)
	{
		str = "(null)";
		len = ft_strlen(str);
	}
	if (book->prec < len && param_is_on(PW5, &params->flags))
		len = book->prec;
	while (book->width > len && !param_is_on(PW2, &params->flags))
	{
		putchar_printf(' ', count);
		book->width--;
	}
	write(1, str, len);
	*count = *count + len;
	while (book->width > len && param_is_on(PW2, &params->flags))
	{
		putchar_printf(' ', count);
		book->width--;
	}
	free(str);
	str = NULL;
}
