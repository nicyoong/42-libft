#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../libft.h"

// Function to print the content of each node
void print_content(void *content)
{
    if (content != NULL)
        printf("%s\n", (char *)content);
}

// Function to test ft_lstiter
void test_ft_lstiter()
{
    // Create nodes with string content
    t_list *node1 = ft_lstnew(strdup("Node 1"));
    t_list *node2 = ft_lstnew(strdup("Node 2"));
    t_list *node3 = ft_lstnew(strdup("Node 3"));
    
    // Link the nodes
    node1->next = node2;
    node2->next = node3;
    
    // Apply ft_lstiter to print the content of each node
    printf("List contents:\n");
    ft_lstiter(node1, print_content);
    
    // Free the allocated memory
    free(node1->content);
    free(node2->content);
    free(node3->content);
    free(node1);
    free(node2);
    free(node3);
}

int main()
{
    test_ft_lstiter();
    return 0;
}
