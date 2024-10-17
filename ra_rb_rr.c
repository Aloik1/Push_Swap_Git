/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:57:25 by aloiki            #+#    #+#             */
/*   Updated: 2024/10/17 17:18:35 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	rr(t_list **headA, t_list **headB)
{
	ra(headA);
	rb(headB);
}

void	rb(t_list **headB)
{
	ra(headB);
}

void	ra(t_list **headA)
{
	t_list	*current;
	t_list	*previous;

	if (headA == NULL || *headA == NULL || (*headA)->next == NULL)
		return ;
	current = *headA;
	previous = NULL;
	while (current->next != NULL)
	{
		previous = current;
		current = current->next;
	}
	current->next = *headA;
	previous->next = NULL;
	*headA = current;
}