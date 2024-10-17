/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:47:16 by aloiki            #+#    #+#             */
/*   Updated: 2024/10/17 18:14:51 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	ss(t_list **headA, t_list **headB, int argc)
{
	sa(headA, argc);
	sb(headB, argc);
}

void	sb(t_list **headB, int argc)
{
	sa(headB, argc);
}

void	sa(t_list **head, int argc)
{
	t_list	*current;
	t_list	*last;
	t_list	*penultimo;

	if (argc < 3) // if we have less than 2 args, dont do anything
		return ;
	current = *head; //aux node, to not modify the original head 
	last = NULL; // initialize 
	penultimo = NULL; // initialize
	while (current != NULL) // we want to reach the last node in the list
	{
		penultimo = last; //we want penultimo to be 1 node behind last
		last = current; // current is 1 ahead of penultimo and equal to last
		current = current->next; // current is the one passing through the list
	}
	if (penultimo == NULL) // if we only have 1 node in the list, dont do anything
		return ;
	if (penultimo == *head) // if penultimo is the first node, aka we only have 2 nodes
	{
		last->next = penultimo; // swap, last points to penultimo
        	penultimo->next = NULL; // penultimo becomes the last node
        	*head = last; // and last becomes the head, since we only have 2 nodes and we swapped them
        	return;
	}
	penultimo->next = last; // when we reach the end, same condition as in while
	last->next = NULL;
	current = *head; // reset current to the beginning
	while (current->next != penultimo) // we want ot get the the node, before the penultimo
		current = current->next;
// Imagine we have this list: 1 2 3 4 5 6. With the while, we reach number 4
	current->next = last; // link 4 and 6
	last->next = penultimo; // link 6 to 5
	penultimo->next = NULL; // point 5 to NULL
}
	