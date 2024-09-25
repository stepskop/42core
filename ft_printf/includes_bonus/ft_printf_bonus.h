/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:00:58 by sskopek           #+#    #+#             */
/*   Updated: 2024/09/24 17:26:29 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "libft.h"
# include <stdarg.h>
# include <stdio.h>

typedef struct s_flags
{
	char	conv;
	int		h_tag;
	int		minus;
	int		plus;
	int		space;
	int		width;
	int		zero;
	int		precision;
	int		format_len;
}	t_flags;

int		ft_printf(const char *format, ...);
int		print_str(char *s, t_flags flags);
int		print_nbr(int n, t_flags flags);
int		print_chr(char c, t_flags flags);
int		print_udc(unsigned long ulong, t_flags flags);
int		print_ptr(void *ptr, t_flags flags);
int		print_hex(unsigned long ulong, unsigned int tppr, t_flags flags);

t_flags	parse_flags(const char *format, const char *convs, va_list args);
t_flags	init_flags(void);
int		is_flag(char c);
void	set_option(char c, t_flags *flags);
size_t	set_modifs(const char *format, va_list args, t_flags *flags);

int		get_digits(unsigned long n, unsigned int base);
int		pad(int size, int zero);
int		nbr_pad(int n, t_flags flags);
int		hex_pad(unsigned long ulong, t_flags flags);

#endif
