/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmtioui <hmtioui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:21:38 by hmtioui           #+#    #+#             */
/*   Updated: 2024/11/19 17:08:32 by hmtioui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*srcpy;
	unsigned char		*destcpy;

	srcpy = (unsigned char *)src;
	destcpy = (unsigned char *)dest;
	if ((!dest && !src) || (dest == src))
		return (dest);
	if (dest > src && dest < src + n)
	{
		while (n--)
			destcpy[n] = srcpy[n];
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
