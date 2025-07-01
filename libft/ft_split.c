/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achajar <achajar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:18:14 by hmtioui           #+#    #+#             */
/*   Updated: 2024/11/21 18:21:28 by achajar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(const char *str, char c)
{
	int	count;
	int	flag;

	count = 0;
	flag = 0;
	while (*str)
	{
		if (*str != c && flag == 0)
		{
			flag = 1;
			count++;
		}
		else if (*str == c)
			flag = 0;
		str++;
	}
	return (count);
}

static int	word_malloc(char **arr, int index, size_t len)
{
	int	i;

	arr[index] = malloc(len);
	if (arr[index] == NULL)
	{
		i = 0;
		while (i < index)
			free(arr[i++]);
		free(arr);
		return (1);
	}
	return (0);
}

static int	fill_arr(char **arr, const char *s, char c, int index)
{
	size_t	len;

	while (*s)
	{
		len = 0;
		while (*s && *s == c)
			s++;
		while (*s && *s != c)
		{
			s++;
			len++;
		}
		if (len)
		{
			if (word_malloc(arr, index, len + 1))
				return (1);
			ft_strlcpy(arr[index], s - len, len + 1);
			index++;
		}
	}
	return (0);
}

char	**ft_split(const char *s, char c)
{
	int		nwords;
	char	**arr;

	if (!s)
		return (NULL);
	nwords = word_count(s, c);
	arr = malloc((nwords + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	arr[nwords] = NULL;
	if (fill_arr(arr, s, c, 0))
		return (NULL);
	return (arr);
}
