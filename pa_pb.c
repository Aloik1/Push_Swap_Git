/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:58:04 by aloiki            #+#    #+#             */
/*   Updated: 2024/10/21 21:01:37 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	pa_pb(t_list **headA, t_list **headB)
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

void	pb(t_list **headA, t_list **headB)
{
	pa_pb(headB, headA);
	ft_printf("pb\n");
}

void	pa(t_list **headA, t_list **headB)
{
	pa_pb(headA, headB);
	ft_printf("pa\n");
}
