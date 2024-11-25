/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:46:04 by aloiki            #+#    #+#             */
/*   Updated: 2024/11/01 15:48:39 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list			*stack_a;
	t_list			*stack_b;
	unsigned int	size;
	int				*array;
	char			**args;

	stack_b = NULL;
	args = handle_args(argc, argv);
	check_repeated(args);
	create_stack(args, &stack_a);
	fill_values(&stack_a);
	size = ft_lstsize(stack_a);
	array = stack_to_array(stack_a, size);
	ft_bubblesort(array, size);
	assign_index(&stack_a, array, size);
	ft_sort(&stack_a, &stack_b);
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
	free(array);
	return (0);
}
