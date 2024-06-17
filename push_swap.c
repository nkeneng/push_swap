/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 11:45:59 by snkeneng          #+#    #+#             */
/*   Updated: 2024/06/17 20:57:19 by snkeneng         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	int		i;
	int		is_zeros;

	i = 1;
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
		ft_printf("OK\n");
	}
	return (0);
}
