/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:32:28 by ikondrat          #+#    #+#             */
/*   Updated: 2024/10/16 21:02:30 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	print_list(t_list **head)
{
	t_list	*current;

	current = *head;
	while (current != NULL)
	{
		ft_printf("%s", current->content);
		current = current->next;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	t_list	*head;
	t_list	*newnode;
	char	*content;

	(void)argc;
	i = 1;
	head = NULL;
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
				return (0);
			}
			ft_lstadd_back(&head, newnode);
			//ft_printf("%s", newnode->content);
			i++;
		}
	}
	sa(&head, argc);
	print_list(&head);
	ft_lstclear(&head, free);
	return (0);
}
