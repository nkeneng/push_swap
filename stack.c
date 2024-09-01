/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:10:44 by snkeneng          #+#    #+#             */
/*   Updated: 2024/08/21 15:31:00 by stevennke        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	return_error(void)
{
	ft_printf("Error\n");
	exit(0);
}

/**
 * Ft list add front push swap
 */
void	ft_lstadd_front_ps(t_node **lst, t_node *new)
{
	t_node	*tmp;

	if (lst && new)
	{
		tmp = *lst;
		*lst = new;
		new->next = tmp;
	}
}

t_node	*ft_lstlast_ps(t_node *lst)
{
	t_node	*last;

	last = lst;
	if (last)
	{
		while (last->next)
			last = last->next;
	}
	return (last);
}

void	create_stack_a(char **av, t_node **stack, int ac)
{
	t_node	*a;
	long	value;
	int		i;

	i = ac - 1;
	while (i >= 1)
	{
		value = ft_atoi(av[i]);
		a = malloc(sizeof(t_node));
		a->data = (int)value;
		a->next = NULL;
		if (*stack == NULL)
			(*stack) = a;
		else
			ft_lstadd_front_ps(stack, a);
		i--;
	}
}
