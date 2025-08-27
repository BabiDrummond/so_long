/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 01:48:38 by bmoreira          #+#    #+#             */
/*   Updated: 2025/07/19 14:26:26 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*temp;

	temp = (char *)dest;
	if (!dest && !src)
		return (NULL);
	if (dest <= src)
		while (n--)
			*(char *)dest++ = *(char *)src++;
	else if (dest > src)
	{
		src += n - 1;
		dest += n - 1;
		while (n--)
			*(char *)dest-- = *(char *)src--;
	}
	return (temp);
}
