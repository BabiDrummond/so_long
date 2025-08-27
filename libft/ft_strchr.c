/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 02:16:44 by bmoreira          #+#    #+#             */
/*   Updated: 2025/07/23 22:59:42 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	while (*s)
		if (*s++ == (char) c)
			return ((char *)--s);
	if (*s == (char) c)
		return ((char *) s);
	return (0);
}

/*
int main(void)
{
	#include <stdio.h>

	printf("%s\n", ft_strchr("oie td bem?", 'e'));
}
*/