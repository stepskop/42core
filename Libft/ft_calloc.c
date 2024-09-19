/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskopek <sskopek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:09:56 by sskopek           #+#    #+#             */
/*   Updated: 2024/09/19 20:39:00 by sskopek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb && (size * nmemb) / nmemb != size)
		return ((void *)0);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (ptr);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
