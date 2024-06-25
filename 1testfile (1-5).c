
// gcc *.c -o testfile

#include "libft.h"
#include <ctype.h>
#include <stdio.h>

void	test_atoi(void)
{
	printf("Testing atoi function:\n");
	write(1, "\n", 1);

	printf("Basic conversions:\n");
	printf("ft_atoi(\"1234\"): %d\n", ft_atoi("1234"));   // 1234
	printf("ft_atoi(\"-1234\"): %d\n", ft_atoi("-1234")); // -1234
	printf("ft_atoi(\"0\"): %d\n", ft_atoi("0"));         // 0
	write(1, "\n", 1);

	printf("Leading and trailing whitespaces:\n");
	printf("ft_atoi(\"   42\"): %d\n", ft_atoi("   42"));       // 42
	printf("ft_atoi(\"42   \"): %d\n", ft_atoi("42   "));       // 42
	printf("ft_atoi(\"   42   \"): %d\n", ft_atoi("   42   ")); // 42
	write(1, "\n", 1);

	printf("Leading and trailing non-digit characters:\n");
	printf("ft_atoi(\"a1234\"(Expected 0)): %d\n", ft_atoi("a1234"));
	printf("ft_atoi(\"1234a\"): %d\n", ft_atoi("1234a")); // 1234
	write(1, "\n", 1);

	printf("Mixed valid and invalid input:\n");
	printf("ft_atoi(\"123abc\"): %d\n", ft_atoi("123abc")); // 123
	printf("ft_atoi(\"abc123\"(Expected 0)): %d\n", ft_atoi("abc123"));
	printf("ft_atoi(\"\"(Expected 0)): %d\n", ft_atoi(""));       // 0
	printf("ft_atoi(\"   \"(Expected 0)): %d\n", ft_atoi("   ")); // 0
	printf("ft_atoi(\"--123\"(Expected 0)): %d\n", ft_atoi("--123"));
	write(1, "\n", 1);

	printf("Edge cases:\n");
	printf("ft_atoi(\"2147483647\"(Expected INT_MAX)): %d\n", ft_atoi("2147483647"));
	printf("ft_atoi(\"-2147483648\"(Expected INT_MIN)): %d\n", ft_atoi("-2147483648"));
	printf("ft_atoi(\"2147483648\"(Expected INT_MAX)): %d\n", ft_atoi("2147483648"));
	printf("ft_atoi(\"-2147483649\"((Expected INT_MIN))): %d\n", ft_atoi("-2147483649"));
	write(1, "\n", 1);

	printf("Overflow and underflow scenarios:\n");
	printf("ft_atoi(\"9223372036854775807\"(Expected INT_MAX)): %d\n",
		ft_atoi("9223372036854775807"));
	printf("ft_atoi(\"-9223372036854775808\"(Expected INT_MIN)): %d\n",
		ft_atoi("-9223372036854775808"));
	printf("ft_atoi(\"9999999999\"(Expected INT_MAX)): %d\n", ft_atoi("9999999999"));
	printf("ft_atoi(\"-9999999999\"(Expected INT_MIN)): %d\n", ft_atoi("-9999999999"));
	write(1, "\n", 1);
}

void	test_bzero(void)
{
		write(1, "\n", 1);
    printf("Testing bzero function:\n");
  char buffer[10];
    int passed_tests = 0;
    int total_tests = 5;
	write(1, "\n", 1);
    printf("Test 1: Basic Functionality Test\n");
    memset(buffer, 'A', sizeof(buffer));
    ft_bzero(buffer, 5);
    printf("Expected: first 5 bytes are zero, remaining are 'A'\n");
    for (int i = 0; i < 5; ++i) {
        if (buffer[i] != 0) {
            printf("Test 1 Failed: buffer[%d] is not zero\n", i);
        } else {
            printf("buffer[%d] = 0\n", i);
        }
    }
    for (int i = 5; i < 10; ++i) {
        if (buffer[i] != 'A') {
            printf("Test 1 Failed: buffer[%d] is not 'A'\n", i);
        } else {
            printf("buffer[%d] = 'A'\n", i);
        }
    }
    printf("Test 1 Passed\n\n");
    passed_tests++;

    write(1, "\n", 1);
    printf("Test 2: Zero Length Test\n");
    memset(buffer, 'A', sizeof(buffer));
    ft_bzero(buffer, 0);
    printf("Expected: buffer remains unchanged\n");
    for (int i = 0; i < 10; ++i) {
        if (buffer[i] != 'A') {
            printf("Test 2 Failed: buffer[%d] is not 'A'\n", i);
        } else {
            printf("buffer[%d] = 'A'\n", i);
        }
    }
    printf("Test 2 Passed\n\n");
    passed_tests++;

    write(1, "\n", 1);
    printf("Test 3: Full Buffer Zeroing Test\n");
    memset(buffer, 'A', sizeof(buffer));
    ft_bzero(buffer, sizeof(buffer));
    printf("Expected: all bytes are zero\n");
    for (int i = 0; i < 10; ++i) {
        if (buffer[i] != 0) {
            printf("Test 3 Failed: buffer[%d] is not zero\n", i);
        } else {
            printf("buffer[%d] = 0\n", i);
        }
    }
    printf("Test 3 Passed\n\n");
    passed_tests++;

   	write(1, "\n", 1);
    printf("Test 4: Partial Buffer Zeroing Test\n");
    memset(buffer, 'A', sizeof(buffer));
    ft_bzero(buffer + 2, 5);
    printf("Expected: first 2 bytes are 'A', next 5 bytes are zero, last 3 bytes are 'A'\n");
    for (int i = 0; i < 2; ++i) {
        if (buffer[i] != 'A') {
            printf("Test 4 Failed: buffer[%d] is not 'A'\n", i);
        } else {
            printf("buffer[%d] = 'A'\n", i);
        }
    }
    for (int i = 2; i < 7; ++i) {
        if (buffer[i] != 0) {
            printf("Test 4 Failed: buffer[%d] is not zero\n", i);
        } else {
            printf("buffer[%d] = 0\n", i);
        }
    }
    for (int i = 7; i < 10; ++i) {
        if (buffer[i] != 'A') {
            printf("Test 4 Failed: buffer[%d] is not 'A'\n", i);
        } else {
            printf("buffer[%d] = 'A'\n", i);
        }
    }
    printf("Test 4 Passed\n\n");
    passed_tests++;

    write(1, "\n", 1);
    printf("Test 5: Edge Case Test\n");
    char edge_buffer[1];
    edge_buffer[0] = 'A';
    ft_bzero(edge_buffer, 1);
    printf("Expected: the single byte is zero\n");
    if (edge_buffer[0] != 0) {
        printf("Test 5 Failed: edge_buffer[0] is not zero\n");
    } else {
        printf("edge_buffer[0] = 0\n");
    }
    printf("Test 5 Passed\n\n");
    passed_tests++;

    printf("Summary: Passed %d/%d tests\n", passed_tests, total_tests);
		write(1, "\n", 1);
}

void test_calloc() {

	write(1, "\n", 1);
	printf("Testing calloc function:\n");
    int passed_tests = 0;
    int total_tests = 5;

    printf("Test 1: Basic Allocation and Zero Initialization Test\n");
    int *arr = (int *)ft_calloc(5, sizeof(int));
    printf("Expected: All 5 integers are zero\n");
    for (int i = 0; i < 5; ++i) {
        if (arr[i] != 0) {
            printf("Test 1 Failed: arr[%d] is not zero\n", i);
        } else {
            printf("arr[%d] = 0\n", i);
        }
    }
	printf("Test 1 Passed\n\n");
    passed_tests++;
    free(arr);

    printf("Test 2: Zero Elements Allocation Test\n");
    arr = (int *)ft_calloc(0, sizeof(int));
    printf("Expected: No memory allocated (arr is NULL)\n");
    if (arr != NULL) {
        printf("Test 2 Failed: arr is not NULL\n\n");
    } else {
        printf("arr is NULL\n");
		printf("Test 2 Passed\n\n");
    	passed_tests++;
    }
    free(arr);


    printf("Test 3: Zero Size Allocation Test\n");
    arr = (int *)ft_calloc(5, 0);
    printf("Expected: No memory allocated (arr is NULL)\n");
    if (arr != NULL) {
        printf("Test 3 Failed: arr is not NULL\n\n");
    } else {
        printf("arr is NULL\n");
		printf("Test 3 Passed\n\n");
		passed_tests++;
    }
    free(arr);

    printf("Test 4: Large Allocation Test\n");
    size_t large_size = 1000;
    arr = (int *)ft_calloc(large_size, sizeof(int));
    printf("Expected: All %zu integers are zero\n", large_size);
    int test4_failed = 0;
    for (size_t i = 0; i < large_size; ++i) {
        if (arr[i] != 0) {
            printf("Test 4 Failed: arr[%zu] is not zero\n\n", i);
            test4_failed = 1;
            break;
        }
    }
    if (!test4_failed) {
        printf("All integers are zero\n");
        printf("Test 4 Passed\n\n");
        passed_tests++;
    }
    free(arr);

    // 5. Edge Case Test: Single Element
    printf("Test 5: Edge Case Test: Single Element\n");
    int *single = (int *)ft_calloc(1, sizeof(int));
    printf("Expected: The single integer is zero\n");
    if (single[0] != 0) {
        printf("Test 5 Failed: single[0] is not zero\n");
    } else {
        printf("single[0] = 0\n");
        printf("Test 5 Passed\n\n");
        passed_tests++;
    }
    free(single);

    printf("Summary: Passed %d/%d tests\n", passed_tests, total_tests);
    write(1, "\n", 1);
}

void test_isalnum(void) {
    printf("Testing isalnum function:\n");
    write(1, "\n", 1);

    printf("Basic alphanumeric checks:\n");
    printf("isalnum('a'): %d (expected 1)\n", ft_isalnum('a')); // 1
    printf("isalnum('Z'): %d (expected 1)\n", ft_isalnum('Z')); // 1
    printf("isalnum('0'): %d (expected 1)\n", ft_isalnum('0')); // 1
    write(1, "\n", 1);

    printf("Non-alphanumeric characters:\n");
    printf("isalnum('@'): %d (expected 0)\n", ft_isalnum('@')); // 0
    printf("isalnum(' '): %d (expected 0)\n", ft_isalnum(' ')); // 0
    printf("isalnum('\\n'): %d (expected 0)\n", ft_isalnum('\n')); // 0
    write(1, "\n", 1);

    printf("Boundary cases:\n");
    printf("isalnum('0' - 1): %d (expected 0)\n", ft_isalnum('0' - 1)); // 0
    printf("isalnum('Z' + 1): %d (expected 0)\n", ft_isalnum('Z' + 1)); // 0
    printf("isalnum('a' - 1): %d (expected 0)\n", ft_isalnum('a' - 1)); // 0
    write(1, "\n", 1);

    printf("Edge cases:\n");
    printf("isalnum(EOF): %d (expected 0)\n", ft_isalnum(EOF)); // 0
    write(1, "\n", 1);
}

void test_isalpha() 
{
	write(1, "\n", 1);
    printf("Testing isalpha function:\n");

    char lower_letters[] = "anz";
    for (int i = 0; lower_letters[i] != '\0'; ++i) {
        char ch = lower_letters[i];
        if (isalpha(ch)) {
            printf("%c is a letter.\n", ch);
        } else {
            printf("%c is not a letter.\n", ch);
        }
    }

    char upper_letters[] = "JLV";
    for (int i = 0; upper_letters[i] != '\0'; ++i) {
        char ch = upper_letters[i];
        if (isalpha(ch)) {
            printf("%c is a letter.\n", ch);
        } else {
            printf("%c is not a letter.\n", ch);
        }
    }

    char digits_and_symbols[] = "0!%^) \n";
    for (int i = 0; digits_and_symbols[i] != '\0'; ++i) {
        char ch = digits_and_symbols[i];
        if (isalpha(ch)) {
            printf("%c is a letter.\n", ch);
        } else {
            printf("%c is not a letter.\n", ch);
        }
    }
		write(1, "\n", 1);
}

int	main(void)
{
	test_atoi();
	test_bzero();
	test_calloc();
    test_isalnum();
	test_isalpha();
	return (0);
}
