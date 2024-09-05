/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:18:18 by snkeneng          #+#    #+#             */
/*   Updated: 2024/09/01 12:06:03 by stevennke        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	len_of_stack(t_node *pList)
{
	int		len;
	t_node	*temp;

	len = 0;
	temp = pList;
	while (temp)
	{
		len++;
		temp = temp->next;
	}
	return (len);
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

void	rotate_while_lower(t_node **stk, int *rotcount, char *move, int mid)
{
	while ((*stk)->data <= mid)
	{
		*rotcount = *rotcount + 1;
		rotate(stk, move, 1);
	}
}

void	rotate_while_greater(t_node **stk, int *rotcount, char *move, int mid)
{
	while ((*stk)->data >= mid)
	{
		*rotcount = *rotcount + 1;
		rotate(stk, move, 1);
	}
}
