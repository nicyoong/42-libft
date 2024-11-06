#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../libft.h"

// Helper function to print integer content of a node
void print_int_node(t_list *node)
{
    if (node && node->content)
        printf("Node content: %d\n", *(int *)node->content);
    else
        printf("Node is NULL or has no content.\n");
}

// Helper function to print string content of a node
void print_string_node(t_list *node)
{
    if (node && node->content)
        printf("Node content: %s\n", (char *)node->content);
    else
        printf("Node is NULL or has no content.\n");
}

// Test case 1: Basic Test Case
void test_basic_case()
{
    printf("Test 1: Basic Case\n");
    int data = 42;
    t_list *node = ft_lstnew(&data);
    
    if (node != NULL)
    {
        print_int_node(node);  // Should print: Node content: 42
        printf("Next pointer: %p\n", node->next);  // Should print: Next pointer: (nil)
    }
    else
    {
        printf("Memory allocation failed!\n");
    }
    free(node);
}

// Test case 2: Null Content
void test_null_content()
{
    printf("Test 2: Null Content\n");
    t_list *node = ft_lstnew(NULL);
    
    if (node != NULL)
    {
        if (node->content == NULL)
            printf("Content is NULL as expected.\n");
        else
            printf("Unexpected content!\n");
        printf("Next pointer: %p\n", node->next);  // Should print: Next pointer: (nil)
    }
    else
    {
        printf("Memory allocation failed!\n");
    }
    free(node);
}

// Test case 4: Content Type Flexibility
void test_different_content_types()
{
    printf("Test 4: Content Type Flexibility\n");

    // Test with an integer
    int num = 100;
    t_list *int_node = ft_lstnew(&num);
    print_int_node(int_node);  // Should print: Node content: 100
    free(int_node);
    
    // Test with a string
    char *str = "Hello, World!";
    t_list *str_node = ft_lstnew(str);
    print_string_node(str_node);  // Should print: Node content: Hello, World!
    free(str_node);
    
    // Test with a struct (arbitrary example)
    struct Person
    {
        char name[20];
        int age;
    };
    
    struct Person person = {"Alice", 30};
    t_list *person_node = ft_lstnew(&person);
    if (person_node && person_node->content)
    {
        struct Person *p = (struct Person *)person_node->content;
        printf("Node content: Name: %s, Age: %d\n", p->name, p->age);
    }
    free(person_node);
}

// Test case 5: Check Next Pointer
void test_next_pointer()
{
    printf("Test 5: Check Next Pointer\n");
    int data1 = 10;
    int data2 = 20;
    
    // Create two nodes and link them
    t_list *node1 = ft_lstnew(&data1);
    t_list *node2 = ft_lstnew(&data2);
    
    node1->next = node2;  // Link node1 to node2
    
    // Verify that the next pointer works correctly
    if (node1->next == node2)
        printf("Next pointer correctly points to the next node.\n");
    
    printf("Node 1 content: %d, Node 2 content: %d\n", *(int *)node1->content, *(int *)node2->content);
    
    // Clean up memory
    free(node1);
    free(node2);
}

int main()
{
    // Run all tests
    test_basic_case();
    test_null_content();
    test_different_content_types();
    test_next_pointer();

    return 0;
}
