/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:43:28 by ikondrat          #+#    #+#             */
/*   Updated: 2024/10/19 13:33:41 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include <limits.h>

int	create_lists(char **argv, int i);
void	sa(t_list **headA, int argc);
void	sb(t_list **headB, int argc);
void	ss(t_list **headA, t_list **headB, int argc);
void	pa(t_list **headA, t_list **headB);
void	pb(t_list **headA, t_list **headB);
void	ra(t_list **headA);
void	rb(t_list **headB);
void	rr(t_list **headA, t_list **headB);
void	rra(t_list **headA);
void	rrb(t_list **headB);
void	rrr(t_list **headA, t_list **headB);

t_list	*ft_lstsizedup(t_list **headA);
void	algo(t_list **headA, t_list **headB, int size);

#endif