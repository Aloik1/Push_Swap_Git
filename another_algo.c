/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   another_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:32:33 by aloiki            #+#    #+#             */
/*   Updated: 2024/10/24 17:57:33 by aloiki           ###   ########.fr       */
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
// 		ft_printf(" ");
// 		current = current->next;
// 	}
// }



static void	ra_or_rra_or_rrr(t_list **headA, t_list **headB, t_list *min_nodeA, t_list *min_nodeB)
{
	int		i;
	int		j;
	t_list	*currentA;
	t_list	*currentB;

	i = 0;
	j = 0;
	currentA = *headA;
	currentB = *headB;
	while (currentA != min_nodeA)
	{
		currentA = currentA->next;
		i++;
	}
	while (currentB != min_nodeB)
	{
		currentB = currentB->next;
		j++;
	}
	if (i >= (ft_lstsize(*headA) / 2) && j >= (ft_lstsize(*headB) / 2))
	{
		// ft_printf("i >= / 2 && j >= / 2\n");
		while (min_nodeA->next != NULL && min_nodeB->next != NULL)
		{
			rr(headA, headB);
			if (min_nodeA->next == NULL || min_nodeB->next == NULL)
				break ;
		}
		if (min_nodeA->next == NULL && min_nodeB->next != NULL)
		{
			while (min_nodeB->next != NULL)
				rb(headB);
		}
		if (min_nodeA->next != NULL && min_nodeB->next == NULL)
		{
			while (min_nodeA->next != NULL)
				ra(headA);
		}
		return ;
	}
	if (i < (ft_lstsize(*headA) / 2) && j < (ft_lstsize(*headB) / 2))
	{
		// ft_printf("i < / 2 && j < / 2\n");
		while (min_nodeA->next != NULL && min_nodeB->next != NULL)
		{
			rrr(headA, headB);
			if (min_nodeA->next == NULL || min_nodeB->next == NULL)
				break ;
		}
		if (min_nodeA->next == NULL && min_nodeB->next != NULL)
		{
			while (min_nodeB->next != NULL)
				rrb(headB);
		}
		if (min_nodeA->next != NULL && min_nodeB->next == NULL)
		{
			while (min_nodeA->next != NULL)
				rra(headA);
		}
		else
			return ;
	}
	if (i >= (ft_lstsize(*headA) / 2) && j < (ft_lstsize(*headB) / 2))
	{
		// ft_printf("i >= / 2 && j < / 2\n");
		while (min_nodeA->next != NULL)
			ra(headA);
		while (min_nodeB->next != NULL)
			rrb(headB);
		return ;
	}
	else
	{
		// ft_printf("i < / 2 && j >= / 2\n");
		while (min_nodeA->next != NULL)
			rra(headA);
		while (min_nodeB->next != NULL)
			rb(headB);
		return ;

	}
}

static void	exception_adder(char **exceptions, char *to_add_A, char *to_add_B, char *next_A, char *next_B)
{
	*exceptions = ft_strjoin(*exceptions, to_add_A);
	*exceptions = ft_strjoin(*exceptions, " ");
	*exceptions = ft_strjoin(*exceptions, to_add_B);
	*exceptions = ft_strjoin(*exceptions, " ");
	*exceptions = ft_strjoin(*exceptions, next_A);
	*exceptions = ft_strjoin(*exceptions, " ");
	*exceptions = ft_strjoin(*exceptions, next_B);
	*exceptions = ft_strjoin(*exceptions, " ");
}

static int	neighbour_checkerA_B(t_list **headA, t_list **headB, t_list *min_nodeA, t_list *min_nodeB, char **exceptions)
{
	t_list		*current;
	t_list		*next_min_nodeA;
	t_list		*next_min_nodeB;
	int		next_min_numA;
	int		next_min_numB;

	next_min_nodeA = NULL;
	next_min_nodeB = NULL;

	next_min_numA = INT_MAX;
	current = *headA;
	while (current != NULL)
	{
		if (ft_atoi(current->content) < next_min_numA)
		{
			if (ft_atoi(current->content) < next_min_numA  && ft_atoi(current->content) != ft_atoi(min_nodeA->content)
				&& (!(ft_strnstr(*exceptions, ft_strjoin(" ", ft_strjoin(current->content, " ")), ft_strlen(*exceptions)))))
			{
				next_min_numA = ft_atoi(current->content);
				next_min_nodeA = current;
			}
		}
		current = current->next;
	}
	// ft_printf("Next min num A is: %d\n", next_min_numA);
	// -------------------------------------
	next_min_numB = INT_MAX;
	current = *headB;
	while (current != NULL)
	{
		if (ft_atoi(current->content) < next_min_numB)
		{
			if (ft_atoi(current->content) < next_min_numB  && ft_atoi(current->content) != ft_atoi(min_nodeB->content)
				&& (!(ft_strnstr(*exceptions, ft_strjoin(" ", ft_strjoin(current->content, " ")), ft_strlen(*exceptions)))))
			{
				next_min_numB = ft_atoi(current->content);
				next_min_nodeB = current;
			}
		}
		current = current->next;
	}
	// ft_printf("Next min num B is: %d\n", next_min_numB);
	// --------------------------------------
	if (next_min_nodeA && next_min_nodeB)
	{
		// ft_printf("both mins found\n");
		if ((next_min_nodeA->next == min_nodeA || min_nodeA->next == next_min_nodeA)
			&& (next_min_nodeB->next == min_nodeB || min_nodeB->next == next_min_nodeB))
		{
			// ft_printf("Both neighbours found\n");
			if (next_min_nodeA->next == min_nodeA && next_min_nodeB->next == min_nodeB)
			{
				ra_or_rra_or_rrr(headA, headB, min_nodeA, min_nodeB);
				ss(headA, headB);
				exception_adder(exceptions, min_nodeA->content, min_nodeB->content, next_min_nodeA->content, next_min_nodeB->content);
				return (1);
				neighbour_checkerA_B(headA, headB, next_min_nodeA, next_min_nodeB, exceptions);
			}
			if (min_nodeA->next == next_min_nodeA && min_nodeB->next == next_min_nodeB)
			{
				ra_or_rra_or_rrr(headA, headB, next_min_nodeA, next_min_nodeB);
				exception_adder(exceptions, min_nodeA->content, min_nodeB->content, next_min_nodeA->content, next_min_nodeB->content);
				neighbour_checkerA_B(headA, headB, next_min_nodeA, next_min_nodeB, exceptions);
				return (1);
			}
			if (next_min_nodeA->next == min_nodeA && min_nodeB->next == next_min_nodeB)
			{
				ra_or_rra_or_rrr(headA, headB, min_nodeA, next_min_nodeB);
				sa(headA);
				exception_adder(exceptions, min_nodeA->content, min_nodeB->content, next_min_nodeA->content, next_min_nodeB->content);
				return (1);
			}
			else/*if (min_nodeA->next == next_min_nodeA && next_min_nodeB->next == min_nodeB)*/
			{
				ra_or_rra_or_rrr(headA, headB, next_min_nodeA, min_nodeB);
				sb(headB);
				exception_adder(exceptions, min_nodeA->content, min_nodeB->content, next_min_nodeA->content, next_min_nodeB->content);
				neighbour_checkerA_B(headA, headB, next_min_nodeA, next_min_nodeB, exceptions);
				return (1);
			}
		}
		if ((next_min_nodeA->next != min_nodeA && min_nodeA->next != next_min_nodeA)
			&& (next_min_nodeB->next == min_nodeB || min_nodeB->next == next_min_nodeB))
		{
			// ft_printf("Neighbour B found\n");
			if (next_min_nodeB->next == min_nodeB)
			{
				ra_or_rra_or_rrr(headA, headB, min_nodeA, min_nodeB);
				sb(headB);
				pb(headA, headB);
				ra_or_rra_or_rrr(headA, headB, next_min_nodeA, min_nodeB->next->next);
				pa(headA, headB);
				sa(headA);
				exception_adder(exceptions, min_nodeA->content, min_nodeB->content, next_min_nodeA->content, next_min_nodeB->content);
				neighbour_checkerA_B(headA, headB, next_min_nodeA, next_min_nodeB, exceptions);
				return (2);
			}
			else
			{
				ra_or_rra_or_rrr(headA, headB, min_nodeA, next_min_nodeB);
				pb(headA, headB);
				ra_or_rra_or_rrr(headA, headB, next_min_nodeA, min_nodeB->next->next);
				pa(headA, headB);
				sa(headA);
				exception_adder(exceptions, min_nodeA->content, min_nodeB->content, next_min_nodeA->content, next_min_nodeB->content);
				neighbour_checkerA_B(headA, headB, next_min_nodeA, next_min_nodeB, exceptions);
				return (2);
			}
		}
		if ((next_min_nodeA->next == min_nodeA || min_nodeA->next == next_min_nodeA)
			&& (next_min_nodeB->next != min_nodeB && min_nodeB->next != next_min_nodeB))
		{
			// ft_printf("Neighbour A found\n");
			if (next_min_nodeA->next == min_nodeA)
			{
				ra_or_rra_or_rrr(headA, headB, min_nodeA, min_nodeB);
				sa(headA);
				pa(headA, headB);
				ra_or_rra_or_rrr(headA, headB, min_nodeA->next->next, next_min_nodeB);
				pb(headA, headB);
				sb(headB);
				exception_adder(exceptions, min_nodeA->content, min_nodeB->content, next_min_nodeA->content, next_min_nodeB->content);
				neighbour_checkerA_B(headA, headB, next_min_nodeA, next_min_nodeB, exceptions);
				return (3);
			}
			else
			{
				ra_or_rra_or_rrr(headA, headB, next_min_nodeA, min_nodeB);
				pa(headA, headB);
				ra_or_rra_or_rrr(headA, headB, min_nodeA->next->next, next_min_nodeB);
				pb(headA, headB);
				sb(headB);
				exception_adder(exceptions, min_nodeA->content, min_nodeB->content, next_min_nodeA->content, next_min_nodeB->content);
				neighbour_checkerA_B(headA, headB, next_min_nodeA, next_min_nodeB, exceptions);
				return (3);
			}
		}
		else
		{

			ra_or_rra_or_rrr(headA, headB, min_nodeA, min_nodeB);
			return (0);
		}
	}
	if ((!(next_min_nodeA)) && next_min_nodeB)
	{
		// ft_printf("Next min B found\n");
		if (min_nodeB->next == next_min_nodeB)
		{
			ra_or_rra_or_rrr(headA, headB, min_nodeA, next_min_nodeB);
			exception_adder(exceptions, min_nodeA->content, min_nodeB->content, "", next_min_nodeB->content);
			return (4);
			
		}
		else/*if (next_min_nodeB->next == min_nodeB)*/
		{
			ra_or_rra_or_rrr(headA, headB, min_nodeA, min_nodeB);
			sb(headB);
			exception_adder(exceptions, min_nodeA->content, min_nodeB->content, "", next_min_nodeB->content);
			return (4);
		}
	}
	if ((!(next_min_nodeB)) && next_min_nodeA)
	{
		// ft_printf("Next min A found\n");
		if (min_nodeA->next == next_min_nodeA)
		{
			ra_or_rra_or_rrr(headA, headB, next_min_nodeA, min_nodeB);
			exception_adder(exceptions, min_nodeA->content, min_nodeB->content, next_min_nodeA->content, "");
			return (5);
		}
		else/*if (next_min_nodeA->next == min_nodeA)*/
		{
			ra_or_rra_or_rrr(headA, headB, min_nodeA, min_nodeB);
			sa(headA);
			exception_adder(exceptions, min_nodeA->content, min_nodeB->content, next_min_nodeA->content, "");
			return (5);
		}
	}
	else
	{
		// ft_printf("No mins found\n");
		ra_or_rra_or_rrr(headA, headB, min_nodeA, min_nodeB);
		exception_adder(exceptions, min_nodeA->content, min_nodeB->content, "", "");
		return (0);
	}
}

static void	last_ordered_establisher_neighbours(t_list **last_orderedA, t_list **last_orderedB, t_list **headA, t_list **headB)
{
	t_list	*currentA;
	t_list	*currentB;
	
	currentA = *headA;
	while (currentA->next->next != NULL)
		currentA = currentA->next;
	// --------------------------------
	currentB = *headB;
	while (currentB->next->next != NULL)
		currentB = currentB->next;
	
	if (*last_orderedA == NULL && *last_orderedB == NULL)
	{
		// ft_printf("No last ordered yet\n");
		*last_orderedA = currentA->next;
		*last_orderedB = currentB->next;
		return ;
	}
	if ((*last_orderedA != NULL) && (*last_orderedA)->next != currentA
		&& (*last_orderedB != NULL) && (*last_orderedB)->next != currentB)
	{
		// ft_printf("Need to order both\n");
		pb(headA, headB);
		pb(headA, headB);
		ra_or_rra_or_rrr(headA, headB, *last_orderedA, currentA);
		pa(headA, headB);
		pa(headA, headB);
		// --------------------------------------
		pa(headA, headB);
		pa(headA, headB);
		ra_or_rra_or_rrr(headA, headB, currentB, *last_orderedB);
		pb(headA, headB);
		pb(headA, headB);
		*last_orderedA = currentA->next;
		*last_orderedB = currentB->next;
		return ;
	}
	if ((*last_orderedA != NULL) && (*last_orderedA)->next == currentA
		&& (*last_orderedB != NULL) && (*last_orderedB)->next != currentB)
	{
		// ft_printf("Need to order B\n");
		*last_orderedA = currentA->next;
		pa(headA, headB);
		pa(headA, headB);
		ra_or_rra_or_rrr(headA, headB, currentB, *last_orderedB);
		pb(headA, headB);
		pb(headA, headB);
		*last_orderedB = currentB->next;
	}
	if ((*last_orderedA != NULL) && (*last_orderedA)->next != currentA
		&& (*last_orderedB != NULL) && (*last_orderedB)->next == currentB)
	{
		// ft_printf("Need to order A\n");
		*last_orderedB = currentB->next;
		pb(headA, headB);
		pb(headA, headB);
		ra_or_rra_or_rrr(headA, headB, *last_orderedA, currentA);
		pa(headA, headB);
		pa(headA, headB);
		*last_orderedA = currentA->next;
	}
	else /*((*last_orderedA)->next == currentA)*/
	{
		// ft_printf("Both already ordered\n");
		*last_orderedA = currentA->next;
		*last_orderedB = currentB->next;
		return ;
	}	
}

static void	last_ordered_establisher(t_list **last_orderedA, t_list **last_orderedB, t_list **headA, t_list **headB)
{
	t_list	*currentA;
	t_list	*currentB;
	
	currentA = *headA;
	while (currentA->next != NULL)
		currentA = currentA->next;
	// --------------------------------
	currentB = *headB;
	while (currentB->next != NULL)
		currentB = currentB->next;
	if (*last_orderedA == NULL && *last_orderedB == NULL)
	{
		// ft_printf("No last ordered yet\n");
		*last_orderedA = currentA;
		*last_orderedB = currentB;
		return ;
	}
	if ((*last_orderedA)->next == currentA && (*last_orderedB)->next == currentB)
	{
		*last_orderedA = (*last_orderedA)->next;
		*last_orderedB = (*last_orderedB)->next;
		return ;
	}
	if ((*last_orderedA)->next != currentA && (*last_orderedB)->next != currentB)
	{
		// ft_printf("Need to order both last ordered\n");
		pb(headA, headB);
		ra_or_rra_or_rrr(headA, headB, *last_orderedA, currentA);
		pa(headA, headB);
		pa(headA, headB);
		ra_or_rra_or_rrr(headA, headB, currentA->next, *last_orderedB);
		pb(headA, headB);
		*last_orderedA = currentA;
		*last_orderedB = currentB;
		return ;
	}
	if ((*last_orderedA)->next == currentA && (*last_orderedB)->next != currentB)
	{
		// ft_printf("Need to order last ordered B\n");
		*last_orderedA = currentA;
		pa(headA, headB);
		ra_or_rra_or_rrr(headA, headB, currentB, *last_orderedB);
		pb(headA, headB);
		*last_orderedB = currentB;
		return ;
	}
	if ((*last_orderedA)->next != currentA && (*last_orderedB)->next == currentB)
	{
		// ft_printf("Need to order last ordered A\n");
		*last_orderedB = currentB;
		pb(headA, headB);
		ra_or_rra_or_rrr(headA, headB, *last_orderedA, currentA);
		pa(headA, headB);
		*last_orderedA = currentA;
		return ;
	}	
}

static t_list	*min_num_finder(t_list **head, char *exceptions)
{
	t_list		*current;
	t_list		*min_node;
	int			min_num;
	int			current_num;

	current = *head;
	min_num = INT_MAX;
	min_node = NULL;
	while (current)
	{
		current_num = ft_atoi(current->content);
		if (current_num < min_num
			&& (!(ft_strnstr(exceptions, ft_strjoin(" ", ft_strjoin(current->content, " ")), ft_strlen(exceptions)))))
		{
			min_num = current_num;
			min_node = current;
		}
		current = current->next;
	}
	return (min_node);
}

static void	final_combiner(t_list **headA, t_list **headB)
// MAKE THE FIRST ROUND FOLLOW SAME RULES AS THE REST
{
	t_list	*current;
	t_list	*min_node;
	//int	first;

	//first = 0;
	min_node = NULL;
	if (ft_atoi((*headA)->content) < ft_atoi((*headB)->content))
		min_node = *headA;
	else
		min_node = *headB;
	while ((*headB))
	{
		current = *headA;
		while (current->next != NULL)
			current = current->next;
		if (ft_atoi((*headB)->content) < ft_atoi((*headA)->content))
		{
			// ft_printf("headB is smaller than headA\n");
			if (ft_atoi((*headB)->content) < ft_atoi(current->content))
			{
				// ft_printf("headB is smaller than currentA\n");
				rrb(headB);
				pa(headA, headB);
			}
			else // ft_atoi((*headB)->content) > ft_atoi(current->content)
			{
				// ft_printf("headB is bigger than currentA\n");
				rrb(headB);
				pa(headA, headB);
			}
		}
		else // (ft_atoi((*headB)->content) > ft_atoi((*headA)->content))
		{
			// ft_printf("headB is bigger than headA and implicitly bigger than current\n");
			rra(headA);
			if (*headA == min_node)
			 	pa(headA, headB);
		}
		// ft_printf("List A is: ");
		// print_list(headA);
		// ft_printf("\n");
		// ft_printf("List B is: ");
		// print_list(headB);
		// ft_printf("\n");
		//first = 1;
	}
	current = *headA;
	while (current->next != NULL)
		current = current->next;
	while (ft_atoi((*headA)->content) > ft_atoi(current->content))
	{
		current = *headA;
		while (current->next != NULL)
			current = current->next;
		rra(headA);
	}

}

void	another_algo(t_list **headA, t_list **headB, int size)
{
	t_list		*min_nodeA;
	t_list		*min_nodeB;
	t_list		*last_orderedA;
	t_list		*last_orderedB;
	char		*exceptions;
	int		i;
	int		neighbour_checker;

	// size = ft_lstsize(*headA);
	// ft_printf("A list in the beginning is: ");
	// print_list(headA);
	// ft_printf("\n");
	// ft_printf("B list in the beginning is: ");
	// print_list(headB);
	// ft_printf("\n");
	last_orderedA = NULL;
	last_orderedB = NULL;
	exceptions = " ";
	i = 0;
	while (size > 0)
	{
		min_nodeA = NULL;
		min_nodeB = NULL;
		// -------------------------
		min_nodeA = min_num_finder(headA, exceptions);
		min_nodeB = min_num_finder(headB, exceptions);
		if (min_nodeA == NULL && min_nodeB == NULL)
			break ;
		exception_adder(&exceptions, min_nodeA->content, min_nodeB->content, "", "");
		// -------------------------
		// ft_printf("Min num A is: %s\n", min_nodeA->content);
		// ft_printf("Min num B is: %s\n", min_nodeB->content);
		neighbour_checker = neighbour_checkerA_B(headA, headB, min_nodeA, min_nodeB, &exceptions);
		if (neighbour_checker == 1)
		{
			// ft_printf("neighbour checker returned 1\n");
			// ft_printf("List A is: ");
			// print_list(headA);
			// ft_printf("\n");
			// ft_printf("List B is: ");
			// print_list(headB);
			// ft_printf("\n");
			last_ordered_establisher_neighbours(&last_orderedA, &last_orderedB, headA, headB);
		}
		if (neighbour_checker == 2)
		{
			// ft_printf("neighbour checker returned 2\n");
			last_ordered_establisher_neighbours(&last_orderedA, &last_orderedB, headA, headB);
			// ft_printf("List A is: ");
			// print_list(headA);
			// ft_printf("\n");
			// ft_printf("List B is: ");
			// print_list(headB);
			// ft_printf("\n");
			
		}
		if (neighbour_checker == 3)
		{
			// ft_printf("neighbour checker returned 3\n");
			last_ordered_establisher_neighbours(&last_orderedA, &last_orderedB, headA, headB);
			// ft_printf("List A is: ");
			// print_list(headA);
			// ft_printf("\n");
			// ft_printf("List B is: ");
			// print_list(headB);
			// ft_printf("\n");
		}
		if (neighbour_checker == 4)
		{
			// ft_printf("neighbour checker returned 4\n");
			last_ordered_establisher_neighbours(&last_orderedA, &last_orderedB, headA, headB);
			// ft_printf("List A is: ");
			// print_list(headA);
			// ft_printf("\n");
			// ft_printf("List B is: ");
			// print_list(headB);
			// ft_printf("\n");
		}
		if (neighbour_checker == 5)
		{
			// ft_printf("neighbour checker returned 5\n");
			last_ordered_establisher_neighbours(&last_orderedA, &last_orderedB, headA, headB);
			// ft_printf("List A is: ");
			// print_list(headA);
			// ft_printf("\n");
			// ft_printf("List B is: ");
			// print_list(headB);
			// ft_printf("\n");
		}
		if (!(neighbour_checker))
			last_ordered_establisher(&last_orderedA, &last_orderedB, headA, headB);
		// ft_printf("Exceptions are: %s\n", exceptions);
		// ft_printf("Last ordered A is: %s, Last ordered B is: %s\n", last_orderedA->content, last_orderedB->content);
		// ft_printf("List A is: ");
		// print_list(headA);
		// ft_printf("\n");
		// ft_printf("List B is: ");
		// print_list(headB);
		// ft_printf("\n");
		// We are supposed to have the 2 min nums at the top, from A and B with or w/o neighbours
		size--;
		i++;
		// ft_printf("--------------------------------------\n");
		// ft_printf("Cycle number: %d\n", i);
	}
	final_combiner(headA, headB);
}
