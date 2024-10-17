/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:19:45 by aloiki            #+#    #+#             */
/*   Updated: 2024/10/17 18:17:56 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	rrr(t_list **headA, t_list **headB)
{
	rra(headA);
	rra(headB);
	return ;
}

void	rrb(t_list **headB)
{
	rra(headB);
	return ;
}

void	rra(t_list **headA)
{
	t_list	*currentA;
	t_list	*newheadA;

	
	if (headA == NULL || *headA == NULL || (*headA)->next == NULL)
		return ;
	currentA = *headA;
	while (currentA->next != NULL)
		currentA = currentA->next;
	newheadA = *headA;
	*headA = (*headA)->next;
	currentA->next = newheadA;
	newheadA->next = NULL;
	return ;
}