/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2_3_4_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:46:51 by aloiki            #+#    #+#             */
/*   Updated: 2024/11/01 15:48:51 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_list **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
}

void	sort_three(t_list **stack_a)
{
	int	a;
	int	b;
	int	c;

	if (is_sorted(stack_a))
		return ;
	a = (*stack_a)->value;
	b = (*stack_a)->next->value;
	c = (*stack_a)->next->next->value;
	if (a > b && b < c && a < c)
		sa(stack_a);
	else if (a > b && b > c)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (a > b && b < c && a > c)
		ra(stack_a);
	else if (a < b && b > c && a < c)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (a < b && b > c && a > c)
		rra(stack_a);
}

void	sort_four(t_list **stack_a, t_list **stack_b)
{
	int	min_index;

	if (is_sorted(stack_a))
		return ;
	min_index = get_min_index(*stack_a);
	best_rotate(stack_a, min_index);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	int	min_index;

	if (is_sorted(stack_a))
		return ;
	min_index = get_min_index(*stack_a);
	best_rotate(stack_a, min_index);
	pb(stack_a, stack_b);
	min_index = get_min_index(*stack_a);
	best_rotate(stack_a, min_index);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	ft_sort(t_list **stack_a, t_list **stack_b)
{
	unsigned int	size;

	size = ft_lstsize(*stack_a);
	if (is_sorted(stack_a))
		return ;
	if (size == 2)
		sort_two(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 4)
		sort_four(stack_a, stack_b);
	else if (size == 5)
		sort_five(stack_a, stack_b);
	else if (size > 5)
	{
		move_to_b(stack_a, stack_b);
		move_to_a(stack_a, stack_b);
	}
}
