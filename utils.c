/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:47:08 by aloiki            #+#    #+#             */
/*   Updated: 2024/11/01 15:48:55 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_memory(void *ptr)
{
	if (!ptr)
	{
		ft_printerror("memory problems");
	}
}

t_list	*ft_lstnew_(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->value = 0;
	new->index = 0;
	new->next = NULL;
	return (new);
}

int	ft_sqrt(int num)
{
	int	sqrt;

	sqrt = 0;
	while (sqrt * sqrt <= num)
	{
		if (sqrt * sqrt == num)
			return (sqrt);
		sqrt++;
	}
	return (sqrt - 1);
}

int	get_max_index(t_list *stack)
{
	int	max_index;

	max_index = 0;
	while (stack)
	{
		if (stack->index > max_index)
			max_index = stack->index;
		stack = stack->next;
	}
	return (max_index);
}
