/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:00:58 by sskopek           #+#    #+#             */
/*   Updated: 2024/09/23 21:48:58 by username         ###   ########.fr       */
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

int		ft_putcount_str(char *s, t_flags flags);
int		ft_putcount_nbr(int n);
int		ft_putcount_chr(char c, t_flags flags);
void	ft_putcount_hex(unsigned long ulong, unsigned int toupper, int *count);
void	ft_putcount_dec(unsigned long ulong, int *count);
int		ft_printf(const char *format, ...);
void	ft_print_pointer(void *ptr, int *count);
t_flags	parse_flags(const char *format, const char *convs, va_list args);
int		pad(int size, int zero);

#endif
