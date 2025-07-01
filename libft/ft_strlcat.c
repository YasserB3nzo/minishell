/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmtioui <hmtioui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:47:53 by hmtioui           #+#    #+#             */
/*   Updated: 2024/11/19 17:07:37 by hmtioui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	a;
	size_t	b;

	a = 0;
	b = 0;
	if (!dst && !size)
		return (ft_strlen(src));
	while (dst[a] && a < size)
		a++;
	while (src[b] && (a + b + 1) < size)
	{
		dst[a + b] = src[b];
		b++;
	}
	if (a < size)
		dst[a + b] = 0;
	return (a + ft_strlen(src));
}
