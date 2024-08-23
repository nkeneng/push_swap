#include "../push_swap.h"
#include <criterion/criterion.h>

// #include "/opt/homebrew/include/criterion/criterion.h"
// #include "/opt/homebrew/include/criterion/redirect.h"

Test(send_to_b, test_send_to_b_with_null_nodes)
{
	t_node	*a;
	t_node	*b;
	int		total_nodes_to_go;

	a = NULL;
	b = NULL;
	total_nodes_to_go = 5;
	send_to_b(&a, &b, total_nodes_to_go);
	cr_assert_null(a, "Node a should be NULL");
	cr_assert_null(b, "Node b should be NULL");
}

Test(send_to_b, test_send_to_b_with_some_nodes)
{
	t_node	*a;
	t_node	*b;
	char	*str[] = {"1", "2", "3", "4", "5"};

	// int		total_nodes_to_go;
	create_stack(str, &a, 5);
	// print_linked_list(a);
	//
	add_sorting_index(&a, find_len(a));
	// print_linked_list(a);
	b = NULL;
	// total_nodes_to_go = 2;
	// send_to_b(&a, &b, total_nodes_to_go);
	// print_linked_list(a);
	ft_printf("\n");
	cr_assert_not_null(a, "Node a should not be NULL");
	cr_assert_not_null(b, "Node b should not be NULL");
	cr_assert_eq(b->s_index, 1, "The first node in b should have s_index 1");
	cr_assert_eq(b->next->s_index, 2,
		"The second node in b should have s_index 2");
}

Test(send_to_b, test_send_to_b_with_no_nodes_to_go)
{
	t_node	*a;
	t_node	*b;
	int		total_nodes_to_go;

	create_stack((char *[]){"1", "2", "3"}, &a, 3);
	add_sorting_index(&a, find_len(a));
	b = NULL;
	total_nodes_to_go = 0;
	send_to_b(&a, &b, total_nodes_to_go);
	cr_assert_not_null(a, "Node a should not be NULL");
	cr_assert_null(b, "Node b should be NULL");
}
