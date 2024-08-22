/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change-name.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stevennkeneng <snkeneng@student.42ber      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:02:28 by stevennke         #+#    #+#             */
/*   Updated: 2024/08/22 16:40:10 by stevennke        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_zeros(char *str)
{
	unsigned int	i;

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
		midpoint_sorting(a, &b, sorted_list);
	return ;
}

void	print_linked_list(t_node *head)
{
	t_node	*current;
	FILE	*file;

	file = fopen("output.txt", "w");
	if (file == NULL)
	{
		printf("Error opening file!\n");
		return ;
	}
	current = head;
	while (current != NULL)
	{
		// fprintf(file, "%d -> %d\n", current->s_index, current->data);
		printf("%d", current->data);
		current = current->next;
	}
	fclose(file);
}
