/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodedup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:22:44 by aloiki            #+#    #+#             */
/*   Updated: 2024/10/16 18:27:14 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

t_list	*ft_nodedup(t_list *node)
{
	t_list	*dup;

	dup->content = ft_strdup(node->content)
	dup->next = NULL;
	return (dup);
}