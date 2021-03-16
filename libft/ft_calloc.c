/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <thjonell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:47:40 by thjonell          #+#    #+#             */
/*   Updated: 2020/11/01 18:01:10 by thjonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void *tmp;

	if (!(tmp = malloc(count * size)))
		return (NULL);
	else
	{
		ft_bzero(tmp, count * size);
		return (tmp);
	}
}
