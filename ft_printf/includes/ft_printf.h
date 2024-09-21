/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:00:58 by sskopek           #+#    #+#             */
/*   Updated: 2024/09/21 21:06:48 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

int		ft_putcount_str(char *s);
int		ft_putcount_nbr(int n);
int		ft_putcount_chr(char c);
void	ft_putcount_hex(unsigned long ulong, unsigned int toupper, int *count);
void	ft_putcount_dec(unsigned long ulong, int *count);
int		ft_printf(const char *format, ...);

#endif