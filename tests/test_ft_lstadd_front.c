#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../libft.h"

// Helper function to print the list (for testing purposes)
void print_list(t_list *lst)
{
    while (lst != NULL)
    {
        printf("Node content: %d\n", *(int *)lst->content);
        lst = lst->next;
    }
    printf("\n");
}

// Helper function to create a new node
t_list *ft_lstnew(void *content)
{
    t_list *new_node = (t_list *)malloc(sizeof(t_list));
    if (!new_node)
        return NULL;
    new_node->content = content;
    new_node->next = NULL;
    return new_node;
}

// Test case 1: Basic Test Case - Add a node to an empty list
void test_add_to_empty_list()
{
    printf("Test 1: Add to Empty List\n");
    t_list *head = NULL;  // Start with an empty list
    int data = 42;
    t_list *new_node = ft_lstnew(&data);
    
    ft_lstadd_front(&head, new_node);  // Add the new node to the front of the list
    
    print_list(head);  // Expected output: Node content: 42
    
    free(new_node);    // Clean up
}

// Test case 2: Add Multiple Nodes to the Front of the List
void test_add_multiple_nodes()
{
    printf("Test 2: Add Multiple Nodes\n");
    t_list *head = NULL;
    
    int data1 = 10;
    int data2 = 20;
    int data3 = 30;
    
    ft_lstadd_front(&head, ft_lstnew(&data1));
    ft_lstadd_front(&head, ft_lstnew(&data2));
    ft_lstadd_front(&head, ft_lstnew(&data3));
    
    print_list(head);  // Expected output: Node content: 30, 20, 10
    
    // Free the allocated nodes
    free(head->next->next);
    free(head->next);
    free(head);
}

// Test case 3: Add NULL Node - Should not affect the list
void test_add_null_node()
{
    printf("Test 3: Add NULL Node\n");
    t_list *head = NULL;
    int data = 42;
    t_list *new_node = ft_lstnew(&data);
    
    ft_lstadd_front(&head, new_node);  // Add the new node
    
    // Add NULL node, list should remain unchanged
    ft_lstadd_front(&head, NULL);
    
    print_list(head);  // Expected output: Node content: 42
    
    free(new_node);  // Clean up
}

int main()
{
    // Run all test cases
    test_add_to_empty_list();
    test_add_multiple_nodes();
    test_add_null_node();

    return 0;
}
