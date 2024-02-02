/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroulet <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:23:52 by jroulet           #+#    #+#             */
/*   Updated: 2023/11/25 19:39:27 by jroulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_forcheck(va_list args, const char format);
int		ft_print_char(int c);
int		ft_print_str(char *str);
int		ft_print_nbr(int n);
int		ft_print_percent(void);

int		ft_print_ptr(unsigned long ptr);
int		ft_ptr_len(uintptr_t ptr);
void	ft_ptr_calc(uintptr_t ptr);

int		ft_print_uns(unsigned int uns);
char	*ft_uitoa(unsigned int n);
int		ft_uns_len(unsigned int uns);

int		ft_print_hex(unsigned int hex, const char format);
void	ft_put_hex(unsigned int hex, const char format);
int		ft_hex_len(unsigned int hex);

void	ft_putchar_fd(char c, int fd);
char	*ft_itoa(int n);
int		ft_atoi(const char *nptr);

#endif
