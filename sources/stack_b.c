/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flip_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:52:29 by snkeneng          #+#    #+#             */
/*   Updated: 2024/09/05 17:21:45 by stevennke        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

void	push_whole_chunk(t_node **stk_a, t_node **stk_b, int chunksz)
{
	int	i;

	i = 0;
	while (i < chunksz)
	{
		push(stk_a, stk_b, "pa");
		i++;
	}
	return ;
}

void	push_back_to_a(int mid, int size, t_node **stk_a, t_node **stk_b)
{
	int	i;
	int	reverse_count;

	i = 0;
	reverse_count = 0;
	while (i < size)
	{
		rotate_while_lower(stk_b, &reverse_count, "rb", mid);
		if ((*stk_b)->data > mid)
			push(stk_a, stk_b, "pa");
		i++;
	}
	rotate_back(stk_b, reverse_count, "rrb");
}

void	send_chunk_to_a(int mid, int chunksz, t_node **stk_a, t_node **stk_b)
{
	int	i;
	int	rotcount;

	i = -1;
	rotcount = 0;
	while (++i < chunksz)
	{
		if ((*stk_b)->data >= mid)
			push(stk_a, stk_b, "pa");
	}
	if (!is_sorted_ascending(*stk_a, 2))
		swap(*stk_a, "sa");
	rotate_back(stk_b, rotcount, "rrb");
	return ;
}

void	from_b_to_a(int *sorted_list, int chunksz, t_node **stk_a,
		t_node **stk_b)
{
	int	mid;
	int	restsz;

	mid = chunksz / 2;
	if (chunksz % 2 == 0)
		restsz = chunksz - mid + 1;
	else
		restsz = chunksz - mid;
	if (chunksz <= 2)
		return (send_chunk_to_a(sorted_list[0], chunksz, stk_a, stk_b));
	else if (is_sorted_descending(*stk_b, chunksz))
		return (push_whole_chunk(stk_a, stk_b, chunksz));
	push_back_to_a(sorted_list[mid], chunksz - mid - 1, stk_a, stk_b);
	from_a_to_b(&sorted_list[mid + 1], chunksz - mid - 1, stk_a, stk_b);
	from_b_to_a(sorted_list, restsz, stk_a, stk_b);
}
