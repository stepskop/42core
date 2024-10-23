/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:08:18 by username          #+#    #+#             */
/*   Updated: 2024/10/23 14:09:38 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	is_inrow(char **row, int x)
{
	int	i;

	i = -1;
	while(++i <= x)
		if (!row[i])
			return (0);
	return (1);
}
