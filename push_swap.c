/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 11:45:59 by snkeneng          #+#    #+#             */
/*   Updated: 2024/08/22 15:03:42 by stevennke        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int		i;
	int		is_zeros;
	t_node	*a;
	int		*sorted_list;

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
		create_stack_a(av, &a, ac);
		sorted_list = create_add_indexes(&a, len_of_stack(a));
		push_swap(&a, sorted_list);
	}
	return (0);
}
