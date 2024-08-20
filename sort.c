/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:03:01 by snkeneng          #+#    #+#             */
/*   Updated: 2024/06/19 16:03:04 by snkeneng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_node **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->s_index;
	second = (*stack)->next->s_index;
	third = (*stack)->next->next->s_index;
	if ((first < second) && (second < third))
		return ;
	else if ((first < second) && (first < third)) // 1 3 2
	{
		swap(*stack, "sa"); // 3 1 2
		rotate(stack, "ra", 1); // 1 2 3
	}
	else if ((first > second) && (first < third) && (second < third)) // 2 1 3
		swap(*stack, "sa"); // 1 2 3
	else if ((first < second) && (first > third)) // 2 3 1
		reverse_rotate(stack, "rra", -1);
	else if ((first > second) && (first > third) && (second < third)) // 3 1 2
		rotate(stack, "ra", 1);
	else if ((first > second) && (first > third) && (second > third)) // 3 2 1
	{
		swap(*stack, "sa"); // 2 3 1
		reverse_rotate(stack, "rra", -1);
	}
}

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

int	*add_sorting_index(t_node **stack, int len)
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
