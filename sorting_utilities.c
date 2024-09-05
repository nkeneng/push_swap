/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utilities.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stevennkeneng <snkeneng@student.42ber      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 17:47:11 by stevennke         #+#    #+#             */
/*   Updated: 2024/09/05 17:48:11 by stevennke        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_is_sorted(t_node *stack)
{
	t_node	*temp;

	temp = stack;
	while (temp->next)
	{
		if (temp->data > temp->next->data)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	is_sorted_ascending(t_node *stk, int chunksz)
{
	int	i;

	i = 0;
	while (stk && stk->next && i < (chunksz - 1))
	{
		if (stk->data >= stk->next->data)
			return (0);
		stk = stk->next;
		i++;
	}
	return (1);
}

int	is_sorted_descending(t_node *stk, int chunksz)
{
	int	i;

	i = 0;
	while (stk && stk->next && i < (chunksz - 1))
	{
		if (stk->data <= (stk)->next->data)
			return (0);
		stk = stk->next;
		i++;
	}
	return (1);
}
