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

t_flags	parse_flags(const char *format, const char *ops, va_list args)
{
	t_flags	flags;
	size_t	i;
	size_t	j;
	char	*num_opts;

	i = 0;
	num_opts = "uidxX";
	flags = init_flags();
	while (is_flag(format[i]))
		set_option(format[i++], &flags);
	i += set_modifs(&(format[i]), args, &flags);
	j = -1;
	while (ops[++j])
	{
		if (format[i] == ops[j])
			flags.conv = ops[j];
	}
	if (ft_strchr(num_opts, flags.conv) && flags.zero && flags.precision != -1)
		flags.zero = 0;
	flags.format_len = i + 1;
	return (flags);
}
