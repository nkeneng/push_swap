/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   midpoint_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:05:56 by snkeneng          #+#    #+#             */
/*   Updated: 2024/08/20 16:21:56 by snkeneng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	find_midpt(t_node *stack)
{
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	while (stack)
	{
		sum += stack->s_index;
		i++;
		stack = stack->next;
	}
	if (sum % i == 0)
		return (sum / i);
	else
		return ((sum / i) + 1);
}

void	push_to_b(t_node **a, t_node **b, int *i)
{
	push(b, a, "pb");
	(*i)--;
}

void	send_to_b(t_node **a, t_node **b, int total_nodes_to_go)
{
	int	mid_pt;
	int	i;

	mid_pt = find_midpt(*a);
	i = (total_nodes_to_go / 2);
	while (i > 0)
	{
		if ((*a)->s_index < mid_pt)
			push_to_b(a, b, &i);
		else if ((*a)->next->s_index < mid_pt)
		{
			rotate(a, "ra", 1);
			push_to_b(a, b, &i);
		}
		else if ((ft_lstlast_ps(*a)->s_index < mid_pt))
		{
			reverse_rotate(a, "rra", -1);
			push_to_b(a, b, &i);
		}
		else
			rotate(a, "ra", 1);
	}
}

void	midpoint_sorting(t_node **a, t_node **b, int *sorted_list)
{
	int	size;

	size = find_len(*a);
	if (size <= 2)
	{
		if (!stack_is_sorted(*a))
			swap(*a, "sa"); // sort two last elements in a
		return ;
	}
	send_to_b(a, b, size);
	midpoint_sorting(a, b, &sorted_list[size / 2]);
	flip_b(sorted_list, size / 2, a, b);
}
