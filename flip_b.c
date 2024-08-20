/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flip_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:52:29 by snkeneng          #+#    #+#             */
/*   Updated: 2024/08/20 16:17:58 by snkeneng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	pa_abovemid(int *sorted_list, int howmny, t_node **stk_a, t_node **stk_b)
{
	int	i;
	int	rotcount;

	i = -1;
	rotcount = 0;
	while (++i < howmny)
	{
		while ((*stk_b)->data <= sorted_list[0])
		{
			rotcount++;
			rotate(stk_b, "rb", 1);
		}
		if ((*stk_b)->data > sorted_list[0])
			push(stk_a, stk_b, "pa");
	}
	while (rotcount-- > 0)
		reverse_rotate(stk_b, "rb", -1);
}

void	flip_b_base(int *sorted_list, int chunksz, t_node **stk_a, t_node **stk_b)
{
	int	i;
	int	rotcount;

	i = -1;
	rotcount = 0;
	while (++i < chunksz)
	{
		while ((*stk_b)->data < sorted_list[0])
		{
			rotcount++;
			rotate(stk_b, "rb", 1);
		}
		if ((*stk_b)->data >= sorted_list[0])
			push(stk_a, stk_b, "pa");
	}
	while (rotcount-- > 0)
		reverse_rotate(stk_b, "rb", 1);
	if (isunsorted(*stk_a, 2))
		swap(*stk_a, "sa");
	return ;
}

void	flip_b(int *sorted_list, int chunksz, t_node **stk_a, t_node **stk_b)
{
	int	mid;
	int	restsz;
	int	i;

	mid = chunksz / 2;
	i = -1;
	if (chunksz % 2 == 0)
		restsz = chunksz - mid + 1;
	else
		restsz = chunksz - mid;
	if (chunksz <= 2)
	{
		flip_b_base(sorted_list, chunksz, stk_a, stk_b);
		return ;
	}
	else if (!isrevunsorted(*stk_b, chunksz))
	{
		while (++i < chunksz)
			push(stk_a, stk_b, "pa");
		return ;
	}
	pa_abovemid(&sorted_list[mid], chunksz - mid - 1, stk_a, stk_b);
	flip_a(&sorted_list[mid + 1], chunksz - mid - 1, stk_a, stk_b);
	flip_b(sorted_list, restsz, stk_a, stk_b);
}
