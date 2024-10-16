/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikondrat <ikondrat@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-14 17:32:28 by ikondrat          #+#    #+#             */
/*   Updated: 2024-10-14 17:32:28 by ikondrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	i;
	t_list	*firstnode;
	t_list	*newnode;
	char	*content;

	(void)argc;
	i = 1;
	firstnode = NULL;
	ft_printf("%d", argc);
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
			ft_lstadd_back(&firstnode, newnode);
			ft_printf("%s", newnode->content);
			i++;
		}
	}
	ft_lstclear(&firstnode, free);
	return (0);
}