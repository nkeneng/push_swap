/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   midpoint_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:05:56 by snkeneng          #+#    #+#             */
/*   Updated: 2024/09/05 17:21:02 by stevennke        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/**
 * midpoint seems to be the sum of all indexes divided by the number of elements
 */
int	midpoint_of(t_node *stack)
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

static void	push_to_b_and_decrement(t_node **a, t_node **b, int *i)
{
	push(b, a, "pb");
	(*i)--;
}

void	send_to_b(t_node **a, t_node **b, int nodes_total)
{
	int	midpoint;
	int	i;

	if (*a == NULL)
		return ;
	midpoint = midpoint_of(*a);
	i = (nodes_total / 2);
	while (i > 0)
	{
		if ((*a)->s_index < midpoint)
			push_to_b_and_decrement(a, b, &i);
		else if ((*a)->next->s_index < midpoint)
		{
			rotate(a, "ra", 1);
			push_to_b_and_decrement(a, b, &i);
		}
		else if ((ft_lstlast_ps(*a)->s_index < midpoint))
		{
			reverse_rotate(a, "rra", -1);
			push_to_b_and_decrement(a, b, &i);
		}
		else
			rotate(a, "ra", 1);
	}
}

void	midpoint_sorting(t_node **a, t_node **b, int *sorted_list)
{
	int	size;

	size = len_of_stack(*a);
	if (size <= 2)
	{
		if (!stack_is_sorted(*a))
			swap(*a, "sa");
		return ;
	}
	send_to_b(a, b, size);
	midpoint_sorting(a, b, &sorted_list[size / 2]);
	from_b_to_a(sorted_list, size / 2, a, b);
}
