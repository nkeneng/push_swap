/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 11:45:59 by snkeneng          #+#    #+#             */
/*   Updated: 2024/09/27 17:13:55 by stevennke        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	throw_and_exit(char **args)
{
	free_args(args);
	write(2, "Error\n", 6);
	exit(0);
}

int	check_duplicates(char **av, int start)
{
	int	j;

	while (av[start])
	{
		j = start + 1;
		while (av[j])
		{
			if (ft_atoi(av[start]) == ft_atoi(av[j]))
				return (-1);
			j++;
		}
		start++;
	}
	return (1);
}

static int	check_string_array(char **av, int start)
{
	int		is_zeros;
	long	atoi_result;
	int		i;

	is_zeros = 0;
	i = start;
	if (!av[i])
		return (-1);
	while (av[i])
	{
		is_zeros = check_zeros(av[i]);
		atoi_result = ft_atol(av[i]);
		if ((!is_zeros && atoi_result == 0) || (atoi_result <= INT_MIN
				|| atoi_result >= INT_MAX))
			return (-1);
		else if (!is_zeros && !ft_isnumber(av[i]))
			return (-1);
		i++;
	}
	return (check_duplicates(av, start));
}

void	handle_args(int ac, char **av, t_node **a)
{
	char	**args;
	int		res;

	res = 0;
	if (ac == 2)
	{
		args = ft_split(av[1], ' ');
		if (!args)
			throw_and_exit(args);
		res = check_string_array(args, 0);
		if (res == -1)
			throw_and_exit(args);
		create_stack_a(args, a, ft_strslen(args), 0);
		free_args(args);
	}
	else
	{
		res = check_string_array(av, 1);
		if (res == -1)
			throw_and_exit(NULL);
		create_stack_a(av, a, ac, 1);
	}
}

int	main(int ac, char **av)
{
	t_node	*a;
	int		*sorted_list;
	int		res;

	a = NULL;
	if (ac < 2)
		throw_and_exit(NULL);
	handle_args(ac, av, &a);
	sorted_list = create_add_indexes(&a, len_of_stack(a));
	res = push_swap(&a, sorted_list);
	free_linked_list(&a);
	free(sorted_list);
	return (0);
}
