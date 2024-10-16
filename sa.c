/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:47:16 by aloiki            #+#    #+#             */
/*   Updated: 2024/10/16 22:10:58 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	sa(t_list **head, int argc)
{
	t_list	*current;
	t_list	*last;
	t_list	*penultimo;

	if (argc < 3)
		return ;
	current = *head;
	last = NULL;
	penultimo = NULL;
	while (current != NULL)
	{
		penultimo = last;
		last = current;
		current = current->next;
	}
	if (penultimo == NULL)
		return ;
	if (penultimo == *head)
	{
		last->next = penultimo;
        	penultimo->next = NULL;
        	*head = last;
        	return;
	}
	penultimo->next = last;
	last->next = NULL;
	current = *head;
	while (current->next != penultimo)
		current = current->next;
	current->next = last;
	last->next = penultimo;
	penultimo->next = NULL;
}
	