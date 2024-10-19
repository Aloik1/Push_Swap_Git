/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:35:45 by ikondrat          #+#    #+#             */
/*   Updated: 2024/10/19 14:35:29 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

// static void	print_list(t_list **headA)
// {
// 	t_list	*current;

// 	current = *headA;
// 	while (current != NULL)
// 	{
// 		ft_printf("%s", current->content);
// 		current = current->next;
// 	}
// }

/*void	algo(t_list **headA, t_list **headB)
{
	t_list	*current;
	int		i;
	int		num;
	while ((*headA)->content != NULL)
	{
		current = *headA;
		num = ft_atoi(current->content);
		current = current->next;
		while (current != NULL)
		{
			if (num < ft_atoi(current->content))
				current = current->next;
		//potential to optimize.A rule if multiple numbers are the same value
			else
			{
				num = ft_atoi(current->content);
				current = current->next;
			}
		}
		i = 0;
		current = *headA;
		while (ft_atoi(current->content) != num)
		{
			current = current->next;
			i++;
		}
		if (i > ft_lstsize(*headA) / 2)
		{
			while (current->next != NULL)
				ra(headA);
			pb(headA, headB);
			if (ft_lstsize(*headB) > 1)
				rb(headB);
		}
		else if (i < ft_lstsize(*headA) / 2)
		{
			while (current->next != NULL)
				rra(headA);
			pb(headA, headB);
			if (ft_lstsize(*headB) > 1)
				rb(headB);
		}
		while (ft_lstsize(*headB) != 0)
		{
			pa(headA, headB);
		}
	}
}*/


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikondrat <ikondrat@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-18 11:35:45 by ikondrat          #+#    #+#             */
/*   Updated: 2024-10-18 11:35:45 by ikondrat         ###   ########.fr       */
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
		if (ft_lstsize(*headA) == 1)
			pb(headA, headB);
		else
		{
			i = 0;
			current = *headA;
			while (current != min_node)
			{
				current = current->next;
				i++;
			}
			if (i <= ft_lstsize(*headA) / 2)
			{
				while (min_node->next != NULL)
					ra(headA);
			}
			else
			{
				while (min_node->next != NULL)
					rra(headA);
			}
			pb(headA, headB);
			rb(headB);
			// print_list(headB);
		}
		size--;
	}
	rb(headB); // I don't fking get it but it works :))
	size = ft_lstsize(*headB);
	while (size > 0)
	{
		pa(headA, headB);
		size--;
	}
}
