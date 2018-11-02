/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 16:27:19 by tholzheu          #+#    #+#             */
/*   Updated: 2018/11/01 16:45:19 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		set_unsigned_len_and_base(t_params *params, unsigned long long nb, size_t *len, int *base)
{
	if (params->type == PW1)
	{
		*len = unsigned_nb_size(nb, 10);
		*base = 10;
	}
	if (params->type == PW2)
	{
		*len = unsigned_nb_size(nb, 8);
		*base = 8;
	}
	if (params->type == PW3 || params->type == PW4)
	{
		*len = unsigned_nb_size(nb, 16);
		*base = 16;
	}
}
