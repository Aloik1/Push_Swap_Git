/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:47:16 by aloiki            #+#    #+#             */
/*   Updated: 2024/10/21 19:32:40 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static void	sa_sb_ss(t_list **headA_B, t_list *current, t_list *last, t_list *penultimo)
{
	if (ft_lstsize(*headA_B) < 2)
		return ;
	while (current)
	{
		penultimo = last;
		last = current;
		current = current->next;
	}
	if (!penultimo)
		return ;
	if (penultimo == *headA_B)
	{
		last->next = penultimo;
        	penultimo->next = NULL;
        	*headA_B = last;
        	return;
	}
	penultimo->next = last;
	last->next = NULL;
	current = *headA_B;
	while (current->next != penultimo)
		current = current->next;
	current->next = last;
	last->next = penultimo;
	penultimo->next = NULL;
}

void	ss(t_list **headA, t_list **headB)
{
	t_list	*current;
	t_list	*last;
	t_list	*penultimo;

	current = *headA;
	last = NULL;
	penultimo = NULL;
	sa_sb_ss(headA, current, last, penultimo);
	current = *headB;
	last = NULL;
	penultimo = NULL;
	sa_sb_ss(headB, current, last, penultimo);
	ft_printf("ss\n");
}

void	sb(t_list **headB)
{
	t_list	*current;
	t_list	*last;
	t_list	*penultimo;
	
	current = *headB;
	last = NULL;
	penultimo = NULL;
	sa_sb_ss(headB, current, last, penultimo);
	ft_printf("sb\n");
}

void	sa(t_list **headA)
{
	t_list	*current;
	t_list	*last;
	t_list	*penultimo;

	current = *headA;
	last = NULL;
	penultimo = NULL;
	sa_sb_ss(headA, current, last, penultimo);
	ft_printf("sa\n");
}
	