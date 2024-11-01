/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:46:25 by aloiki            #+#    #+#             */
/*   Updated: 2024/11/01 15:48:43 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ra(t_list **stack_a)
{
	t_list	*first;

	if (stack_a == NULL || *stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	first = *stack_a;
	*stack_a = (*stack_a)->next;
	first->next = NULL;
	ft_lstadd_back(stack_a, first);
	ft_putendl_fd("ra", 1);
}

void	rb(t_list **stack_b)
{
	t_list	*first;

	if (stack_b == NULL || *stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	first = *stack_b;
	*stack_b = (*stack_b)->next;
	first->next = NULL;
	ft_lstadd_back(stack_b, first);
	ft_putendl_fd("rb", 1);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	t_list	*first_a;
	t_list	*first_b;

	if (stack_a == NULL || *stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	if (stack_b == NULL || *stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	first_a = *stack_a;
	*stack_a = (*stack_a)->next;
	first_b = *stack_b;
	*stack_b = (*stack_b)->next;
	first_a->next = NULL;
	ft_lstadd_back(stack_a, first_a);
	first_b->next = NULL;
	ft_lstadd_back(stack_b, first_b);
	ft_putendl_fd("rr", 1);
}
