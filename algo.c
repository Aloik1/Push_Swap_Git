/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:35:45 by ikondrat          #+#    #+#             */
/*   Updated: 2024/10/19 20:56:53 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	algo(t_list **headA, t_list **headB, int size)
{
	t_list		*current;
	t_list		*min_node;
	int		i;
	int		min_num;
	int		current_num;

	size = ft_lstsize(*headA);
	while (size > 0)
	{
		current = *headA;
		min_num = INT_MAX;
		min_node = NULL;
		while (current)
		{
			current_num = ft_atoi(current->content);
			if (current_num < min_num)
			{
				min_num = current_num;
				min_node = current;
			}
			current = current->next;
		}
		// ft_printf("A list size is: %d", ft_lstsize(*headA));
		// write (1, "\n", 1);
		if (ft_lstsize(*headA) == 1)
		{
			pb(headA, headB);
			ft_printf("pb");
			write (1, "\n", 1);
		}	
		else
		{
			i = 0;
			current = *headA;
			if (*headA == min_node)
			{
				while (min_node->next != NULL)
				{
					rra(headA);
					ft_printf("rra");
					write (1, "\n", 1);
				}
			}
			while (current != min_node)
			{
				current = current->next;
				i++;
			}
			if (i <= (ft_lstsize(*headA) / 2))
			{

				while (min_node->next != NULL)
				{
					ra(headA);
					ft_printf("ra");
					write (1, "\n", 1);
				}
			}
			else
			{
				while (min_node->next != NULL)
				{
					rra(headA);
					ft_printf("rra");
					write (1, "\n", 1);
				}
			}
			pb(headA, headB);
			ft_printf("pb");
			write (1, "\n", 1);
			rb(headB);
			ft_printf("rb");
			write (1, "\n", 1);
		}
		size--;
	}
	rb(headB); // I don't fking get it but it works :))
	ft_printf("rb");
	write (1, "\n", 1);
	size = ft_lstsize(*headB);
	// ft_printf("size of B is: %d", ft_lstsize(*headB));
	// write (1, "\n", 1);
	while (size > 0)
	{
		pa(headA, headB);
		ft_printf("pa");
		write (1, "\n", 1);
		size--;
	}
}
