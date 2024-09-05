/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:03:01 by snkeneng          #+#    #+#             */
/*   Updated: 2024/09/05 17:47:34 by stevennke        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort(t_node **stack, t_node *b, t_node *c)
{
	if (((*stack)->s_index < b->s_index) && (b->s_index < c->s_index))
		return ;
	else if (((*stack)->s_index < b->s_index)
		&& ((*stack)->s_index < c->s_index))
	{
		swap(*stack, "sa");
		rotate(stack, "ra", 1);
	}
	else if (((*stack)->s_index > b->s_index)
		&& ((*stack)->s_index < c->s_index) && (b->s_index < c->s_index))
		swap(*stack, "sa");
	else if (((*stack)->s_index < b->s_index)
		&& ((*stack)->s_index > c->s_index))
		reverse_rotate(stack, "rra", -1);
	else if (((*stack)->s_index > b->s_index)
		&& ((*stack)->s_index > c->s_index) && (b->s_index < c->s_index))
		rotate(stack, "ra", 1);
	else if (((*stack)->s_index > b->s_index)
		&& ((*stack)->s_index > c->s_index) && (b->s_index > c->s_index))
	{
		swap(*stack, "sa");
		reverse_rotate(stack, "rra", -1);
	}
}

void	sort_three(t_node **stack)
{
	t_node	*b;
	t_node	*c;

	b = (*stack)->next;
	c = b->next;
	sort(stack, b, c);
}

void	assign_index(int len, t_node **stack, int *sorted_list)
{
	int		i;
	t_node	*temp;

	temp = *stack;
	while (temp)
	{
		i = 0;
		while (i < len)
		{
			if (temp->data == sorted_list[i])
			{
				temp->s_index = i;
				break ;
			}
			i++;
		}
		temp = temp->next;
	}
}

void	sort_int_array(int **arr, int len)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if ((*arr)[i] > (*arr)[j])
			{
				temp = (*arr)[i];
				(*arr)[i] = (*arr)[j];
				(*arr)[j] = temp;
			}
			j++;
		}
		i++;
	}
}

int	*create_add_indexes(t_node **stack, int len)
{
	t_node	*temp;
	int		i;
	int		*sorted_list;

	temp = *stack;
	sorted_list = malloc(sizeof(int) * len);
	if (!sorted_list)
		return (NULL);
	i = 0;
	while (temp)
	{
		sorted_list[i++] = temp->data;
		temp = temp->next;
	}
	sort_int_array(&sorted_list, len);
	temp = *stack;
	assign_index(len, &temp, sorted_list);
	*stack = temp;
	return (sorted_list);
}
