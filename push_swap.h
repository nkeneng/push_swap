/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 11:45:40 by snkeneng          #+#    #+#             */
/*   Updated: 2024/08/20 16:08:24 by snkeneng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/ft_printf/ft_printf.h"
# include "libft/get_next_line/get_next_line.h"
# include "libft/lib_ft/libft.h"
# include <stdio.h>

typedef struct t_list
{
	int				data;
	int				s_index;
	int				cost_a;
	int				cost_b;
	int				pos;
	struct t_list	*next;
}					t_node;

void				create_stack(char **av, t_node **stack, int ac);
int					stack_is_sorted(t_node *stack);
void				free_linked_list(t_node **stack);

void				swap(t_node *stack, char *str);
void				safe_free(char ***ptr);
t_node				*ft_lstlast_ps(t_node *lst);
void				sort_three(t_node **stack);
void				rotate(t_node **stack, char *str, int cost);
void				reverse_rotate(t_node **stack, char *str, int cost);
int					find_len(t_node *pList);
void				push(t_node **stack_1, t_node **stack_2, char *str);
void				midpoint_sorting(t_node **a, t_node **b, int *sorted_list);
int					*add_sorting_index(t_node **stack, int len);
int					count_divisions(int dividend, int divisor);
int					isrevunsorted(t_node *stk, int chunksz);
int					isunsorted(t_node *stk, int chunksz);
void				flip_b(int *arr_ind, int chunksz, t_node **stk_a,
						t_node **stk_b);
void				flip_a(int *arr_ind, int chunksz, t_node **stk_a,
						t_node **stk_b);
int					find_midpt(t_node *stack);
#endif
