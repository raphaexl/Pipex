/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@1337.MA>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 14:53:19 by abiri             #+#    #+#             */
/*   Updated: 2018/10/10 12:53:22 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	if ((str = malloc(size + 1)))
	{
		while (i <= size)
			str[i++] = '\0';
		return (str);
	}
	return (NULL);
}
