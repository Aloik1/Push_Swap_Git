/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsizedup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:15:44 by aloiki            #+#    #+#             */
/*   Updated: 2024/10/17 16:48:49 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

t_list	*ft_lstsizedup(t_list **headA)
{
	t_list	*current;
	t_list	*newnode;
	t_list	*headB;
	char	*content;

	current = *headA;
	newnode = NULL;
	headB = NULL;
	while (current != NULL)
	{
		content = ft_strdup("A"); // change to NULL
		if (!content) // only for test
			return NULL; //only for test
		newnode = ft_lstnew(content);
		if (!newnode)
		{
			free (content);
			ft_lstclear(&headB, free);
			return NULL;
		}
		ft_lstadd_back(&headB, newnode);
		current = current->next;
	}
	return (headB);
}
