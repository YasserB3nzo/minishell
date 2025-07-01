/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmtioui <hmtioui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:48:23 by hmtioui           #+#    #+#             */
/*   Updated: 2024/11/17 21:20:24 by hmtioui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			len;
	unsigned int	i;
	char			*snew;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	snew = malloc(len + 1);
	if (!snew)
		return (NULL);
	i = 0;
	while (i < len)
	{
		snew[i] = f(i, s[i]);
		i++;
	}
	snew[i] = 0;
	return (snew);
}
