/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcarlos <wcarlos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:31:16 by wcarlos           #+#    #+#             */
/*   Updated: 2021/10/20 17:31:45 by wcarlos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*current;
	t_list	*result;
	t_list	*result_copy;

	current = lst;
	result = ft_lstnew((f(current->content)));
	if (!result)
		ft_lstclear(&result, del);
	current = current->next;
	while (current && result)
	{
		result_copy = ft_lstnew(f(current->content));
		if (!result_copy)
		{
			ft_lstclear(&result_copy, del);
			ft_lstclear(&result, del);
		}
		ft_lstadd_back(&result, result_copy);
		current = current->next;
	}
	return (result);
}
