/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_algo_modified.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:35:45 by ikondrat          #+#    #+#             */
/*   Updated: 2024/10/21 23:12:43 by aloiki           ###   ########.fr       */
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
// 		ft_printf("%s ", current->content);
// 		current = current->next;
// 	}
// 	ft_printf("\n");
// }

static t_list	*last_checker(t_list **headA, char *exceptions)
{
	t_list	*current;
	t_list	*min_node;
	int	min_num;
	int	current_num;

	current = *headA;
	min_num = INT_MAX;
	min_node = NULL;
	while (current != NULL)
	{
		current_num = ft_atoi(current->content);
		if (current_num < min_num)
		{
			if (!(ft_strnstr(exceptions, ft_strjoin(",", ft_strjoin(current->content, ",")), ft_strlen(exceptions)) 
			&& current_num < min_num))
			{
				min_num = current_num;
				min_node = current;
			}
		}
		current = current->next;
	}
	return (min_node);
}

static void	ra_or_rra(t_list **headA, t_list *min_node)
{
	int		i;
	t_list		*current;

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
			ra(headA);
	}
	else
	{
		while (min_node->next != NULL)
			rra(headA);
	}
}

static int	neighbour_checker(t_list **headA, t_list *min_node, int min_num, char **exceptions, t_list **last_ordered)
{
	t_list		*current;
	t_list		*next_min_node;
	int		next_min_num;
	int		current_num;

	next_min_node = NULL;
	next_min_num = INT_MAX;
	current = *headA;
	while (current != NULL)
	{
		current_num = ft_atoi(current->content);
		if (current_num < next_min_num  && current_num != min_num &&
			(!(ft_strnstr(*exceptions, ft_strjoin(",", ft_strjoin(current->content, ",")), ft_strlen(*exceptions)))))
		{
			next_min_num = current_num;
			next_min_node = current;
		}
		current = current->next;
	}
	if (next_min_node == NULL)
		return (0);
	if (next_min_node->next == min_node)
	{
		ra_or_rra(headA, min_node);
		sa(headA);
		*exceptions = ft_strjoin(*exceptions, next_min_node->content);
		*exceptions = ft_strjoin(*exceptions, ",");
		*exceptions = ft_strjoin(*exceptions, min_node->content);
		*exceptions = ft_strjoin(*exceptions, ",");
		neighbour_checker(headA, next_min_node, next_min_num, exceptions, last_ordered);
		return (1);
	}
	if (min_node->next == next_min_node)
	{
		ra_or_rra(headA, next_min_node);
		*exceptions = ft_strjoin(*exceptions, next_min_node->content);
		*exceptions = ft_strjoin(*exceptions, ",");
		*exceptions = ft_strjoin(*exceptions, min_node->content);
		*exceptions = ft_strjoin(*exceptions, ",");
		neighbour_checker(headA, next_min_node, next_min_num, exceptions, last_ordered);
		return (1);
	}
	else
		return (0);
}
static int	neighbour_checker_first(t_list **headA, t_list *min_node, int min_num, char **exceptions, t_list **last_ordered)
{
	t_list	*current;
	t_list	*next_min_node;
	int		next_min_num;
	int		current_num;

	next_min_num = INT_MAX;
	next_min_node = NULL;
	current = *headA;

	if (headA == NULL || *headA == NULL || min_node == NULL) 
        	return (0);
	while (current != NULL)
	{
		current_num = ft_atoi(current->content);
		if (current_num < next_min_num  && current_num != min_num &&
			(!(ft_strnstr(*exceptions, ft_strjoin(",", ft_strjoin(current->content, ",")), ft_strlen(*exceptions)))))
		{
			next_min_num = current_num;
			next_min_node = current;
		}
		current = current->next;
	}
	if (next_min_node == NULL)
		return (0);
	if (next_min_node->next == min_node)
	{
		ra_or_rra(headA, min_node);
		sa(headA);
		*exceptions = ft_strjoin(*exceptions, next_min_node->content);
		*exceptions = ft_strjoin(*exceptions, ",");
		*exceptions = ft_strjoin(*exceptions, min_node->content);
		*exceptions = ft_strjoin(*exceptions, ",");
		*last_ordered = next_min_node;
		neighbour_checker_first(headA, next_min_node, next_min_num, exceptions, last_ordered);
		return (1);
	}
	if (min_node->next == next_min_node)
	{
		*exceptions = ft_strjoin(*exceptions, min_node->content);
		*exceptions = ft_strjoin(*exceptions, ",");
		*exceptions = ft_strjoin(*exceptions, next_min_node->content);
		*exceptions = ft_strjoin(*exceptions, ",");
		*last_ordered = next_min_node;
		neighbour_checker_first(headA, next_min_node, next_min_num, exceptions, last_ordered);
		return (1);
	}
	else
		return (0);
	return (0);
}
void	another_algo(t_list **headA, t_list **headB, int size)
{
	t_list	*last_ordered;
	t_list	*min_node;
	t_list	*current;
	char	*exceptions;
	int	current_num;
	int	min_num;
	int	i;

	exceptions = ft_strdup(",");
	last_ordered = NULL;
	current = *headA;
	min_node = current;
	while (min_node != NULL)
	{
		
		min_num = INT_MAX;
		min_node = NULL;
		current = *headA;
		while (current !=NULL)
		{
			current_num = ft_atoi(current->content);
			if (current_num < min_num)
			{
				if (!(ft_strnstr(exceptions, ft_strjoin(",", ft_strjoin(current->content, ",")), ft_strlen(exceptions)) && current_num < min_num))
				{
					min_num = current_num;
					min_node = current;
				}
			}
			current = current->next;
			//ft_printf("Min_num is: %d\n", min_num);
		 // Now min_node is the node with the smallest number;

		}
		// ft_printf("last_ordered at the end is: %s\n", last_ordered->content);
		// ft_printf("Exceptions list is: %s\n", exceptions);
		// ft_printf("List A at the end is: ");
		// print_list(headA);
		// ft_printf("\n");
		// ft_printf("Last ordered is: %s\n", last_ordered->content);
		// ft_printf("List B at the end is: ");
		// print_list(headB);
		// ft_printf("----------------\n");
		
	}
}
