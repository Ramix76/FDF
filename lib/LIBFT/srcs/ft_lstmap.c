/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 17:02:54 by framos-p          #+#    #+#             */
/*   Updated: 2022/11/10 10:58:27 by framos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_stack *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_element;
	void	*new_content;

	new_list = NULL;
	if (!lst)
		return (NULL);
	while (lst)
	{
		new_content = f(lst -> content);
		new_element = ft_lstnew(new_content);
		if (!new_element)
		{
			if (new_content)
				free(new_content);
			ft_lstclear(&new_list, del);
		}
		ft_lstadd_back(&new_list, new_element);
		lst = lst -> next;
	}
	return (new_list);
}
