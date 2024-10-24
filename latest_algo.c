/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   latest_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:35:45 by ikondrat          #+#    #+#             */
/*   Updated: 2024/10/24 23:05:57 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

// CAN POTENTIALLY MAKE IT ALWAYS ORDER 2 ELEMENTS, THIS WAY WE DONT NEED TO LIFT 1 THEN LIFT ANOTHER, WE LIFT BOTH

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

static t_list	*min_num_finder(t_list **head, t_list *last_ordered)
{
	t_list		*current;
	t_list		*min_node;
	int		min_num;
	int		current_num;

	current = *head;
	min_num = INT_MAX;
	min_node = NULL;
	while (current)
	{
		current_num = ft_atoi(current->content);
		if (current_num < min_num && current != last_ordered)
		{
			min_num = current_num;
			min_node = current;
		}
		current = current->next;
	}
	return (min_node);
}

static t_list	*neighbour_checker(t_list **headA, t_list **min_node, t_list **last_ordered)
{
	t_list		*current;
	t_list		*next_min_node;
	int		next_min_num;
	int		current_num;

	next_min_node = NULL;
	next_min_num = INT_MAX;
	current = *headA;
	if (*min_node == NULL)
		return (NULL);
	while (current != NULL)
	{
		current_num = ft_atoi(current->content);
		if (current_num < next_min_num  && current != *min_node && current != *last_ordered)		
		{
			next_min_num = current_num;
			next_min_node = current;
		}
		current = current->next;
	}
	// ft_printf("Next min num is: %d\n", next_min_num);
	if (next_min_node == NULL)
		return NULL;
	if (next_min_node->next == *min_node)
	{
		// ft_printf("Next min num is before min num\n");
		ra_or_rra(headA, *min_node);
		sa(headA);
		(*min_node)->content = ft_strjoin((*min_node)->content, ft_strjoin(" ", next_min_node->content));
		(*min_node)->next =  next_min_node->next;
		ft_lstdelone(next_min_node, free);
		// *min_node = min_num_finder(headA, *last_ordered);
		// if (!min_node)
		// 	return (0);
		// neighbour_checker(headA, min_node, last_ordered);
		return (*min_node);
	}
	if ((*min_node)->next == next_min_node)
	{
		// ft_printf("Next min num is after min num\n");
		ra_or_rra(headA, next_min_node);
		(*min_node)->content = ft_strjoin((*min_node)->content, ft_strjoin(" ", next_min_node->content));
		(*min_node)->next =  next_min_node->next;
		ft_lstdelone(next_min_node, free);
		// *min_node = min_num_finder(headA, *last_ordered);
		// if (!min_node)
		// 	return (0);
		// neighbour_checker(headA, min_node, last_ordered);
		return (*min_node);
	}
	else
	{
		// ft_printf("No next min nums neighbour\n");
		ra_or_rra(headA, *min_node);
		return NULL;
	}
}


static int	neighbour_checker_first(t_list **headA, t_list *min_node, int min_num, t_list **last_ordered)
{
	t_list		*current;
	t_list		*next_min_node;
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
		if (current_num < next_min_num  && current_num != min_num && current != *last_ordered)
		{
			next_min_num = current_num;
			next_min_node = current;
		}
		current = current->next;
	}
	// ft_printf("Next min num is: %d\n", next_min_num);
	if (next_min_node == NULL)
		return (0);
	if (next_min_node->next == min_node)
	{
		// ft_printf("first neighbour is before min num\n");
		ra_or_rra(headA, min_node);
		sa(headA);
		(*last_ordered)->content = ft_strjoin((*last_ordered)->content, ft_strjoin(" ", next_min_node->content));
		(*last_ordered)->next = next_min_node->next;
		ft_lstdelone(next_min_node, free);
		min_node = min_num_finder(headA, *last_ordered);
		if (!min_node)
			return (0);
		min_num = ft_atoi(min_node->content);
		neighbour_checker_first(headA, min_node, min_num, last_ordered);
		return (1);
	}
	if (min_node->next == next_min_node)
	{
		// ft_printf("first neighbour is after min num\n");
		(*last_ordered)->content = ft_strjoin((*last_ordered)->content, ft_strjoin(" ", next_min_node->content));
		(*last_ordered)->next = next_min_node->next;
		ft_lstdelone(next_min_node, free);
		min_node = min_num_finder(headA, *last_ordered);
		if (!min_node)
			return (0);
		min_num = ft_atoi(min_node->content);
		neighbour_checker_first(headA, min_node, min_num, last_ordered);

		return (1);
	}
	else
	{
		// ft_printf("They be random\n");
		return (0);
	}
	return (0);
}


void	latest_algo(t_list **headA, t_list **headB, int size)
{
	t_list	*last_ordered;
	t_list	*min_node;
	t_list	*current;
	int	min_num;

	last_ordered = ft_lstnew(ft_strdup(""));
	current = *headA;
	min_node = current;
	// ft_printf("List A at the beginning is: ");
	// print_list(headA);
	while (min_node != NULL && ft_lstsize(*headA) != 1)
	{
		
		// min_num = INT_MAX;
		current = *headA; 
		min_node = min_num_finder(headA, last_ordered);
		min_num = ft_atoi(min_node->content);
		// Now min_node is the node with the smallest number;
		// ft_printf("Min number is: %s\n", min_node->content);

		if (min_node == NULL)
		{
			break ;
		}
		if (ft_lstsize(*headA) == 2 && min_node->next == last_ordered)
		{
			rra(headA);
			break ;
		}
		if (ft_atoi(last_ordered->content) == 0)
		{
			last_ordered = min_num_finder(headA, last_ordered);
			if (neighbour_checker_first(headA, min_node, min_num, &last_ordered))
			{
				// ft_printf("Found first neighbours\n");
				size = size - 2;
			}
			else
			{
				// ft_printf("No first neighbours\n");
				size--;
			}
		}
		else
		{
			current = *headA;
			if (!(neighbour_checker(headA, &min_node, &last_ordered)))
			{
				// ft_printf("List A is: ");
				// print_list(headA);
				ra_or_rra(headA, min_node); // puts the min_node to the top if nodes are not next to each other;
				if (last_ordered->next == min_node)
				{
					// ft_printf("Last ordered is before min num\n");
					last_ordered->content = ft_strjoin(last_ordered->content, ft_strjoin(" ", min_node->content));
					last_ordered->next = min_node->next;
					ft_lstdelone(min_node, free);
				}
				else
				{
					// ft_printf("Last ordered is not before min num\n");
					pb(headA, headB);
					ra_or_rra(headA, last_ordered);
					pa(headA, headB);
					last_ordered->content = ft_strjoin(last_ordered->content, ft_strjoin(" ", min_node->content));
					last_ordered->next = min_node->next;
					ft_lstdelone(min_node, free);
				}
				size--;
			}
			else
			{
				while (neighbour_checker(headA, &min_node, &last_ordered))
				{
					// ft_printf("List A at the beginning is: ");
					// print_list(headA);
					if (last_ordered->next != min_node)
					{
						pb(headA, headB);
						ra_or_rra(headA, last_ordered); // now he have our last_ordered at the top
						pa(headA, headB);
						last_ordered->content = ft_strjoin(last_ordered->content, ft_strjoin(" ", min_node->content));
						last_ordered->next = min_node->next;
						ft_lstdelone(min_node, free);
						min_node = min_num_finder(headA, last_ordered);
						neighbour_checker(headA, &min_node, &last_ordered);
						size--;
					}
					else
					{
						last_ordered->content = ft_strjoin(last_ordered->content, ft_strjoin(" ", min_node->content));
						last_ordered->next = min_node->next;
						ft_lstdelone(min_node, free);
						min_node = min_num_finder(headA, last_ordered);
						neighbour_checker(headA, &min_node, &last_ordered);
						size = size - 2;
					}
				}
			}
			// ft_printf("last_ordered is: %s\n", last_ordered->content);
		}
		// ft_printf("last_ordered at the end is: %s\n", last_ordered->content);
		// ft_printf("Exceptions list is: %s\n", exceptions);
		// ft_printf("List A at the end is: ");
		// print_list(headA);
		// ft_printf("\n");
		// ft_printf("Last ordered is: %s\n", last_ordered->content);

		// ft_printf("List B at the end is: ");
		// print_list(headB);
		// write (1, "\n", 1);
		// ft_printf("----------------\n");

	}
}