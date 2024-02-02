/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:31:25 by jroulet           #+#    #+#             */
/*   Updated: 2023/11/18 21:03:39 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_ptr(unsigned long ptr);
void	ft_ptr_calc(uintptr_t ptr);
int		ft_ptr_len(uintptr_t ptr);

int	ft_print_ptr(unsigned long ptr)
{
	int	length;

	length = 0;
	length += write(1, "0x", 2);
	if (ptr == 0)
		length += write(1, "0", 1);
	else
	{
		ft_ptr_calc(ptr);
		length += ft_ptr_len(ptr);
	}
	return (length);
}

void	ft_ptr_calc(uintptr_t ptr)
{
	char	digit;
	char	hex_digit;

	if (ptr >= 16)
	{
		ft_ptr_calc(ptr / 16);
		ft_ptr_calc(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
		{
			digit = ptr + '0';
			write(1, &digit, 1);
		}
		else
		{
			hex_digit = ptr - 10 + 'a';
			write(1, &hex_digit, 1);
		}
	}
}

int	ft_ptr_len(uintptr_t ptr)
{
	int	i;

	i = 0;
	while (ptr)
	{
		i ++;
		ptr = ptr / 16;
	}
	return (i);
}
