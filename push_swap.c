/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 11:45:59 by snkeneng          #+#    #+#             */
/*   Updated: 2024/07/01 13:56:43 by snkeneng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_zeros(char *str)
{
	unsigned int		i;

	i = ft_strlen(str);
	if (!ft_isempty(str) && ft_strncmp(str, "0", i) == 0)
		return (1);
	return (0);
}

void	push_swap(t_node **a, int *sorted_list)
{
	t_node	*b;

	b = NULL;
	if (stack_is_sorted(*a))
	{
		free_linked_list(a);
		exit(0);
	}
	else if (find_len(*a) == 2)
		swap(*a, "sa");
	else if (find_len(*a) == 3)
		sort_three(a);
	else if (find_len(*a) > 3)
	{
		midpoint_sorting(a, &b, sorted_list);
		printf("OK\n");
	}
	return ;
}

int	main(int ac, char **av)
{
	int		i;
	int		is_zeros;
	t_node	*a;
	int			*sorted_list;

	i = 1;
	a = NULL;
	if (ac >= 2)
	{
		while (av[i])
		{
			is_zeros = check_zeros(av[i]);
			if (!is_zeros && ft_atoi(av[i]) == 0)
			{
				ft_printf("Error\n");
				return (0);
			}
			i++;
		}
		create_stack(av, &a, ac);
		sorted_list = add_sorting_index(&a, find_len(a));
		push_swap(&a, sorted_list);
		// print linked list
		print_linked_list(a);
		ft_printf("OK\n");
	}
	return (0);
}
