/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:26:49 by snkeneng          #+#    #+#             */
/*   Updated: 2024/06/28 13:25:35 by snkeneng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node *stack, char *str)
{
	int	data_temp;
	int	index_temp;

	data_temp = stack->data;
	stack->data = stack->next->data;
	stack->next->data = data_temp;
	index_temp = stack->s_index;
	stack->s_index = stack->next->s_index;
	stack->next->s_index = index_temp;
	ft_printf(str, 1);
}

void	rotate(t_node **stack, char *str, int cost)
{
	t_node	*temp;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	while (cost)
	{
		temp = *stack;
		(*stack) = (*stack)->next;
		temp->next = NULL;
		ft_lstlast_ps(*stack)->next = temp;
		ft_printf(str, 1);
		cost--;
	}
}

void	reverse_rotate(t_node **stack, char *str, int cost)
{
	t_node	*temp;
	t_node	*last;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	last = ft_lstlast_ps(*stack);
	while (cost)
	{
		temp = *stack;
		while (temp->next != last)
			temp = temp->next;
		last->next = *stack;
		*stack = last;
		temp->next = NULL;
		last = temp;
		ft_printf(str, 1);
		cost++;
	}
}

/**
 * Pushes the top element of stack_2 to stack_1.
 *
 * @param stack_1 The stack to push to.
 * @param stack_2 The stack to push from.
 * @param str The operation string.
 */
void	push(t_node **stack_1, t_node **stack_2, char *str)
{
	t_node	*temp;

	if (!stack_1 || !stack_2 || !(*stack_2))
		return ;
	temp = *stack_2;
	*stack_2 = (*stack_2)->next;
	temp->next = *stack_1;
	*stack_1 = temp;
	if (ft_strncmp(str, "pa", 2) == 0)
		write(1, "pa\n", 3);
	else if (ft_strncmp(str, "pb", 2) == 0)
		write(1, "pb\n", 3);
}
