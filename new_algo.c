/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:35:45 by ikondrat          #+#    #+#             */
/*   Updated: 2024/10/19 20:56:31 by aloiki           ###   ########.fr       */
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

void	new_algo(t_list **headA, t_list **headB, int size)
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
	while (size > 0)
	{
		current = *headA;
		min_num = INT_MAX;
		min_node = NULL;
		i = 0;
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
		} // Now min_node is the node with the smallest number;
		if (min_node == NULL)
			break ;
		ft_printf("min_num is: %d", min_num);
		write (1, "\n", 1);
		if (size == ft_lstsize(*headA))
			last_ordered = min_node;
		else
		{
			current = *headA;
			if (!(last_ordered->next == min_node))
			{

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
						// puts the min_node to the top if nodes are not next to each other;
				
			}
			else
				last_ordered = last_ordered->next;

			if (min_node->next == NULL)
			{
				pb(headA, headB);
				ft_printf("pb");
				write (1, "\n", 1);
				// ft_printf("List A is: ");
				// print_list(headA);
				// write (1, "\n", 1);
				// ft_printf("List B is: ");
				// print_list(headB);
				// write (1, "\n", 1);
				current = *headA;
				if (last_ordered != NULL && *headA == last_ordered)
				{
					rra(headA);
					ft_printf("rra");
					write (1, "\n", 1);
				}
				i = 0;
				while (current != last_ordered)
				{
					current = current->next;
					i++;
				}
				if (i <= (ft_lstsize(*headA) / 2))
				{

					while (last_ordered != NULL && last_ordered->next != NULL)
					{
						ra(headA);
						ft_printf("ra");
						write (1, "\n", 1);
					}
	
				}
				else
				{
					while (last_ordered->next != NULL)
					{
						rra(headA);
						ft_printf("rra");
						write (1, "\n", 1);
					}
				} // now he have our last_ordered at the top
				pa(headA, headB);
				last_ordered = last_ordered->next;
				ft_printf("pa");
				write (1, "\n", 1);
			}
		}
		// ft_printf("List A at the end is: ");
		// print_list(headA);
		// write (1, "\n", 1);
		// ft_printf("List B at the end is: ");
		// print_list(headB);
		// write (1, "\n", 1);
		// ft_printf("----------------");
		// write (1, "\n", 1);
		exceptions = ft_strjoin(exceptions, min_node->content);
		exceptions = ft_strjoin(exceptions, ",");
		size--;

	}
}
