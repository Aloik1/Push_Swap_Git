/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:35:45 by ikondrat          #+#    #+#             */
/*   Updated: 2024/10/20 20:44:28 by aloiki           ###   ########.fr       */
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

void	ra_or_rra(t_list **headA, t_list *min_node)
{
	int		i;
	t_list	*current;

	i = 0;
	current = *headA;
	while (current != min_node)
	{
		current = current->next;
		i++;
	}
	if (i >= (ft_lstsize(*headA) / 2))
	{

		while (min_node->next != NULL)
		{
			ra(headA);
			ft_printf("ra\n");
		}
	}
	else
	{
		while (min_node->next != NULL)
		{
			rra(headA);
			ft_printf("rra\n");
		}
	}
}

int	neighbour_checker(t_list **headA, t_list **headB, t_list *min_node, int min_num)
{
	t_list	*current;
	t_list	*next_min_node;
	int		next_min_num;
	int		current_num;

	next_min_num = INT_MAX;
	current = *headA;
	while (current != NULL)
	{
		current_num = ft_atoi(current->content);
		if (current_num < next_min_num  && current_num != min_num)
		{
			next_min_num = current_num;
			next_min_node = current;
		}
		current = current->next;
	}
	if (next_min_node->next == min_node)
	{
		ra_or_rra(headA, min_node);
		pb(headA, headB);
		pb(headA, headB);
		ft_printf("pb\n");
		ft_printf("pb\n");
		return (1);
	}
	if (min_node->next == next_min_node)
	{
		ra_or_rra(headA, next_min_node);
		sa(headA);
		pb(headA, headB);
		pb(headA, headB);
		ft_printf("pb\n");
		ft_printf("pb\n");
		return (1);
	}
	else
		return 0;
}

void	algo(t_list **headA, t_list **headB, int size)
{
	t_list		*current;
	t_list		*min_node;
	int		min_num;
	int		current_num;

	size = ft_lstsize(*headA);
	while (size > 1)
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
		if (!(neighbour_checker(headA, headB, min_node, min_num)))
		{
			// ft_printf("A list size is: %d", ft_lstsize(*headA));
			// write (1, "\n", 1);	
			current = *headA;
			if (*headA == min_node)
			{
				while (min_node->next != NULL)
				{
					rra(headA);
					ft_printf("rra\n");
				}
			}
			ra_or_rra(headA, min_node);
			pb(headA, headB);
			ft_printf("pb\n");
			// rb(headB);
			// ft_printf("rb");
			// write (1, "\n", 1);
			size--;
		}
		else
			size = size - 2;
		// ft_printf("B list in the end is: ");
		// print_list(headB);
		// write (1, "\n", 1);

	}
	size = ft_lstsize(*headB);
	while (size > 0)
	{
		pa(headA, headB);
		ft_printf("pa");
		write (1, "\n", 1);
		size--;
	}
}
