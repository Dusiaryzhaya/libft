// gcc *.c -o testfile

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void test_ft_lstnew(void) {
    write (1, "\n", 1);
    printf("Testing ft_lstnew function:\n");    
    write (1, "\n", 1);

    // Test 1: Creating a node with integer content
    printf("Test 1: Creating a node with integer content\n");
    int num1 = 10;
    t_list *node1 = ft_lstnew(&num1);

    // Expected Result: Node content should be a pointer to integer 10
    printf("Expected Result: Node content should be a pointer to integer 10\n");
    printf("Actual Result:   ");
    if (node1 && *(int *)(node1->content) == num1) {
        printf("Passed\n");
    } else {
        printf("Failed\n");
    }
    printf("\n");

    // Test 2: Creating a node with string content
    printf("Test 2: Creating a node with string content\n");
    char *str2 = "Hello, World!";
    t_list *node2 = ft_lstnew(str2);

    // Expected Result: Node content should be a pointer to string "Hello, World!"
    printf("Expected Result: Node content should be a pointer to string \"Hello, World!\"\n");
    printf("Actual Result:   ");
    if (node2 && strcmp((char *)node2->content, str2) == 0) {
        printf("Passed\n");
    } else {
        printf("Failed\n");
    }
    printf("\n");

    // Test 3: Creating a node with NULL content
    printf("Test 3: Creating a node with NULL content\n");
    void *ptr3 = NULL;
    t_list *node3 = ft_lstnew(ptr3);

    // Expected Result: Node content should be NULL
    printf("Expected Result: Node content should be NULL\n");
    printf("Actual Result:   ");
    if (node3 && node3->content == NULL) {
        printf("Passed\n");
    } else {
        printf("Failed\n");
    }
    printf("\n");

    // Test 4: Creating a node with custom structure content
    printf("Test 4: Creating a node with custom structure content\n");
    struct {
        int x;
        char *str;
    } custom_struct = {42, "Custom Data"};
    t_list *node4 = ft_lstnew(&custom_struct);

    // Expected Result: Node content should be a pointer to custom structure data
    printf("Expected Result: Node content should be a pointer to custom structure data\n");
    printf("Actual Result:   ");
    if (node4 && memcmp(node4->content, &custom_struct, sizeof(custom_struct)) == 0) {
        printf("Passed\n");
    } else {
        printf("Failed\n");
    }
    printf("\n");

    // Clean up allocated memory
    free(node1);
    free(node2);
    free(node3);
    free(node4);

    printf("Tests complete.\n\n");
    write (1, "\n", 1);
}

void test_ft_lstadd_front(void) {
    write (1, "\n", 1);
    printf("Testing ft_lstadd_front function:\n");
    write (1, "\n", 1);

    // Test 1: Adding to an empty list
    printf("Test 1: Adding to an empty list\n");
    t_list *list1 = NULL;
    int num1 = 10;
    t_list *node1 = ft_lstnew(&num1);
    ft_lstadd_front(&list1, node1);

    // Expected Result: List content should be the address of integer 10 -> NULL
    printf("Expected Result: List content should be the address of integer 10 -> NULL\n");
    printf("Actual Result:   ");
    if (list1 && list1->content == &num1 && list1->next == NULL) {
        printf("Passed\n");
    } else {
        printf("Failed\n");
    }
    printf("\n");

    // Test 2: Adding to a non-empty list
    printf("Test 2: Adding to a non-empty list\n");
    char *str2 = "Hello";
    t_list *node2 = ft_lstnew(str2);
    ft_lstadd_front(&list1, node2);

    // Expected Result: List content should be the address of string "Hello" -> address of integer 10 -> NULL
    printf("Expected Result: List content should be the address of string \"Hello\" -> address of integer 10 -> NULL\n");
    printf("Actual Result:   ");
    if (list1 && list1->content == str2 && list1->next->content == &num1) {
        printf("Passed\n");
    } else {
        printf("Failed\n");
    }
    printf("\n");

    // Test 3: Adding NULL node
    printf("Test 3: Adding NULL node\n");
    ft_lstadd_front(&list1, NULL);

    // Expected Result: List content should remain unchanged
    printf("Expected Result: List content should remain unchanged\n");
    printf("Actual Result:   ");
    if (list1 && list1->content == str2 && list1->next->content == &num1) {
        printf("Passed\n");
    } else {
        printf("Failed\n");
    }
    printf("\n");

    // Clean up allocated memory
    free(node1);
    free(node2);

    printf("Tests complete.\n\n");
    write (1, "\n", 1);
}

void test_ft_lstsize(void) {
    write (1, "\n", 1);
    printf("Testing ft_lstsize function:\n");
    write (1, "\n", 1);

    // Test 1: Counting elements in an empty list
    printf("Test 1: Counting elements in an empty list\n");
    t_list *list1 = NULL;
    int size1 = ft_lstsize(list1);

    // Expected Result: Size should be 0
    printf("Expected Result: Size should be 0\n");
    printf("Actual Result:   Size is %d\n", size1);
    if (size1 == 0) {
        printf("Passed\n\n");
    } else {
        printf("Failed\n\n");
    }

    // Test 2: Counting elements in a list with one node
    printf("Test 2: Counting elements in a list with one node\n");
    int num2 = 10;
    t_list *node2 = ft_lstnew(&num2);
    ft_lstadd_front(&list1, node2);
    int size2 = ft_lstsize(list1);

    // Expected Result: Size should be 1
    printf("Expected Result: Size should be 1\n");
    printf("Actual Result:   Size is %d\n", size2);
    if (size2 == 1) {
        printf("Passed\n");
    } else {
        printf("Failed\n");
    }
    printf("\n");

    // Test 3: Counting elements in a list with multiple nodes
    printf("Test 3: Counting elements in a list with multiple nodes\n");
    char *str3 = "Hello";
    t_list *node3 = ft_lstnew(str3);
    ft_lstadd_front(&list1, node3);
    int size3 = ft_lstsize(list1);

    // Expected Result: Size should be 2
    printf("Expected Result: Size should be 2\n");
    printf("Actual Result:   Size is %d\n", size3);
    if (size3 == 2) {
        printf("Passed\n");
    } else {
        printf("Failed\n");
    }
    printf("\n");

    // Test 4: Counting elements in a NULL list
    printf("Test 4: Counting elements in a NULL list\n");
    int size4 = ft_lstsize(NULL);

    // Expected Result: Size should be 0
    printf("Expected Result: Size should be 0\n");
    printf("Actual Result:   Size is %d\n", size4);
    if (size4 == 0) {
        printf("Passed\n");
    } else {
        printf("Failed\n");
    }
    write (1, "\n", 1);
}

void test_ft_lstlast(void) {
    write (1, "\n", 1);
    printf("Testing ft_lstlast function:\n");
    write (1, "\n", 1);

    // Test 1: Retrieving last node from an empty list
    printf("Test 1: Retrieving last node from an empty list\n");
    t_list *list1 = NULL;
    t_list *last1 = ft_lstlast(list1);

    // Expected Result: Last node should be NULL
    printf("Expected Result: Last node should be NULL\n");
    printf("Actual Result:   ");
    if (last1 == NULL) {
        printf("Passed\n\n");
    } else {
        printf("Failed\n\n");
    }

    // Test 2: Retrieving last node from a list with one node
    printf("Test 2: Retrieving last node from a list with one node\n");
    int num2 = 10;
    t_list *node2 = ft_lstnew(&num2);
    ft_lstadd_front(&list1, node2);
    t_list *last2 = ft_lstlast(list1);

    // Expected Result: Last node should be the node containing integer 10
    printf("Expected Result: Last node should be the node containing integer 10\n");
    printf("Actual Result:   ");
    if (last2 == node2) {
        printf("Passed\n");
    } else {
        printf("Failed\n");
    }
    printf("\n");

    // Test 3: Retrieving last node from a list with multiple nodes
    printf("Test 3: Retrieving last node from a list with multiple nodes\n");
    char *str3 = "Hello";
    t_list *node3 = ft_lstnew(str3);
    ft_lstadd_front(&list1, node3);
    t_list *last3 = ft_lstlast(list1);

    // Expected Result: Last node should be the node containing string "Hello"
    printf("Expected Result: Last node should be the node containing string \"Hello\"\n");
    printf("Actual Result:   ");
    if (last3 == node2) {
        printf("Passed\n");
    } else {
        printf("Failed\n");
    }
    printf("\n");

    // Test 4: Retrieving last node from a NULL list
    printf("Test 4: Retrieving last node from a NULL list\n");
    t_list *last4 = ft_lstlast(NULL);

    // Expected Result: Last node should be NULL
    printf("Expected Result: Last node should be NULL\n");
    printf("Actual Result:   ");
    if (last4 == NULL) {
        printf("Passed\n");
    } else {
        printf("Failed\n");
    }
    write (1, "\n", 1);
}

void test_ft_lstadd_back(void) {
    write (1, "\n", 1);
    printf("Testing ft_lstadd_back function:\n");
    write (1, "\n", 1);

    // Test 1: Adding to an empty list
    printf("Test 1: Adding to an empty list\n");
    t_list *list1 = NULL;
    int num1 = 10;
    t_list *node1 = ft_lstnew(&num1);
    ft_lstadd_back(&list1, node1);

    // Expected Result: List content should be the address of integer 10 -> NULL
    printf("Expected Result: List content should be the address of integer 10 -> NULL\n");
    printf("Actual Result:   ");
    if (list1 && list1->content == &num1 && list1->next == NULL) {
        printf("Passed\n");
    } else {
        printf("Failed\n");
    }
    printf("\n");

    // Test 2: Adding to a list with one node
    printf("Test 2: Adding to a list with one node\n");
    char *str2 = "Hello";
    t_list *node2 = ft_lstnew(str2);
    ft_lstadd_back(&list1, node2);

    // Expected Result: List content should be the address of integer 10 -> address of string "Hello" -> NULL
    printf("Expected Result: List content should be the address of integer 10 -> address of string \"Hello\" -> NULL\n");
    printf("Actual Result:   ");
    if (list1 && list1->content == &num1 && list1->next->content == str2 && list1->next->next == NULL) {
        printf("Passed\n");
    } else {
        printf("Failed\n");
    }
    printf("\n");

    // Test 3: Adding NULL node
    printf("Test 3: Adding NULL node\n");
    ft_lstadd_back(&list1, NULL);

    // Expected Result: List content should remain unchanged
    printf("Expected Result: List content should remain unchanged\n");
    printf("Actual Result:   ");
    if (list1 && list1->content == &num1 && list1->next->content == str2 && list1->next->next == NULL) {
        printf("Passed\n");
    } else {
        printf("Failed\n");
    }
    printf("\n");

    // Clean up allocated memory
    free(node1);
    free(node2);

    printf("Tests complete.\n\n");
    write (1, "\n", 1);
}


int main() {
    test_ft_lstnew();
    test_ft_lstadd_front();
    test_ft_lstsize();
    test_ft_lstlast();
    test_ft_lstadd_back();
    printf("sorry, but I don't have any more tests because they require\n"); 
    printf("extra function inside your .c file\n");
    write (1, "\n", 1);
    return 0;
}