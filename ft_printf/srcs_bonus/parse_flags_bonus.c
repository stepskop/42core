/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:02:21 by username          #+#    #+#             */
/*   Updated: 2024/09/24 10:53:52 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/ft_printf_bonus.h"

t_flags	parse_flags(const char *format, const char *convs, va_list args)
{
	t_flags	flags;
	size_t	i;
	size_t	j;

	i = 0;
	flags = init_flags();
	while (is_flag(format[i]))
		set_option(format[i++], &flags);
	i += set_modifs(&(format[i]), args, &flags);
	j = -1;
	while (convs[++j])
	{
		if (format[i] == convs[j])
			flags.conv = convs[j];
	}
	flags.format_len = i + 1;
	return (flags);
}
