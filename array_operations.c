/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 22:07:09 by juanherr          #+#    #+#             */
/*   Updated: 2024/11/01 15:48:28 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*stack_to_array(t_list *stack, int size)
{
	int	*array;
	int	i;

	array = (int *)malloc(sizeof(int) * size);
	check_memory((void **)&array);
	i = 0;
	while (stack)
	{
		array[i++] = stack->value;
		stack = stack->next;
	}
	return (array);
}

void	assign_index(t_list **stack, int *array, int size)
{
	t_list	*current;
	int		i;

	current = *stack;
	while (current)
	{
		i = 0;
		while (i < size)
		{
			if (current->value == array[i])
			{
				current->index = i;
				break ;
			}
			i++;
		}
		current = current->next;
	}
}

void	ft_bubblesort(int *array, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}
