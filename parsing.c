/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 20:11:29 by tholzheu          #+#    #+#             */
/*   Updated: 2018/11/01 19:10:51 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*flags_parsing(char *fmt, t_params *params)
{
	int		i;

	i = 1;
	if (*fmt != '#' && *fmt != '0' && *fmt != '-' && *fmt != ' ' && *fmt != '+')
	{
		set_params(PW5, &params->flags);
		return (fmt);
	}
	while (*fmt && i)
	{
		i = 0;
		if (*fmt == '#' && (i = 1))
			set_params(PW0, &params->flags);
		else if (*fmt == '0' && (i = 1))
			set_params(PW1, &params->flags);
		else if (*fmt == '-' && (i = 1))
			set_params(PW2, &params->flags);
		else if (*fmt == ' ' && (i = 1))
			set_params(PW3, &params->flags);
		else if (*fmt == '+' && (i = 1))
			set_params(PW4, &params->flags);
		fmt++;
	}
	fmt--;
	return (fmt);
}

static char		*lmod_parsing(char *fmt, t_params *params)
{
	if (*fmt == 'h' && *(fmt + 1) == 'h' && fmt++)
		set_params(PW0, &params->lmod);
	else if (*fmt == 'h')
		set_params(PW1, &params->lmod);
	else if (*fmt == 'l' && *(fmt + 1) == 'l' && fmt++)
		set_params(PW2, &params->lmod);
	else if (*fmt == 'l')
		set_params(PW3, &params->lmod);
	else if (*fmt == 'j')
		set_params(PW4, &params->lmod);
	else if (*fmt == 'z')
		set_params(PW5, &params->lmod);
	else
		return (fmt);
	fmt++;
	return (fmt);
}

static char		*type_parsing(char *fmt, t_params *params)
{
	if (*fmt == 'd' || *fmt == 'i')
		set_params(PW0, &params->type);
	else if (*fmt == 'u' || *fmt == 'U' || *fmt == 'D')
		set_params(PW1, &params->type);
	else if (*fmt == 'o' || *fmt == 'O')
		set_params(PW2, &params->type);
	else if (*fmt == 'x')
		set_params(PW3, &params->type);
	else if (*fmt == 'X')
		set_params(PW4, &params->type);
	else if (*fmt == 'p')
		set_params(PW5, &params->type);
	else if (*fmt == 's')
		set_params(PW6, &params->type);
	else if (*fmt == 'c')
		set_params(PW7, &params->type);
	fmt++;
	return (fmt);
}

char			*parsing(char *fmt, t_params *params, t_book *book)
{
	fmt = flags_parsing(fmt, params);
	if (*fmt && *fmt != '.')
		book->width = ft_atoi(fmt);
	while (*fmt && ft_isdigit(*fmt))
	   fmt++;
	if (*fmt && *fmt == '.' && fmt++)
	{
		unset_params(PW1, &params->flags);
		book->prec = ft_atoi(fmt);
	}
	while (*fmt && ft_isdigit(*fmt))
	   fmt++;
	fmt = lmod_parsing(fmt, params);
	fmt = type_parsing(fmt, params);
	if (param_is_on(PW2, &params->flags))
		unset_params(PW1, &params->flags);
	if (param_is_on(PW4, &params->flags))
		unset_params(PW3, &params->flags);
	fmt--;
	return (fmt);
}