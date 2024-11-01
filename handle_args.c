/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloiki <aloiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:47:26 by aloiki            #+#    #+#             */
/*   Updated: 2024/11/01 15:48:34 by aloiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**handle_one_arg(char *arg)
{
	char	**array;

	array = ft_split(arg, ' ');
	if (!array)
	{
		ft_printerror("memory problems");
	}
	return (array);
}

char	**handle_several_args(char *argv[])
{
	return (argv + 1);
}

char	**handle_args(int argc, char *argv[])
{
	if (argc == 1)
		exit(0);
	else if (argc == 2)
		return (handle_one_arg(argv[1]));
	else
		return (handle_several_args(argv));
}
