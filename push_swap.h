/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snkeneng <snkeneng@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 11:45:40 by snkeneng          #+#    #+#             */
/*   Updated: 2024/09/09 17:47:57 by stevennke        ###   ########.fr       */
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
	struct t_list	*next;
}					t_node;

void				create_stack_a(char **av, t_node **stack, int ac,
						int first_index);
int					stack_is_sorted(t_node *stack);
void				free_linked_list(t_node **stack);

void				swap(t_node *stack, char *str);
t_node				*ft_lstlast_ps(t_node *lst);
void				sort_three(t_node **stack);
void				rotate(t_node **stack, char *str, int cost);
void				reverse_rotate(t_node **stack, char *str, int cost);
int					len_of_stack(t_node *pList);
void				push(t_node **stack_1, t_node **stack_2, char *str);
void				midpoint_sorting(t_node **a, t_node **b, int *sorted_list);
int					*create_add_indexes(t_node **stack, int len);
void				from_b_to_a(int *arr_ind, int chunksz, t_node **stk_a,
						t_node **stk_b);
void				from_a_to_b(int *arr_ind, int chunksz, t_node **stk_a,
						t_node **stk_b);
int					midpoint_of(t_node *stack);
void				send_to_b(t_node **a, t_node **b, int total_nodes_to_go);
void				print_linked_list(t_node *head);
void				push_swap(t_node **a, int *sorted_list);
int					check_zeros(char *str);
void				rotate_back(t_node **stk_b, int reverse_count, char *str);
void				rotate_while_lower(t_node **stk, int *rotcount, char *move,
						int mid);
void				rotate_while_greater(t_node **stk, int *rotcount,
						char *move, int mid);
int					is_sorted_descending(t_node *stk, int chunksz);
int					is_sorted_ascending(t_node *stk, int chunksz);
#endif
