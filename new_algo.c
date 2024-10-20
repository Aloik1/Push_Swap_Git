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

static void	print_list(t_list **headA)
{
	t_list	*current;

	current = *headA;
	while (current != NULL)
	{
		ft_printf("%s", current->content);
		current = current->next;
	}
}

static void	ra_or_rra(t_list **headA, t_list *min_node)
{
	int		i;
	int		first;
	t_list	*current;

	i = 0;
	first = 0;
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
static int	neighbour_checker(t_list **headA, t_list **headB, t_list *min_node, int min_num)
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
void	new_algo(t_list **headA, t_list **headB, int size)
{
	t_list	*last_ordered;
	t_list	*min_node;
	t_list	*current;
	char	*exceptions;
	int	current_num;
	int	min_num;

	exceptions = ft_strdup(",");
	last_ordered = NULL;
	while (size > 0)
	{
		current = *headA;
		min_num = INT_MAX;
		min_node = NULL;
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
		ft_printf("min_num is: %d\n", min_num);
		if (size == ft_lstsize(*headA))
			last_ordered = min_node;
		else
		{
			current = *headA;
			if (!(neighbour_checker(headA, headB, min_node, min_num)))
			{
				ra_or_rra(headA, min_node); // puts the min_node to the top if nodes are not next to each other;
			}
			else
				last_ordered = last_ordered->next;

			if (min_node->next == NULL)
			{
				pb(headA, headB);
				ft_printf("pb\n");
				current = *headA;
				if (last_ordered != NULL && *headA == last_ordered)
				{
					rra(headA);
					ft_printf("rra\n");
				}
				ra_or_rra(headA, last_ordered); // now he have our last_ordered at the top
				pa(headA, headB);
				ft_printf("pa\n");
				last_ordered = last_ordered->next;
			}
		}
		ft_printf("List A at the end is: ");
		print_list(headA);
		write (1, "\n", 1);
		ft_printf("List B at the end is: ");
		print_list(headB);
		write (1, "\n", 1);
		ft_printf("----------------\n");
		exceptions = ft_strjoin(exceptions, min_node->content);
		exceptions = ft_strjoin(exceptions, ",");
		size--;

	}
}
