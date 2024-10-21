/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:57:25 by aloiki            #+#    #+#             */
/*   Updated: 2024/10/21 19:31:20 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	ra_rb_rr(t_list **headA_B)
{
	t_list	*current;
	t_list	*previous;

	if (headA_B == NULL || *headA_B == NULL || (*headA_B)->next == NULL)
		return ;
	current = *headA_B;
	previous = NULL;
	while (current->next != NULL)
	{
		previous = current;
		current = current->next;
	}
	current->next = *headA_B;
	previous->next = NULL;
	*headA_B = current;
}

void	rr(t_list **headA, t_list **headB)
{
	ra_rb_rr(headA);
	ra_rb_rr(headB);
	ft_printf("rr\n");
}

void	rb(t_list **headB)
{
	ra_rb_rr(headB);
	ft_printf("rb\n");
}

void	ra(t_list **headA)
{
	ra_rb_rr(headA);
	ft_printf("ra\n");
}
