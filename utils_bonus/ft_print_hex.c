/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:32:11 by jroulet           #+#    #+#             */
/*   Updated: 2023/11/18 18:25:09 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int hex, const char format)
{
	if (hex == 0)
		return (write(1, "0", 1));
	else
		ft_put_hex(hex, format);
	return (ft_hex_len(hex));
}

int	ft_hex_len(unsigned int hex)
{
	int	length;

	length = 0;
	while (hex)
	{
		length++;
		hex = hex / 16;
	}
	return (length);
}

void	ft_put_hex(unsigned int hex, const char format)
{
	if (hex >= 16)
	{
		ft_put_hex(hex / 16, format);
		ft_put_hex(hex % 16, format);
	}
	else
	{
		if (hex <= 9)
			ft_putchar_fd((hex + '0'), 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd((hex - 10 + 'a'), 1);
			if (format == 'X')
				ft_putchar_fd((hex - 10 + 'A'), 1);
		}
	}
}
