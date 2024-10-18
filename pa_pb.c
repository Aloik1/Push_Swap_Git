/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:58:04 by aloiki            #+#    #+#             */
/*   Updated: 2024/10/17 17:17:44 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	pb(t_list **headA, t_list **headB)
{
	pa(headB, headA);
}

void	pa(t_list **headA, t_list **headB)
{
	t_list	*currentB;
	t_list	*previousB;


	if (*headB == NULL)
		return ;
	currentB = *headB;
	previousB = NULL;
	if (currentB->next == NULL)
	{
		if (*headA == NULL)
		{
			ft_lstadd_front(headA, currentB);
		}
		ft_lstadd_back(headA, currentB);
		*headB = NULL;
		return ;
	}
	while (currentB->next != NULL)
	{
		previousB = currentB;
		currentB = currentB->next;
	}
	previousB->next = NULL;
	ft_lstadd_back(headA, currentB);
}
