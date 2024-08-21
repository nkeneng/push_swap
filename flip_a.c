/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flip_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:22:39 by snkeneng          #+#    #+#             */
/*   Updated: 2024/08/21 17:05:13 by stevennke        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	pb_belowmid(int *sorted_list, int howmny, t_node **stk_a, t_node **stk_b)
{
	int	i;
	int	rotcount;

	i = -1;
	rotcount = 0;
	while (++i < howmny)
	{
		while ((*stk_a)->data >= sorted_list[0])
		{
			rotcount++;
			rotate(stk_a, "ra", 1);
		}
		if ((*stk_a)->data < sorted_list[0])
			push(stk_b, stk_a, "pb");
	}
	while (rotcount-- > 0)
		reverse_rotate(stk_a, "ra", -1);
}

void	flip_a(int *sorted_list, int chunksz, t_node **stk_a, t_node **stk_b)
{
	int	mid;
	int	restsz;

	mid = chunksz / 2;
	restsz = chunksz - mid;
	if (chunksz <= 2)
	{
		if (isunsorted(*stk_a, 2))
			swap(*stk_a, "sa");
		return ;
	}
	if (!isunsorted(*stk_a, chunksz))
		return ;
	pb_belowmid(&sorted_list[mid], mid, stk_a, stk_b);
	flip_a(&sorted_list[mid], restsz, stk_a, stk_b);
	flip_b(sorted_list, mid, stk_a, stk_b);
}
