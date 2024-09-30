/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzubkova <dzubkova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:39:35 by dzubkova          #+#    #+#             */
/*   Updated: 2023/11/30 13:49:44 by dzubkova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_substr(char const *s, unsigned int start, size_t len);
static size_t	min(size_t a, size_t b);

/*int	main(void)
{
	char *str = ft_strdup("0123456789");
	char *s = ft_substr(str, 9, 10);
	printf("%lu\n", ft_strlen(s));
	return (0);
}*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	count;
	size_t	min_len;
	char	*res;

	if (start >= ft_strlen(s))
	{
		res = malloc(1);
		if (!res)
			return (NULL);
		ft_strlcpy(res, "", 1);
		return (res);
	}
	min_len = min(len, ft_strlen(s + start));
	str = malloc(min_len + 1);
	res = str;
	if (!str)
		return (NULL);
	s += start;
	count = len;
	while (*s && count--)
		*str++ = *s++;
	*str = '\0';
	return (res);
}

static size_t	min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	else
		return (b);
}
