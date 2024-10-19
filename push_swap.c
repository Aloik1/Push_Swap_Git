/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:32:28 by ikondrat          #+#    #+#             */
/*   Updated: 2024/10/19 15:50:54 by aloiki           ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	int	i;
	t_list	*headA;
	t_list	*headB;
	t_list	*newnode;
	char	*content;

	(void)argc;
	i = 1;
	headA = NULL;
	headB = NULL;
	if (argc > 1)
	{
		while (argv[i])
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
			ft_lstadd_back(&headA, newnode);
			//ft_printf("%s", newnode->content);
			i++;
		}
	}
	headB = ft_lstsizedup(&headA);
	algo(&headA, &headB, i);
	print_list(&headA);
	ft_lstclear(&headA, free);
	ft_lstclear(&headB, free);
	return (0);
}
