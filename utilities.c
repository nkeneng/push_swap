/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:18:18 by snkeneng          #+#    #+#             */
/*   Updated: 2024/06/28 15:25:12 by snkeneng         ###   ########.fr       */
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

int	isunsorted(t_node *stk, int chunksz)
{
	int	i;

	i = -1;
	while (stk && stk->next && ++i < (chunksz - 1))
	{
		if (stk->data >= stk->next->data)
			return (1);
		stk = stk->next;
	}
	return (0);
}

int	isrevunsorted(t_node *stk, int chunksz)
{
	int	i;

	i = -1;
	while (stk && stk->next && ++i < (chunksz - 1))
	{
		if (stk->data <= (stk)->next->data)
			return (1);
		stk = stk->next;
	}
	return (0);
}
