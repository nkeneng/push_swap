/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:18:18 by snkeneng          #+#    #+#             */
/*   Updated: 2024/09/27 17:13:33 by stevennke        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	free_linked_list(t_node **stack)
{
	t_node	*temp;

	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}

void	free_args(char **av)
{
	int	i;

	i = 0;
	while (av && av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}
