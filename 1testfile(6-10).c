
// gcc *.c -o testfile

#include "libft.h"
#include <ctype.h>
#include <stdio.h>

void test_isascii(void) 
{
    write(1, "\n", 1);
    printf("Testing isascii function:\n");
    write(1, "\n", 1);

    printf("isascii('A'): %d (expected 1)\n", ft_isascii('A')); // 1
    printf("isascii(' '): %d (expected 1)\n", ft_isascii(' ')); // 1
    printf("isascii(0): %d (expected 1)\n", ft_isascii(0));     // 1
    printf("isascii(127): %d (expected 1)\n", ft_isascii(127)); // 1
    printf("isascii(-1): %d (expected 0)\n", ft_isascii(-1));   // 0
    printf("isascii(128): %d (expected 0)\n", ft_isascii(128)); // 0
    write(1, "\n", 1);

    printf("Edge cases:\n");
    printf("isascii(EOF): %d (expected 0)\n", ft_isascii(EOF)); // 0
    printf("isascii(0): %d (expected 1)\n", ft_isascii(0));     // 1
    write(1, "\n", 1);
}

void	test_isdigit(void)
{
	write(1, "\n", 1);
	printf("Testing isdigit function:\n");
	// Test digits '0' to '9'
	for (char ch = '0'; ch <= '9'; ++ch)
	{
		if (ft_isdigit(ch))
		{
			printf("%c is a digit.\n", ch);
		}
		else
		{
			printf("%c is not a digit.\n", ch);
		}
	}
	// Test non-digits
	char	non_digits[] = {'a', 'A', '!', ' ', '\0'};
	for (int i = 0; i < sizeof(non_digits) / sizeof(non_digits[0]); ++i)
	{
		if (ft_isdigit(non_digits[i]))
		{
			printf("%c is a digit (unexpected).\n", non_digits[i]);
		}
		else
		{
			printf("%c is not a digit.\n", non_digits[i]);
		}
	}
    write(1, "\n", 1);
}

void test_isprint(void) {

    write(1, "\n", 1);
    printf("Testing isprint function:\n");
    write(1, "\n", 1);

    printf("isprint('A'): %d (expected 1)\n", ft_isprint('A')); // 1
    printf("isprint(' '): %d (expected 1)\n", ft_isprint(' ')); // 1
    printf("isprint('~'): %d (expected 1)\n", ft_isprint('~')); // 1
    printf("isprint('\\t'): %d (expected 0)\n", ft_isprint('\t')); // 0
    printf("isprint(126): %d (expected 1)\n", ft_isprint(126)); // 1
    printf("isprint(127): %d (expected 0)\n", ft_isprint(127)); // 0
    write(1, "\n", 1);

    printf("Edge cases:\n");
    printf("isprint(EOF): %d (expected 0)\n", ft_isprint(EOF)); // 0
    printf("isprint(0): %d (expected 0)\n", ft_isprint(0));     // 0
    write(1, "\n", 1);
}

void test_itoa(void) {
    printf("Testing itoa function:\n");
    write(1, "\n", 1);

    // Test cases
    struct TestCase {
        int value;
        const char *expected_result;
    };

    struct TestCase test_cases[] = {
        {123, "123"},
        {-123, "-123"},
        {0, "0"},
        {2147483647, "2147483647"},   // INT_MAX
        {-2147483648, "-2147483648"}, // INT_MIN
        {987654321, "987654321"},
        {-987654321, "-987654321"},
    };

    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

    for (int i = 0; i < num_tests; ++i) {
        struct TestCase *tc = &test_cases[i];

        // Allocate memory for the result string
        char *result = ft_itoa(tc->value);

        // Compare result with expected result
        printf("Test %d:\n", i + 1);
        printf("Expected: %s\n", tc->expected_result);
        printf("Result:   %s\n", result);

        if (strcmp(result, tc->expected_result) == 0) {
            printf("Test Passed\n\n");
        } else {
            printf("Test Failed\n\n");
        }
        free(result);
    }
}


void test_memchr(void) {
    printf("Testing memchr function:\n\n");

    const char *str1 = "Hello!0";
    const char str2[] = {1, 2, 3, 4, 5};
    const char str3[] = {0, 0, 0, 0, 0};
    const char *str4 = NULL;

    // Test 1: Search for '0' in str1 with size 20
    printf("Test 1:\n");
    const char *res1 = ft_memchr(str1, '0', 20);
    printf("Expected Result: Pointer to '0' in \"%s\"\n", str1);
    printf("Actual Result:   Pointer to \"%s\"\n\n", res1 ? res1 : "(null)");

    // Test 2: Search for '0' in str1 with size 0
    printf("Test 2:\n");
    const char *res2 = ft_memchr(str1, '0', 0);
    printf("Expected Result: (null) because size is 0\n");
    printf("Actual Result:   Pointer to \"%s\"\n\n", res2 ? res2 : "(null)");

    // Test 3: Search for '8' in str1 with size 20
    printf("Test 3:\n");
    const char *res3 = ft_memchr(str1, '8', 20);
    printf("Expected Result: (null) because '8' is not in \"%s\"\n", str1);
    printf("Actual Result:   Pointer to \"%s\"\n\n", res3 ? res3 : "(null)");

   // Test 4: Search for '1' in str2 with size 5
    printf("Test 4:\n");
    const char *res4 = ft_memchr(str2, 1, 5);
    printf("Expected Result: Pointer to '1' in {1, 2, 3, 4, 5}\n");
    printf("Actual Result:   Pointer to \"%s\"\n\n", res4 ? "1" : "(null)");

    // Test 5: Search for '5' in str2 with size 5
    printf("Test 5:\n");
    const char *res5 = ft_memchr(str2, 5, 3);
    printf("Expected Result: (null) because integer 5 is not in {1, 2, 3}\n");
    printf("Actual Result:   Pointer to \"%s\"\n\n", res5 ? res5 : "(null)");

    // Test 6: Search for '0' in str3 with size 5
    printf("Test 6:\n");
    const char *res6 = ft_memchr(str3, 0, 5);
    printf("Expected Result: Pointer to '0' in {0, 0, 0, 0, 0}\n");
    printf("Actual Result:   Pointer to \"%s\"\n\n", res6 ? "0" : "(null)");

    // Test 7: Search for '0' in str4 (NULL pointer) with size 5
    printf("Test 7:\n");
    const char *res7 = ft_memchr(str4, '0', 5);
    printf("Expected Result: (null) because input pointer is NULL\n");
    printf("Actual Result:   Pointer to \"%s\"\n\n", res7 ? res7 : "(null)");

    // Test 8: Search for '0' in NULL pointer with size 0
    printf("Test 8:\n");
    const char *res8 = ft_memchr(NULL, '0', 0);
    printf("Expected Result: (null) because input pointer is NULL\n");
    printf("Actual Result:   Pointer to \"%s\"\n\n", res8 ? res8 : "(null)");
}

int	main(void)
{
    test_isascii();
    test_isdigit();
    test_isprint();
    test_itoa();
    test_memchr();
	return (0);
}
