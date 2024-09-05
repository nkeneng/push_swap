/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flip_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:22:39 by snkeneng          #+#    #+#             */
/*   Updated: 2024/09/01 11:59:58 by stevennke        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	push_to_b(int mid, int size, t_node **stk_a, t_node **stk_b)
{
	int	i;
	int	rotcount;

	i = 0;
	rotcount = 0;
	while (i < size)
	{
		rotate_while_greater(stk_a, &rotcount, "ra", mid);
		if ((*stk_a)->data < mid)
			push(stk_b, stk_a, "pb");
		i++;
	}
	rotate_back(stk_a, rotcount, "rra");
}

void	flip_a(int *sorted_list, int chunksz, t_node **stk_a, t_node **stk_b)
{
	int	mid;
	int	restsz;

	mid = chunksz / 2;
	restsz = chunksz - mid;
	if (chunksz <= 2)
	{
		if (!is_sorted_ascending(*stk_a, 2))
			swap(*stk_a, "sa");
		return ;
	}
	if (is_sorted_ascending(*stk_a, chunksz))
		return ;
	push_to_b(sorted_list[mid], mid, stk_a, stk_b);
	flip_a(&sorted_list[mid], restsz, stk_a, stk_b);
	flip_b(sorted_list, mid, stk_a, stk_b);
}
