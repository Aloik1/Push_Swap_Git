/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikondrat <ikondrat@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-18 11:35:45 by ikondrat          #+#    #+#             */
/*   Updated: 2024-10-18 11:35:45 by ikondrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

/*void	algo(t_list **headA, t_list **headB)
{
	t_list	*current;
	int		i;
	int		num;
	while ((*headA)->content != NULL)
	{
		current = *headA;
		num = ft_atoi(current->content);
		current = current->next;
		while (current != NULL)
		{
			if (num < ft_atoi(current->content))
				current = current->next;
		//potential to optimize.A rule if multiple numbers are the same value
			else
			{
				num = ft_atoi(current->content);
				current = current->next;
			}
		}
		i = 0;
		current = *headA;
		while (ft_atoi(current->content) != num)
		{
			current = current->next;
			i++;
		}
		if (i > ft_lstsize(*headA) / 2)
		{
			while (current->next != NULL)
				ra(headA);
			pb(headA, headB);
			if (ft_lstsize(*headB) > 1)
				rb(headB);
		}
		else if (i < ft_lstsize(*headA) / 2)
		{
			while (current->next != NULL)
				rra(headA);
			pb(headA, headB);
			if (ft_lstsize(*headB) > 1)
				rb(headB);
		}
		while (ft_lstsize(*headB) != 0)
		{
			pa(headA, headB);
		}
	}
}*/


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikondrat <ikondrat@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-18 11:35:45 by ikondrat          #+#    #+#             */
/*   Updated: 2024-10-18 11:35:45 by ikondrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	algo(t_list **headA, t_list **headB)
{
	t_list	*current;
	int		i;
	int		num;
	int		size;

	size = ft_lstsize(*headA);
	while (size > 0)
	{
		current = *headA;
		num = ft_atoi(current->content);
		current = current->next;
		while (current != NULL)
		{
			if (num < ft_atoi(current->content))
				current = current->next;
		//potential to optimize.A rule if multiple numbers are the same value
			else
			{
				num = ft_atoi(current->content);
				current = current->next;
			}
		}
		i = 0;
		current = *headA;
		while (ft_atoi(current->content) != num)
		{
			current = current->next;
			i++;
		}
		if (ft_lstsize(*headA) == 1)
		{
			pb(headA, headB);
			rb(headB);
		}
		if (i > ft_lstsize(*headA) / 2)
		{
			while (current->next != NULL)
				ra(headA);
			pb(headA, headB);
			if (ft_lstsize(*headB) > 1)
				rb(headB);
		}
		if (i < ft_lstsize(*headA) / 2)
		{
			while (current->next != NULL)
				rra(headA);
			pb(headA, headB);
			if (ft_lstsize(*headB) > 1)
				rb(headB);
		}
		/*while (ft_lstsize(*headB) != 0)
		{
			pa(headA, headB);
		}*/
		size--;
	}
	pa(headA, headB);
}
