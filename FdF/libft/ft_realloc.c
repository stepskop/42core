/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@email.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:56:37 by username          #+#    #+#             */
/*   Updated: 2024/10/23 12:26:38 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t old_size, size_t size)
{
	void	*new;

	if (!ptr)
		return (malloc(size));
	if (!size && ptr)
		return (free(ptr), NULL);
	if (old_size > size)
		return (ptr);
	new = malloc(size);
	if (!new)
		return (NULL);
	ft_memcpy(new, ptr, old_size);
	free(ptr);
	return (new);
}
