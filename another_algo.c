/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   another_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:35:45 by ikondrat          #+#    #+#             */
/*   Updated: 2024/10/23 00:39:33 by aloiki           ###   ########.fr       */
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
		ft_printf(" ");
		current = current->next;
	}
}



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
		while (min_nodeA->next != NULL && min_nodeB->next != NULL)
			rr(headA, headB);
		if (min_nodeA->next == NULL && min_nodeB->next != NULL)
		{
			while (min_nodeB->next != NULL)
				rb(headB);
		}
		else
		{
			while (min_nodeA->next != NULL)
				ra(headA);
		}
	}
	else if (i < (ft_lstsize(*headA) / 2) && j < (ft_lstsize(*headB) / 2))
	{
		while (min_nodeA->next != NULL && min_nodeB->next != NULL)
			rrr(headA, headB);
		if (min_nodeA->next == NULL && min_nodeB->next != NULL)
		{
			while (min_nodeB->next != NULL)
				rrb(headB);
		}
		else
		{
			while (min_nodeA->next != NULL)
				rra(headA);
		}
	}
	else if (i >= (ft_lstsize(*headA) / 2) && j < (ft_lstsize(*headB) / 2))
	{
		while (min_nodeA->next != NULL)
			ra(headA);
		while (min_nodeB->next != NULL)
			rrb(headB);
	}
	else
	{
		while (min_nodeA->next != NULL)
			rra(headA);
		while (min_nodeB->next != NULL)
			rb(headB);

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

static void	neighbour_checkerA_B(t_list **headA, t_list **headB, t_list *min_nodeA, t_list *min_nodeB, char **exceptions)
{
	// NEED TO CHECK CONDITIONS< BECAUSE IF NO NEIGHBOURS ARE FOUND DOESNT MEAN THERE IS NO NEXT_MIN_NUM
	// FIX IT
	t_list	*current;
	t_list	*next_min_nodeA;
	t_list	*next_min_nodeB;
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
	ft_printf("Next min num A is: %d\n", next_min_numA);
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
	ft_printf("Next min num B is: %d\n", next_min_numB);
	// --------------------------------------
	if (next_min_nodeA && next_min_nodeB)
	{
		if ((next_min_nodeA->next == min_nodeA || min_nodeA->next == next_min_nodeA)
			&& (next_min_nodeB->next == min_nodeB || min_nodeB->next == next_min_nodeB))
		{
			ft_printf("both neighbours found\n");
			if (next_min_nodeA->next == min_nodeA && next_min_nodeB->next == min_nodeB)
			{
				ra_or_rra_or_rrr(headA, headB, min_nodeA, min_nodeB);
				ss(headA, headB);
				exception_adder(exceptions, min_nodeA->content, min_nodeB->content, next_min_nodeA->content, next_min_nodeB->content);
				return ;
				//neighbour_checker(headA, headB, next_min_node, next_min_num);
			}
			if (min_nodeA->next == next_min_nodeA && min_nodeB->next == next_min_nodeB)
			{
				ra_or_rra_or_rrr(headA, headB, next_min_nodeA, next_min_nodeB);
				exception_adder(exceptions, min_nodeA->content, min_nodeB->content, next_min_nodeA->content, next_min_nodeB->content);
				return ;
				//neighbour_checker(headA, headB, next_min_node, next_min_num);min_nodeA
			}
			if (next_min_nodeA->next == min_nodeA && min_nodeB->next == next_min_nodeB)
			{
				ra_or_rra_or_rrr(headA, headB, min_nodeA, next_min_nodeB);
				sa(headA);
				exception_adder(exceptions, min_nodeA->content, min_nodeB->content, next_min_nodeA->content, next_min_nodeB->content);
				return ;
			}
			else/*if (min_nodeA->next == next_min_nodeA && next_min_nodeB->next == min_nodeB)*/
			{
				ra_or_rra_or_rrr(headA, headB, next_min_nodeA, min_nodeB);
				sb(headA);
				exception_adder(exceptions, min_nodeA->content, min_nodeB->content, next_min_nodeA->content, next_min_nodeB->content);
				return ;
			}
		}
		else
		{
			ra_or_rra_or_rrr(headA, headB, min_nodeA, min_nodeB);
			return ;
		}
	}
	if ((!(next_min_nodeA)) && next_min_nodeB)
	{
		ft_printf("Neighbour B found\n");
		if (min_nodeB->next == next_min_nodeB)
		{
			ra_or_rra_or_rrr(headA, headB, min_nodeA, next_min_nodeB);
			exception_adder(exceptions, min_nodeA->content, min_nodeB->content, " ", next_min_nodeB->content);
			return ;
			
		}
		else/*if (next_min_nodeB->next == min_nodeB)*/
		{
			ra_or_rra_or_rrr(headA, headB, min_nodeA, min_nodeB);
			sb(headB);
			exception_adder(exceptions, min_nodeA->content, min_nodeB->content, " ", next_min_nodeB->content);
			return ;
		}
	}
	if ((!(next_min_nodeB)) && next_min_nodeA)
	{
		ft_printf("Neighbour A found\n");
		if (min_nodeA->next == next_min_nodeA)
		{
			ra_or_rra_or_rrr(headA, headB, next_min_nodeA, min_nodeB);
			exception_adder(exceptions, min_nodeA->content, min_nodeB->content, " ", next_min_nodeB->content);
			return ;
		}
		else/*if (next_min_nodeA->next == min_nodeA)*/
		{
			ra_or_rra_or_rrr(headA, headB, min_nodeA, min_nodeB);
			sa(headA);
			exception_adder(exceptions, min_nodeA->content, min_nodeB->content, " ", next_min_nodeB->content);
			return ;
		}
	}
	else
	{
		ft_printf("No neighbours found\n");
		ra_or_rra_or_rrr(headA, headB, min_nodeA, min_nodeB);
		exception_adder(exceptions, min_nodeA->content, min_nodeB->content, " ", " ");
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

void	another_algo(t_list **headA, t_list **headB, int size)
{
	//t_list		*current;
	t_list		*min_nodeA;
	t_list		*min_nodeB;
	char		*exceptions;
	int		i;
	// int			min_numA;
	// int			min_numB;
	// int			current_num;

	// size = ft_lstsize(*headA);
	ft_printf("A list in the beginning is: ");
	print_list(headA);
	ft_printf("\n");
	ft_printf("B list in the beginning is: ");
	print_list(headB);
	ft_printf("\n");
	exceptions = " ";
	i = 0;
	while (size > 0)
	{
		//current = *headA;
		// min_numA = INT_MAX;
		min_nodeA = NULL;
		// min_numB = INT_MAX;
		min_nodeB = NULL;
		// -------------------------
		min_nodeA = min_num_finder(headA, exceptions);
		min_nodeB = min_num_finder(headB, exceptions);
		exception_adder(&exceptions, min_nodeA->content, min_nodeB->content, "", "");
		// -------------------------
		// min_numA = ft_atoi(min_nodeA->content);
		// min_numB = ft_atoi(min_nodeB->content);
		ft_printf("Min num A is: %s\n", min_nodeA->content);
		ft_printf("Min num B is: %s\n", min_nodeB->content);
		neighbour_checkerA_B(headA, headB, min_nodeA, min_nodeB, &exceptions); 
		ft_printf("Exceptions are: %s\n", exceptions);
		ft_printf("List A is: ");
		print_list(headA);
		ft_printf("\n");
		ft_printf("List B is: ");
		print_list(headB);
		ft_printf("\n");
		// We are supposed to have the 2 min nums at the top, from A and B with or w/o neighbours
		size--;
		i++;
		ft_printf("Cycle number: %d\n", i);



	}
}
