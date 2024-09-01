#include "../push_swap.h"
#include <criterion/criterion.h>

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

	create_stack_a(str, &a, 5);
	create_add_indexes(&a, len_of_stack(a));
	b = NULL;
	//send_to_b(&a, &b, total_nodes_to_go);
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

	create_stack_a((char *[]){"1", "2", "3"}, &a, 3);
	create_add_indexes(&a, len_of_stack(a));
	b = NULL;
	total_nodes_to_go = 0;
	send_to_b(&a, &b, total_nodes_to_go);
	cr_assert_not_null(a, "Node a should not be NULL");
	cr_assert_null(b, "Node b should be NULL");
}
