
// gcc *.c -o testfile

#include <ctype.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include "libft.h" 

void test_strtrim() {
    printf("Testing ft_strtrim function:\n\n");

    // Test Case 1: Trim both sides
    const char *s1 = "   hello, world   ";
    const char *set1 = " ";
    char *result1 = ft_strtrim(s1, set1);
    printf("Test Case 1:Trim both sides\n");
    printf("String  : \"%s\"\n", s1);
    printf("Set     : \"%s\"\n", set1);
    printf("Expected: \"hello, world\"\n");
    printf("Actual  : \"%s\"\n", result1);
    printf("Result  : %s\n\n", (strcmp(result1, "hello, world") == 0) ? "Pass" : "Fail");
    free(result1);

    // Test Case 2: No trim required
    const char *s2 = "hello, world";
    const char *set2 = " ";
    char *result2 = ft_strtrim(s2, set2);
    printf("Test Case 2:No trim required\n");
    printf("String  : \"%s\"\n", s2);
    printf("Set     : \"%s\"\n", set2);
    printf("Expected: \"hello, world\"\n");
    printf("Actual  : \"%s\"\n", result2);
    printf("Result  : %s\n\n", (strcmp(result2, "hello, world") == 0) ? "Pass" : "Fail");
    free(result2);

    // Test Case 3: Trim one side
    const char *s3 = "   hello, world";
    const char *set3 = " ";
    char *result3 = ft_strtrim(s3, set3);
    printf("Test Case 3:Trim one side\n");
    printf("String  : \"%s\"\n", s3);
    printf("Set     : \"%s\"\n", set3);
    printf("Expected: \"hello, world\"\n");
    printf("Actual  : \"%s\"\n", result3);
    printf("Result  : %s\n\n", (strcmp(result3, "hello, world") == 0) ? "Pass" : "Fail");
    free(result3);

    // Test Case 4: Empty string
    const char *s4 = "";
    const char *set4 = " ";
    char *result4 = ft_strtrim(s4, set4);
    printf("Test Case 4:Empty string\n");
    printf("String  : \"%s\"\n", s4);
    printf("Set     : \"%s\"\n", set4);
    printf("Expected: \"\"\n");
    printf("Actual  : \"%s\"\n", result4);
    printf("Result  : %s\n\n", (strcmp(result4, "") == 0) ? "Pass" : "Fail");
    free(result4);

    // Test Case 5: All trim characters
    const char *s5 = "   ";
    const char *set5 = " ";
    char *result5 = ft_strtrim(s5, set5);
    printf("Test Case 5:All trim characters\n");
    printf("String  : \"%s\"\n", s5);
    printf("Set     : \"%s\"\n", set5);
    printf("Expected: \"\"\n");
    printf("Actual  : \"%s\"\n", result5);
    printf("Result  : %s\n\n", (strcmp(result5, "") == 0) ? "Pass" : "Fail");
    free(result5);

        // Test Case 6: NULL string
    const char *s6 = NULL;
    const char *set6 = " ";
    char *result6 = ft_strtrim(s6, set6);
    printf("Test Case 6:NULL string\n");
    printf("String  : NULL\n");
    printf("Set     : \"%s\"\n", set6);
    printf("Expected: NULL\n");
    printf("Actual  : \"%s\"\n", result6);
    printf("Result  : %s\n\n", (result6 == NULL) ? "Pass" : "Fail");
}

void test_substr() {
    printf("Testing ft_substr function:\n\n");

    // Test Case 1: Basic substring extraction
    const char *s1 = "Hello, world!";
    unsigned int start1 = 7;
    size_t len1 = 5;
    char *result1 = ft_substr(s1, start1, len1);
    printf("Test Case 1:Basic substring extraction\n");
    printf("String  : \"%s\"\n", s1);
    printf("Start   : %u\n", start1);
    printf("Length  : %zu\n", len1);
    printf("Expected: \"world\"\n");
    printf("Actual  : \"%s\"\n", result1);
    printf("Result  : %s\n\n", (strcmp(result1, "world") == 0) ? "Pass" : "Fail");
    free(result1);

    // Test Case 2: Substring from beginning
    const char *s2 = "Hello, world!";
    unsigned int start2 = 0;
    size_t len2 = 5;
    char *result2 = ft_substr(s2, start2, len2);
    printf("Test Case 2:Substring from beginning\n");
    printf("String  : \"%s\"\n", s2);
    printf("Start   : %u\n", start2);
    printf("Length  : %zu\n", len2);
    printf("Expected: \"Hello\"\n");
    printf("Actual  : \"%s\"\n", result2);
    printf("Result  : %s\n\n", (strcmp(result2, "Hello") == 0) ? "Pass" : "Fail");
    free(result2);

    // Test Case 3: Substring with length greater than remaining string
    const char *s3 = "Hello";
    unsigned int start3 = 2;
    size_t len3 = 10;
    char *result3 = ft_substr(s3, start3, len3);
    printf("Test Case 3:Substring with length greater than remaining string\n");
    printf("String  : \"%s\"\n", s3);
    printf("Start   : %u\n", start3);
    printf("Length  : %zu\n", len3);
    printf("Expected: \"llo\"\n");
    printf("Actual  : \"%s\"\n", result3);
    printf("Result  : %s\n\n", (strcmp(result3, "llo") == 0) ? "Pass" : "Fail");
    free(result3);

    // Test Case 4: Empty string
    const char *s4 = "";
    unsigned int start4 = 0;
    size_t len4 = 5;
    char *result4 = ft_substr(s4, start4, len4);
    printf("Test Case 4:Empty string\n");
    printf("String  : \"%s\"\n", s4);
    printf("Start   : %u\n", start4);
    printf("Length  : %zu\n", len4);
    printf("Expected: \"\"\n");
    printf("Actual  : \"%s\"\n", result4);
    printf("Result  : %s\n\n", (strcmp(result4, "") == 0) ? "Pass" : "Fail");
    free(result4);

        // Test Case 5: NULL string
    const char *s5 = NULL;
    unsigned int start5 = 0;
    size_t len5 = 5;
    char *result5 = ft_substr(s5, start5, len5);
    printf("Test Case 5:NULL string\n");
    printf("String  : NULL\n");
    printf("Start   : %u\n", start5);
    printf("Length  : %zu\n", len5);
    printf("Expected: NULL\n");
    printf("Actual  : \"%s\"\n", result5);
    printf("Result  : %s\n\n", (result5 == NULL) ? "Pass" : "Fail");
}

void test_tolower() {
    printf("Testing ft_tolower function:\n\n");

    // Test Case 1: Lowercase letter
    int c1 = 'A';
    int result1 = ft_tolower(c1);
    printf("Test Case 1:\n");
    printf("Character: '%c'\n", c1);
    printf("Expected: '%c'\n", 'a');
    printf("Actual  : '%c'\n", result1);
    printf("Result  : %s\n\n", (result1 == 'a') ? "Pass" : "Fail");

    // Test Case 2: Uppercase letter
    int c2 = 'z';
    int result2 = ft_tolower(c2);
    printf("Test Case 2:\n");
    printf("Character: '%c'\n", c2);
    printf("Expected: '%c'\n", 'z');
    printf("Actual  : '%c'\n", result2);
    printf("Result  : %s\n\n", (result2 == 'z') ? "Pass" : "Fail");

    // Test Case 3: Non-alphabetic character
    int c3 = '!';
    int result3 = ft_tolower(c3);
    printf("Test Case 3:\n");
    printf("Character: '%c'\n", c3);
    printf("Expected: '%c'\n", '!');
    printf("Actual  : '%c'\n", result3);
    printf("Result  : %s\n\n", (result3 == '!') ? "Pass" : "Fail");
}

// Test function for ft_toupper
void test_toupper() {
    printf("Testing ft_toupper function:\n\n");

    // Test Case 1: Lowercase letter
    int c1 = 'a';
    int result1 = ft_toupper(c1);
    printf("Test Case 1:\n");
    printf("Character: '%c'\n", c1);
    printf("Expected: '%c'\n", 'A');
    printf("Actual  : '%c'\n", result1);
    printf("Result  : %s\n\n", (result1 == 'A') ? "Pass" : "Fail");

    // Test Case 2: Uppercase letter
    int c2 = 'Z';
    int result2 = ft_toupper(c2);
    printf("Test Case 2:\n");
    printf("Character: '%c'\n", c2);
    printf("Expected: '%c'\n", 'Z');
    printf("Actual  : '%c'\n", result2);
    printf("Result  : %s\n\n", (result2 == 'Z') ? "Pass" : "Fail");

    // Test Case 3: Non-alphabetic character
    int c3 = '!';
    int result3 = ft_toupper(c3);
    printf("Test Case 3:\n");
    printf("Character: '%c'\n", c3);
    printf("Expected: '%c'\n", '!');
    printf("Actual  : '%c'\n", result3);
    printf("Result  : %s\n\n", (result3 == '!') ? "Pass" : "Fail");
}

int main()
{
    test_strtrim();
    test_substr();
    test_tolower();
    test_toupper();
    return 0;
}