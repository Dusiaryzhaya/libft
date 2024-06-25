
// gcc *.c -o testfile

#include <ctype.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include "libft.h" 

void test_strdup() {
    write(1, "\n", 1);
    printf("Testing strdup function:\n");
    write(1, "\n", 1);
    // Test Case 1: Basic string duplication
    const char *str1 = "Hello, world!";
    char *result1 = ft_strdup(str1);
    printf("Test Case 1:\n");
    printf("Original string: \"%s\"\n", str1);
    printf("Expected: \"%s\"\n", str1);
    printf("Result  : \"%s\"\n", result1);
    printf("Result  : %s\n\n", strcmp(result1, str1) == 0 ? "Pass" : "Fail");
    free(result1);

    // Test Case 2: Empty string duplication
    const char *str2 = "";
    char *result2 = ft_strdup(str2);
    printf("Test Case 2:\n");
    printf("Original string: \"\"\n");
    printf("Expected: \"\"\n");
    printf("Result  : \"%s\"\n", result2);
    printf("Result  : %s\n\n", strcmp(result2, "") == 0 ? "Pass" : "Fail");
    free(result2);

    // Test Case 3: Large string duplication
    const char *str3 = "This is a very large string. ";
    char *result3 = ft_strdup(str3);
    printf("Test Case 3:\n");
    printf("Original string: \"%s\"\n", str3);
    printf("Expected: \"%s\"\n", str3);
    printf("Result  : \"%s\"\n", result3);
    printf("Result  : %s\n\n", strcmp(result3, str3) == 0 ? "Pass" : "Fail");
    free(result3);

    // Test Case 4: NULL string
    const char *str4 = NULL;
    char *result4 = ft_strdup(str4);
    printf("Test Case 4:\n");
    printf("Original string: NULL\n");
    printf("Expected: NULL\n");
    printf("Result  : %p\n", (void *)result4);
    printf("Result  : %s\n\n", result4 == NULL ? "Pass" : "Fail");

    // Test Case 6: Memory allocation success with sufficient buffer
    char *result6 = ft_strdup("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
    printf("Test Case 6:\n");
    printf("Original string: Large string with sufficient memory\n");
    printf("Expected: \"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ\"\n");
    printf("Result  : \"%s\"\n", result6);
    printf("Result  : %s\n\n", strcmp(result6, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") == 0 ? "Pass" : "Fail");
    free(result6);
}

// Example function to print character and index
void print_char_index(unsigned int index, char *c) {
    printf("Character at index %u: '%c'\n", index, *c);
}

void test_striteri() {
    write(1, "\n", 1);
    printf("Testing striteri function:\n");
    write(1, "\n", 1);
    // Test case 1: Basic usage with printing characters and their indices
    char str1[] = "Hello";
    printf("Test Case 1:\n");
    printf("Original string: \"%s\"\n", str1);
    ft_striteri(str1, &print_char_index);
    printf("Expected: Characters at indexes 0 to 4 printed\n");
    printf("\n");

    // Test case 2: Empty string
    char str2[] = "";
    printf("Test Case 2:\n");
    printf("Original string: \"%s\"\n", str2);
    ft_striteri(str2, &print_char_index);
    printf("Expected: No characters printed\n");
    printf("\n");

    // Test case 3: NULL string (should handle gracefully)
    char *str3 = NULL;
    printf("Test Case 3:\n");
    printf("Original string: NULL\n");
    ft_striteri(str3, &print_char_index);
    printf("Expected: No characters printed\n");
    printf("\n");
}
void test_strjoin() {
    write(1, "\n", 1);
    printf("Testing strjoin function:\n");
    write(1, "\n", 1);
    // Test Case 1: Basic string combination
    const char *s1 = "Hello, ";
    const char *s2 = "world!";
    char *result1 = ft_strjoin(s1, s2);
    printf("Test Case 1:\n");
    printf("s1: \"%s\"\n", s1);
    printf("s2: \"%s\"\n", s2);
    printf("Expected: \"%s\"\n", "Hello, world!");
    printf("Result  : \"%s\"\n", result1);
    printf("Result  : %s\n\n", strcmp(result1, "Hello, world!") == 0 ? "Pass" : "Fail");
    free(result1);

    // Test Case 2: Combine empty string with non-empty string
    const char *s3 = "";
    const char *s4 = "Testing";
    char *result2 = ft_strjoin(s3, s4);
    printf("Test Case 2:\n");
    printf("s1: \"%s\"\n", s3);
    printf("s2: \"%s\"\n", s4);
    printf("Expected: \"%s\"\n", "Testing");
    printf("Result  : \"%s\"\n", result2);
    printf("Result  : %s\n\n", strcmp(result2, "Testing") == 0 ? "Pass" : "Fail");
    free(result2);

    // Test Case 3: Both strings are NULL
    const char *s5 = NULL;
    const char *s6 = NULL;
    char *result3 = ft_strjoin(s5, s6);
    printf("Test Case 3:\n");
    printf("s1: NULL\n");
    printf("s2: NULL\n");
    printf("Expected: NULL\n");
    printf("Result  : %p\n", (void *)result3);
    printf("Result  : %s\n\n", result3 == NULL ? "Pass" : "Fail");

    // Test Case 4: First string is NULL
    const char *s7 = NULL;
    const char *s8 = "Second";
    char *result4 = ft_strjoin(s7, s8);
    printf("Test Case 4:\n");
    printf("s1: NULL\n");
    printf("s2: \"%s\"\n", s8);
    printf("Expected: \"%s\"\n", "Second");
    printf("Result  : \"%s\"\n", result4);
    printf("Result  : %s\n\n", strcmp(result4, "Second") == 0 ? "Pass" : "Fail");
    free(result4);

    // Test Case 5: Second string is NULL
    const char *s9 = "First";
    const char *s10 = NULL;
    char *result5 = ft_strjoin(s9, s10);
    printf("Test Case 5:\n");
    printf("s1: \"%s\"\n", s9);
    printf("s2: NULL\n");
    printf("Expected: \"%s\"\n", "First");
    printf("Result  : \"%s\"\n", result5);
    printf("Result  : %s\n\n", strcmp(result5, "First") == 0 ? "Pass" : "Fail");
    free(result5);

    // Test Case 6: Empty strings
    const char *s11 = "";
    const char *s12 = "";
    char *result6 = ft_strjoin(s11, s12);
    printf("Test Case 6:\n");
    printf("s1: \"\"\n");
    printf("s2: \"\"\n");
    printf("Expected: \"\"\n");
    printf("Result  : \"%s\"\n", result6);
    printf("Result  : %s\n\n", strcmp(result6, "") == 0 ? "Pass" : "Fail");
    free(result6);

    // Test Case 7: Large strings
    const char *s13 = "This is a very large string ";
    const char *s14 = "with some more content added to it.";
    char *result7 = ft_strjoin(s13, s14);
    printf("Test Case 7:\n");
    printf("s1: \"%s\"\n", s13);
    printf("s2: \"%s\"\n", s14);
    printf("Expected: \"%s\"\n", "This is a very large string with some more content added to it.");
    printf("Result  : \"%s\"\n", result7);
    printf("Result  : %s\n\n", strcmp(result7, "This is a very large string with some more content added to it.") == 0 ? "Pass" : "Fail");
    free(result7);
}
void test_strlcat() {
    write(1, "\n", 1);
    printf("Testing strlcat function:\n");
    write(1, "\n", 1);
    // Test case 1: Basic concatenation within buffer size
    char dest1[20] = "Hello";
    const char *src1 = ", world!";
    size_t size1 = sizeof(dest1);
    size_t result1 = ft_strlcat(dest1, src1, size1);
    printf("Test Case 1:\n");
    printf("Destination: \"%s\"\n", dest1);
    printf("Source: \"%s\"\n", src1);
    printf("Buffer size: %zu\n", size1);
    printf("Result: %zu\n", result1);
    printf("Expected: Length of concatenated string (Hello, world!): %zu\n", strlen("Hello, world!"));
    printf("Concatenated string: \"%s\"\n", dest1);
    printf("Result: %s\n\n", result1 == strlen("Hello, world!") ? "Pass" : "Fail");

    // Test case 2: Empty source string
    char dest2[20] = "Hello";
    const char *src2 = "";
    size_t size2 = sizeof(dest2);
    size_t result2 = ft_strlcat(dest2, src2, size2);
    printf("Test Case 2:\n");
    printf("Destination: \"%s\"\n", dest2);
    printf("Source: \"\"\n");
    printf("Buffer size: %zu\n", size2);
    printf("Result: %zu\n", result2);
    printf("Expected: Length of destination string (Hello): %zu\n", strlen("Hello"));
    printf("Concatenated string: \"%s\"\n", dest2);
    printf("Result: %s\n\n", result2 == strlen("Hello") ? "Pass" : "Fail");

    // Test case 4: Buffer size just enough to fit concatenated string
    char dest4[6] = "Hello";
    const char *src4 = ", world!";
    size_t size4 = sizeof(dest4);
    size_t result4 = ft_strlcat(dest4, src4, size4);
    printf("Test Case 4:\n");
    printf("Destination: \"%s\"\n", dest4);
    printf("Source: \"%s\"\n", src4);
    printf("Buffer size: %zu\n", size4);
    printf("Result: %zu\n", result4);
    printf("Expected: Length of concatenated string (Hello, world!): %zu\n", strlen("Hello, world!"));
    printf("Concatenated string: \"%s\"\n", dest4);
    printf("Result: %s\n\n", result4 == strlen("Hello, world!") ? "Pass" : "Fail");

  // Test case 5: Buffer size smaller than destination string length
    char dest5[10] = "Hello";
    const char *src5 = ", world!";
    size_t size5 = 5;
    size_t result5 = ft_strlcat(dest5, src5, size5);
    printf("Test Case 5:\n");
    printf("Destination: \"%s\"\n", dest5);
    printf("Source: \"%s\"\n", src5);
    printf("Buffer size: %zu\n", size5);
    printf("Result: %zu\n", result5);
    printf("Expected: Length of concatenated string (Hello, world!): %zu\n", strlen("Hello, world!"));
    printf("Result: %s\n\n", result5 == strlen("Hello, world!") ? "Pass" : "Fail");

    // Test case 6: Large buffer size
    char dest6[50] = "Hello";
    const char *src6 = ", world!";
    size_t size6 = sizeof(dest6);
    size_t result6 = ft_strlcat(dest6, src6, size6);
    printf("Test Case 6:\n");
    printf("Destination: \"%s\"\n", dest6);
    printf("Source: \"%s\"\n", src6);
    printf("Buffer size: %zu\n", size6);
    printf("Result: %zu\n", result6);
    printf("Expected: Length of concatenated string (Hello, world!): %zu\n", strlen("Hello, world!"));
    printf("Concatenated string: \"%s\"\n", dest6);
    printf("Result: %s\n\n", result6 == strlen("Hello, world!") ? "Pass" : "Fail");
}

void test_strlcpy() {
    write(1, "\n", 1);
    printf("Testing strlcpy function:\n");
    write(1, "\n", 1);
    // Test Case 1: Basic string copy within buffer size
    char dest1[20];
    const char *src1 = "Hello, world!";
    size_t size1 = sizeof(dest1);
    size_t result1 = ft_strlcpy(dest1, src1, size1);
    printf("Test Case 1:\n");
    printf("Source: \"%s\"\n", src1);
    printf("Buffer size: %zu\n", size1);
    printf("Result: %zu\n", result1);
    printf("Expected: Length of source string (Hello, world!): %zu\n", strlen("Hello, world!"));
    printf("Copied string: \"%s\"\n", dest1);
    printf("Result: %s\n\n", result1 == strlen("Hello, world!") ? "Pass" : "Fail");

    // Test Case 2: NULL source string
    char dest2[20] = "Initial string";
    const char *src2 = NULL;
    size_t size2 = sizeof(dest2);
    size_t result2 = ft_strlcpy(dest2, src2, size2);
    printf("Test Case 2:\n");
    printf("Source: NULL\n");
    printf("Buffer size: %zu\n", size2);
    printf("Result: %zu\n", result2);
    printf("Expected: 0\n");
    printf("Copied string: \"%s\"\n", dest2);
    printf("Result: %s\n\n", result2 == 0 && strcmp(dest2, "") == 0 ? "Pass" : "Fail");

    // Test Case 4: Empty source string
    char dest4[20];
    const char *src4 = "";
    size_t size4 = sizeof(dest4);
    size_t result4 = ft_strlcpy(dest4, src4, size4);
    printf("Test Case 4:\n");
    printf("Source: \"\"\n");
    printf("Buffer size: %zu\n", size4);
    printf("Result: %zu\n", result4);
    printf("Expected: Length of source string (): %zu\n", strlen(""));
    printf("Copied string: \"%s\"\n", dest4);
    printf("Result: %s\n\n", result4 == strlen("") ? "Pass" : "Fail");

    // Test Case 5: Buffer size exactly matching source string length
    char dest5[14];
    const char *src5 = "Hello, world!";
    size_t size5 = sizeof(dest5);
    size_t result5 = ft_strlcpy(dest5, src5, size5);
    printf("Test Case 5:\n");
    printf("Source: \"%s\"\n", src5);
    printf("Buffer size: %zu\n", size5);
    printf("Result: %zu\n", result5);
    printf("Expected: Length of source string (Hello, world!): %zu\n", strlen("Hello, world!"));
    printf("Copied string: \"%s\"\n", dest5);
    printf("Result: %s\n\n", result5 == strlen("Hello, world!") ? "Pass" : "Fail");

    // Test Case 6: Buffer size 1 (edge case)
    char dest6[1];
    const char *src6 = "Hello, world!";
    size_t size6 = sizeof(dest6);
    size_t result6 = ft_strlcpy(dest6, src6, size6);
    printf("Test Case 6:\n");
    printf("Source: \"%s\"\n", src6);
    printf("Buffer size: %zu\n", size6);
    printf("Result: %zu\n", result6);
    printf("Expected: Length of source string (Hello, world!): %zu\n", strlen("Hello, world!"));
    printf("Copied string: \"%s\"\n", dest6);
    printf("Result: %s\n\n", result6 == strlen("Hello, world!") && strcmp(dest6, "") == 0 ? "Pass" : "Fail");
}
int	main(void)
{
	test_strdup();
	test_striteri();
	test_strjoin();
    test_strlcat();
	test_strlcpy();
	return (0);
}