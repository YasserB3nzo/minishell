/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmtioui <hmtioui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:23:53 by hmtioui           #+#    #+#             */
/*   Updated: 2024/11/19 17:08:25 by hmtioui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dstcpy;
	const unsigned char	*srcpy;

	if (!dst && !src)
		return (NULL);
	if (dst == src)
		return (dst);
	if (!n)
		return (dst);
	dstcpy = (unsigned char *)dst;
	srcpy = (unsigned char *)src;
	while (n--)
		*dstcpy++ = *srcpy++;
	return (dst);
}
