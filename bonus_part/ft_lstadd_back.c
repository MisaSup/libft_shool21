/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcarlos <wcarlos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:25:34 by wcarlos           #+#    #+#             */
/*   Updated: 2021/10/20 17:25:47 by wcarlos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_elem;

	last_elem = *lst;
	if (last_elem != NULL)
	{
		while (last_elem->next)
			last_elem = last_elem->next;
		last_elem->next = new;
	}
	else
		*lst = new;
}
