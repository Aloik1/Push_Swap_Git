/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikondrat <ikondrat@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-14 18:02:59 by ikondrat          #+#    #+#             */
/*   Updated: 2024-10-14 18:02:59 by ikondrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	create_lists(char **argv, int i)
{
	t_list	**firstnode;
	t_list	*newnode;

	if (i == 1) 
	{
		newnode = ft_lstnew(argv[1]);
		create_lists(argv, i++);
	}
	if (argv[i])
	{
		firstnode = &newnode;
		ft_lstadd_back(firstnode, ft_lstnew(argv[i]));
		create_lists(argv, i++);
	}
	return (0);
}