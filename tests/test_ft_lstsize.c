#include <stdio.h>
#include <stdlib.h>
#include "../libft.h"

// Helper function to print the result
void print_test_result(int expected, int actual, const char *test_name)
{
    if (expected == actual)
        printf("%s: PASSED\n", test_name);
    else
        printf("%s: FAILED (Expected: %d, Actual: %d)\n", test_name, expected, actual);
}

// Test case 1: Empty list
void test_empty_list()
{
    t_list *empty_list = NULL;
    int size = ft_lstsize(empty_list);
    print_test_result(0, size, "Test Empty List");
}

// Test case 2: List with one element
void test_single_node()
{
    t_list *head = ft_lstnew("Only One Node");
    int size = ft_lstsize(head);
    print_test_result(1, size, "Test Single Node");

    // Free the allocated memory for the node
    free(head);
}

// Test case 3: List with multiple elements
void test_multiple_nodes()
{
    t_list *head = ft_lstnew("First Node");
    t_list *second = ft_lstnew("Second Node");
    t_list *third = ft_lstnew("Third Node");

    // Link the nodes together
    head->next = second;
    second->next = third;
    third->next = NULL;

    int size = ft_lstsize(head);
    print_test_result(3, size, "Test Multiple Nodes");

    // Free the allocated memory for the nodes
    free(head);
    free(second);
    free(third);
}

// Test case 4: List with various types of content (e.g., integers, strings)
void test_various_content()
{
    // Create nodes with different types of content
    int num = 42;
    t_list *num_node = ft_lstnew(&num);
    t_list *str_node = ft_lstnew("Hello World");
    
    // Link the nodes together
    num_node->next = str_node;
    str_node->next = NULL;

    int size = ft_lstsize(num_node);
    print_test_result(2, size, "Test Various Content");

    // Free the allocated memory for the nodes
    free(num_node);
    free(str_node);
}

// Test case 5: List with NULL content (to check behavior with NULL content pointers)
void test_null_content()
{
    t_list *null_content_node = ft_lstnew(NULL);
    null_content_node->next = NULL;

    int size = ft_lstsize(null_content_node);
    print_test_result(1, size, "Test NULL Content");

    // Free the allocated memory for the node
    free(null_content_node);
}

// Test case 6: Larger list
void test_large_list()
{
    t_list *head = ft_lstnew("Node 1");
    t_list *current = head;

    // Create a list of 100 nodes
    for (int i = 2; i <= 100; i++)
    {
        t_list *new_node = ft_lstnew("Node");
        current->next = new_node;
        current = new_node;
    }

    // Test list size
    int size = ft_lstsize(head);
    print_test_result(100, size, "Test Large List");

    // Free the allocated memory for the nodes
    current = head;
    while (current != NULL)
    {
        t_list *next = current->next;
        free(current);
        current = next;
    }
}

int main(void)
{
    // Run all test cases
    test_empty_list();
    test_single_node();
    test_multiple_nodes();
    test_various_content();
    test_null_content();
    test_large_list();

    return 0;
}
