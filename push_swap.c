/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:32:28 by ikondrat          #+#    #+#             */
/*   Updated: 2024/10/21 23:14:19 by aloiki           ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	int	i;
	t_list	*headA;
	t_list	*headB;
	t_list	*newnode;
	char	*content;

	(void)argc;
	i = argc - 1;
	headA = NULL;
	headB = NULL;
	if (argc > 1)
	{
		while (i >= 1)
		{
			content = ft_strdup(argv[i]);
			if (!content)
				return (0);
			newnode = ft_lstnew(content);
			if (!newnode)
			{
				free(content);
				ft_lstclear(&headA, free);
				return (0);
			}
			ft_lstadd_front(&headA, newnode);
			//ft_printf("%s", newnode->content);
			i--;
		}
	}
	headB = NULL;
	i = 0;
	while (i != (argc - 1) / 2)
	{
		pb(&headA, &headB);
		i++;
	}
	new_algo(&headA, &headB, ft_lstsize(headA));
	
	// while (headB != NULL)
	// {
	// 	pa(&headA, &headB);
	// 	i--;
	// }
	// ft_printf("Starting second algo\n");
	// new_algo(&headB, &headA, ft_lstsize(headB));
	//algo(&headA, &headB, (argc - 1) / 2);
	ft_printf("A list in the end is: ");
	print_list(&headA);
	write (1, "\n", 1);
	ft_printf("B list in the end is: ");
	print_list(&headB);
	write (1, "\n", 1);
	ft_lstclear(&headA, free);
	ft_lstclear(&headB, free);
	return (0);
}
