#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../libft.h"

// Helper function to print list
void print_list(t_list *lst)
{
    while (lst != NULL)
    {
        printf("%s -> ", (char *)lst->content);
        lst = lst->next;
    }
    printf("NULL\n");
}

// Helper function to check test results
void print_test_result(t_list *expected_last_node, t_list *actual_last_node, const char *test_name)
{
    if (expected_last_node == actual_last_node)
        printf("%s: PASSED\n", test_name);
    else
        printf("%s: FAILED (Expected last node: %p, Actual last node: %p)\n", test_name, (void *)expected_last_node, (void *)actual_last_node);
}

// Test 1: Add a node to an empty list
void test_empty_list()
{
    t_list *empty_list = NULL;
    t_list *new_node = ft_lstnew("First Node");

    ft_lstadd_back(&empty_list, new_node);
    print_test_result(new_node, empty_list, "Test Empty List");

    // Free allocated memory
    free(new_node);
}

// Test 2: Add a node to a list with one node
void test_single_node()
{
    t_list *head = ft_lstnew("Only Node");
    t_list *new_node = ft_lstnew("Second Node");

    ft_lstadd_back(&head, new_node);
    print_test_result(new_node, head->next, "Test Single Node");

    // Free allocated memory
    free(head);
    free(new_node);
}

// Test 3: Add a node to a list with multiple nodes
void test_multiple_nodes()
{
    t_list *head = ft_lstnew("First Node");
    t_list *second = ft_lstnew("Second Node");
    t_list *third = ft_lstnew("Third Node");

    // Link the nodes together
    head->next = second;
    second->next = third;
    third->next = NULL;

    // Add a new node at the end
    t_list *new_node = ft_lstnew("Fourth Node");
    ft_lstadd_back(&head, new_node);

    // Check if the last node is the new node
    print_test_result(new_node, third->next, "Test Multiple Nodes");

    // Free allocated memory
    free(head);
    free(second);
    free(third);
    free(new_node);
}

// Test 4: Add a node to a list with NULL content
void test_null_content()
{
    t_list *head = ft_lstnew(NULL);
    t_list *new_node = ft_lstnew("New Node");

    ft_lstadd_back(&head, new_node);
    print_test_result(new_node, head->next, "Test NULL Content");

    // Free allocated memory
    free(head);
    free(new_node);
}

// Test 5: Add multiple nodes to an empty list and check the order
void test_multiple_additions()
{
    t_list *head = NULL;
    t_list *node1 = ft_lstnew("Node 1");
    t_list *node2 = ft_lstnew("Node 2");
    t_list *node3 = ft_lstnew("Node 3");

    ft_lstadd_back(&head, node1);
    ft_lstadd_back(&head, node2);
    ft_lstadd_back(&head, node3);

    // Expected order: "Node 1" -> "Node 2" -> "Node 3"
    print_list(head); // Print the entire list to verify the order
    print_test_result(node3, node2->next, "Test Multiple Additions");

    // Free allocated memory
    free(node1);
    free(node2);
    free(node3);
}

// Test 6: Add node with empty content
void test_empty_node_content()
{
    t_list *head = ft_lstnew("");
    t_list *new_node = ft_lstnew("Non-empty Node");

    ft_lstadd_back(&head, new_node);
    print_test_result(new_node, head->next, "Test Empty Node Content");

    // Free allocated memory
    free(head);
    free(new_node);
}

// Test 7: Add nodes and check if the last node's content matches
void test_last_node_content()
{
    t_list *head = ft_lstnew("First Node");
    t_list *new_node = ft_lstnew("Last Node");

    ft_lstadd_back(&head, new_node);
    print_test_result(new_node, head->next, "Test Last Node Content");

    // Free allocated memory
    free(head);
    free(new_node);
}

int main(void)
{
    // Run all test cases
    test_empty_list();
    test_single_node();
    test_multiple_nodes();
    test_null_content();
    test_multiple_additions();
    test_empty_node_content();
    test_last_node_content();

    return 0;
}
