/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:19:45 by aloiki            #+#    #+#             */
/*   Updated: 2024/10/21 19:33:05 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	rra_rrb_rrr(t_list **headA_B)
{
	t_list	*currentA_B;
	t_list	*newheadA_B;

	
	if (headA_B == NULL || *headA_B == NULL || (*headA_B)->next == NULL)
		return ;
	currentA_B = *headA_B;
	while (currentA_B->next != NULL)
		currentA_B = currentA_B->next;
	newheadA_B = *headA_B;
	*headA_B = (*headA_B)->next;
	currentA_B->next = newheadA_B;
	newheadA_B->next = NULL;
	return ;
}

void	rrr(t_list **headA, t_list **headB)
{
	rra_rrb_rrr(headA);
	rra_rrb_rrr(headB);
	ft_printf("rrr\n");
	return ;
}

void	rrb(t_list **headB)
{
	rra_rrb_rrr(headB);
	ft_printf("rrb\n");
	return ;
}

void	rra(t_list **headA)
{
	rra_rrb_rrr(headA);
	ft_printf("rra\n");
}