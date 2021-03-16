/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <thjonell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 21:21:18 by thjonell          #+#    #+#             */
/*   Updated: 2020/11/05 18:35:52 by thjonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_lstadd_back(t_list **lst, t_list *new)
{
    if (!new)
        return ;
    if (!(*lst))
    {
        *lst = new;
        return ;
    }
    ft_lstlast(*lst)->next = new;
}
