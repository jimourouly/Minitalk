/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:31:36 by jroulet           #+#    #+#             */
/*   Updated: 2023/11/25 21:10:31 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_uns(unsigned int uns)
{
	int		length;
	char	*res;

	length = 0;
	if (uns == 0)
	{
		length += write(1, "0", 1);
	}
	else
	{
		res = ft_uitoa(uns);
		length += ft_print_str(res);
		free(res);
	}
	return (length);
}

int	ft_uns_len(unsigned int uns)
{
	int	length;

	length = 0;
	while (uns)
	{
		length ++;
		uns = uns / 10;
	}
	return (length);
}
