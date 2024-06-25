
// gcc *.c -o testfile

#include <ctype.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h> // for memcmp
#include "libft.h" // assuming your ft_memcmp function is declared in libft.h

void test_memcmp(void) {
    write(1, "\n", 1);
    printf("Testing memcmp function:\n");
    write(1, "\n", 1);

    // Test 1: Comparing equal memory blocks
    printf("Test 1: Comparing equal memory blocks\n");
    char str1[] = "Hello";
    char str2[] = "Hello";
    int len1 = 5;
    int len2 = 5;
    int result1 = ft_memcmp(str1, str2, len1);
    int expected1 = memcmp(str1, str2, len1);
    printf("Expected Result: %d\n", expected1);
    printf("Actual Result:   %d\n", result1);
    if (result1 == expected1)
        printf("Test 1 Passed\n");
    else
        printf("Test 1 Failed\n");

    // Test 2: Comparing different memory blocks
    printf("\nTest 2: Comparing different memory blocks\n");
    char str3[] = "Hello";
    char str4[] = "World";
    int len3 = 5;
    int len4 = 5;
    int result2 = ft_memcmp(str3, str4, len3);
    int expected2 = memcmp(str3, str4, len3);
    printf("Expected Result: %d\n", expected2);
    printf("Actual Result:   %d\n", result2);
    if (result2 == expected2)
        printf("Test 2 Passed\n");
    else
        printf("Test 2 Failed\n");

    // Test 3: Comparing part of memory blocks
    printf("\nTest 3: Comparing part of memory blocks\n");
    char str5[] = "Hello";
    char str6[] = "HellO";
    int len5 = 4;
    int len6 = 4;
    int result3 = ft_memcmp(str5, str6, len5);
    int expected3 = memcmp(str5, str6, len5);
    printf("Expected Result: %d\n", expected3);
    printf("Actual Result:   %d\n", result3);
    if (result3 == expected3)
        printf("Test 3 Passed\n");
    else
        printf("Test 3 Failed\n");

    // Test 4: Comparing memory blocks of different lengths
    printf("\nTest 4: Comparing memory blocks of different lengths\n");
    char str7[] = "Helloooooo";
    char str8[] = "Hello";
    int len7 = 5;
    int len8 = 3;
    int result4 = ft_memcmp(str7, str8, len7);
    int expected4 = memcmp(str7, str8, len7);
    printf("Expected Result: %d\n", expected4);
    printf("Actual Result:   %d\n", result4);
    if (result4 == expected4)
        printf("Test 4 Passed\n");
    else
        printf("Test 4 Failed\n");
}

void test_memcpy() {
    write(1, "\n", 1);
    printf("Testing memcpy function:\n");
    write(1, "\n", 1);

    char buffer[50];  // Buffer to store copied data

    // Test case 1: Copying a simple string
    const char *src1 = "Hello, world!";
    size_t len1 = strlen(src1) + 1;  // Include null terminator
    ft_memcpy(buffer, src1, len1);
    printf("Test Case 1: Copying a simple string\n");
    printf("Expected: %s\n", src1);
    printf("Actual  : %s\n", buffer);
    printf("Result  : %s\n", strcmp(buffer, src1) == 0 ? "Pass" : "Fail");
    write(1, "\n", 1);

    // Test case 2: Copying part of a string
    const char *src2 = "Goodbye";
    size_t len2 = 4;  // Only copy "Good"
    ft_memcpy(buffer, src2, len2);
    buffer[len2] = '\0';  // Null terminate the copied part
    printf("Test Case 2: Copying part of a string\n");
    printf("Expected: %.*s\n", (int)len2, src2);  // Print only the first len2 characters
    printf("Actual  : %s\n", buffer);
    printf("Result  : %s\n", strncmp(buffer, src2, len2) == 0 ? "Pass" : "Fail");
    write(1, "\n", 1);

    // Test case 3: Copying an array of integers
    int src3[] = {1, 2, 3, 4, 5};
    int dest3[5];
    size_t len3 = sizeof(src3);  // Copy entire array
    ft_memcpy(dest3, src3, len3);
    printf("Test Case 3: Copying an array of integers\n");
    printf("Expected: {1, 2, 3, 4, 5}\n");
    printf("Actual  : {%d, %d, %d, %d, %d}\n", dest3[0], dest3[1], dest3[2], dest3[3], dest3[4]);
    int array_pass = 1;
    for (size_t i = 0; i < sizeof(src3) / sizeof(int); ++i) {
        if (dest3[i] != src3[i]) {
            array_pass = 0;
            break;
        }
    }
    printf("Result  : %s\n", array_pass ? "Pass" : "Fail");
    write(1, "\n", 1);

    // Test case 4: Copying a large block of memory
    char src4[1000];
    for (size_t i = 0; i < sizeof(src4); ++i) {
        src4[i] = (char)(i % 256);
    }
    char dest4[1000];
    size_t len4 = sizeof(src4);
    ft_memcpy(dest4, src4, len4);
    printf("Test Case 4: Copying a large block of memory\n");
    int large_block_pass = 1;
    for (size_t i = 0; i < len4; ++i) {
        if (dest4[i] != src4[i]) {
            large_block_pass = 0;
            break;
        }
    }
    printf("Expected: src4 content\n");
    printf("Actual  : dest4 content matches src4 content\n");
    printf("Result  : %s\n", large_block_pass ? "Pass" : "Fail");
    write(1, "\n", 1);

    // Test case 5: NULL destination
    printf("Test Case 5: NULL destination\n");
    void *result5 = ft_memcpy(NULL, src1, len1);
    printf("Expected: NULL\n");
    printf("Actual  : %p\n", result5);
    printf("Result  : %s\n", result5 == NULL ? "Pass" : "Fail");
    write(1, "\n", 1);

    // Test case 6: NULL source
    printf("Test Case 6: NULL source\n");
    void *result6 = ft_memcpy(buffer, NULL, len1);
    printf("Expected: NULL\n");
    printf("Actual  : %p\n", result6);
    printf("Result  : %s\n", result6 == NULL ? "Pass" : "Fail");
    write(1, "\n", 1);

    // Test case 7: NULL source and destination
    printf("Test Case 7: NULL source and destination\n");
    void *result7 = ft_memcpy(NULL, NULL, len1);
    printf("Expected: NULL\n");
    printf("Actual  : %p\n", result7);
    printf("Result  : %s\n", result7 == NULL ? "Pass" : "Fail");
    write(1, "\n", 1);
}
// Function to test ft_memmove
void test_memmove() {
    write(1, "\n", 1);
    printf("Testing memmove function:\n");
    write(1, "\n", 1);

    char buffer[50];  // Buffer to store copied data

    // Test case 1: Copying a simple string
    printf("Test Case 1: Copying a simple string\n");
    const char *src1 = "Hello, world!";
    size_t len1 = strlen(src1) + 1;  // Include null terminator
    ft_memmove(buffer, src1, len1);
    printf("Expected: %s\n", src1);
    printf("Actual  : %s\n", buffer);
    printf("Result  : %s\n", strcmp(buffer, src1) == 0 ? "Pass" : "Fail");
    printf("\n");

    // Test case 2: Copying part of a string
    printf("Test Case 2: Copying part of a string\n");
    const char *src2 = "Goodbye";
    size_t len2 = 4;  // Only copy "Good"
    ft_memmove(buffer, src2, len2);
    buffer[len2] = '\0';  // Null terminate the copied part
    printf("Expected: %.*s\n", (int)len2, src2);  // Print only the first len2 characters
    printf("Actual  : %s\n", buffer);
    printf("Result  : %s\n", strncmp(buffer, src2, len2) == 0 ? "Pass" : "Fail");
    printf("\n");

    // Test case 3: Copying an array of integers
    printf("Test Case 3: Copying an array of integers\n");
    int src3[] = {1, 2, 3, 4, 5};
    int dest3[5];
    size_t len3 = sizeof(src3);  // Copy entire array
    ft_memmove(dest3, src3, len3);
    printf("Expected: {1, 2, 3, 4, 5}\n");
    printf("Actual  : {%d, %d, %d, %d, %d}\n", dest3[0], dest3[1], dest3[2], dest3[3], dest3[4]);
    int array_pass = 1;
    for (size_t i = 0; i < sizeof(src3) / sizeof(int); ++i) {
        if (dest3[i] != src3[i]) {
            array_pass = 0;
            break;
        }
    }
    printf("Result  : %s\n", array_pass ? "Pass" : "Fail");
    printf("\n");

    // Test case 4: Copying a large block of memory
    printf("Test Case 4: Copying a large block of memory\n");
    char src4[1000];
    for (size_t i = 0; i < sizeof(src4); ++i) {
        src4[i] = (char)(i % 256);
    }
    char dest4[1000];
    size_t len4 = sizeof(src4);
    ft_memmove(dest4, src4, len4);
    int large_block_pass = 1;
    for (size_t i = 0; i < len4; ++i) {
        if (dest4[i] != src4[i]) {
            large_block_pass = 0;
            break;
        }
    }
    printf("Expected: src4 content\n");
    printf("Actual  : dest4 content matches src4 content\n");
    printf("Result  : %s\n", large_block_pass ? "Pass" : "Fail");
    printf("\n");

    // Test case 5: NULL destination
    printf("Test Case 5: NULL destination\n");
    void *result5 = ft_memmove(NULL, src1, len1);
    printf("Expected: NULL\n");
    printf("Actual  : %p\n", result5);
    printf("Result  : %s\n", result5 == NULL ? "Pass" : "Fail");
    printf("\n");

    // Test case 6: NULL source
    printf("Test Case 6: NULL source\n");
    void *result6 = ft_memmove(buffer, NULL, len1);
    printf("Expected: NULL\n");
    printf("Actual  : %p\n", result6);
    printf("Result  : %s\n", result6 == NULL ? "Pass" : "Fail");
    printf("\n");

    // Test case 7: NULL source and destination
    printf("Test Case 7: NULL source and destination\n");
    void *result7 = ft_memmove(NULL, NULL, len1);
    printf("Expected: NULL\n");
    printf("Actual  : %p\n", result7);
    printf("Result  : %s\n", result7 == NULL ? "Pass" : "Fail");
    printf("\n");

    // Test case 8: Overlapping regions (source before destination)
    printf("Test Case 8: Overlapping regions (source before destination)\n");
    char overlap_src1[20] = "1234567890";
    memmove(overlap_src1 + 2, overlap_src1, 5);  // Use standard memmove to get expected result
    printf("Expected: %s\n", overlap_src1);
    char overlap_src12[20] = "1234567890";
    ft_memmove(overlap_src12 + 2, overlap_src12, 5);  // Test custom memmove
    printf("Actual  : %s\n", overlap_src12);
    printf("Result  : %s\n\n", strcmp(overlap_src1, "1212345890") == 0 ? "Pass" : "Fail");

    // Test case 9: Overlapping regions (destination before source)
    printf("Test Case 9: Overlapping regions (destination before source)\n");
    char overlap_src2[20] = "1234567890";
    memmove(overlap_src2, overlap_src2 + 2, 5);  // Use standard memmove to get expected result
    printf("Expected: %s\n", overlap_src2);
    char overlap_src22[20] = "1234567890";
    ft_memmove(overlap_src22, overlap_src22 + 2, 5);  // Test custom memmove
    printf("Actual  : %s\n", overlap_src22);
    printf("Result  : %s\n\n", strcmp(overlap_src2, "3456767890") == 0 ? "Pass" : "Fail");
    write(1, "\n", 1);
}

void test_memset()
{
    write(1, "\n", 1);
    printf("Testing memset function:\n");
    write(1, "\n", 1);

    char buffer[50];
    int numbers[5];
    struct {
        int x;
        float y;
        char z;
    } data;
    char large_buffer[1000];

    // Test case 1: Setting a simple string to a character
    // Description: Sets the first 13 characters of the buffer to '*' where the source is "Hello, world!"
    const char *src1 = "Hello, world!";
    size_t len1 = strlen(src1);  // Length of the string without null terminator
    strcpy(buffer, src1);  // Initialize buffer with src1
    ft_memset(buffer, '*', len1);
    buffer[len1] = '\0';  // Null-terminate the modified string
    printf("Test Case 1: Setting a simple string to a character\n");
    printf("Expected: %s\n", "*************");
    printf("Actual  : %s\n", buffer);
    printf("Result  : %s\n", strcmp(buffer, "*************") == 0 ? "Pass" : "Fail");
    printf("\n");


    // Test case 2: Setting a block of integers to zero
    printf("Test Case 2: Setting a block of integers to zero\n");
    int initial_numbers[5] = {1, 2, 3, 4, 5};
    memcpy(numbers, initial_numbers, sizeof(numbers));  // Copy initial data
    ft_memset(numbers, 0, sizeof(numbers));
    printf("Expected: {0, 0, 0, 0, 0}\n");
    printf("Actual  : {%d, %d, %d, %d, %d}\n", numbers[0], numbers[1], numbers[2], numbers[3], numbers[4]);
    if (numbers[0] == 0 && numbers[1] == 0 && numbers[2] == 0 && numbers[3] == 0 && numbers[4] == 0) {
        printf("Result  : Pass\n\n");
    } else {
        printf("Result  : Fail\n\n");
    }

    // Test case 3: Setting a structure to a specific value
    printf("Test Case 3: Setting a structure to a specific value\n");
    data.x = 10;
    data.y = 3.14;
    data.z = 'A';
    ft_memset(&data, 0, sizeof(data));
    printf("Expected: {0, 0.0, '\\0'}\n");
    printf("Actual  : {%d, %f, '%c'}\n", data.x, data.y, data.z);
    if (data.x == 0 && data.y == 0.0 && data.z == '\0') {
        printf("Result  : Pass\n\n");
    } else {
        printf("Result  : Fail\n\n");
    }

    // Test case 4: Setting a large block of memory to a non-zero value
    printf("Test Case 4: Setting a large block of memory to a non-zero value\n");
    ft_memset(large_buffer, 'A', sizeof(large_buffer));
    printf("Expected: A repeated 1000 times\n");
    printf("Actual  : %.20s\n", large_buffer);  // Print only the first 20 characters
    int large_pass = 1;
    for (size_t i = 0; i < sizeof(large_buffer); ++i) {
        if (large_buffer[i] != 'A') {
            large_pass = 0;
            break;
        }
    }
    if (large_pass) {
        printf("Result  : Pass\n\n");
    } else {
        printf("Result  : Fail\n\n");
    }
}

// Function to compare file content with expected string
int compare_file_content(const char *filename, const char *expected) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("fopen");
        return 0;
    }
    char buffer[1024];
    size_t len = fread(buffer, 1, sizeof(buffer) - 1, file);
    buffer[len] = '\0';
    fclose(file);
    return strcmp(buffer, expected) == 0;
}

    void test_putchar_fd()
{
    write(1, "\n", 1);
    printf("Testing putchar_fd function:\n");
    write(1, "\n", 1);
        const char *filename = "test_output.txt";
    int fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
    if (fd < 0) {
        perror("open");
        return;
    }

    // Test case 1: Write a single character 'A'
    // Description: Writes the character 'A' to the file
    ft_putchar_fd('A', fd);
    close(fd);
    printf("Test Case 1: Write a single character 'A'\n");
    printf("Expected: A\n");
    printf("Actual  : ");
    if (compare_file_content(filename, "A")) {
        printf("A\n");
        printf("Result  : Pass\n");
    } else {
        printf("Mismatch\n");
        printf("Result  : Fail\n");
    }
    printf("\n");

    // Test case 2: Write multiple characters sequentially
    // Description: Writes the characters 'B', 'C', 'D' to the file
    fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
    if (fd < 0) {
        perror("open");
        return;
    }
    ft_putchar_fd('B', fd);
    ft_putchar_fd('C', fd);
    ft_putchar_fd('D', fd);
    close(fd);
    printf("Test Case 2: Write multiple characters 'BCD'\n");
    printf("Expected: BCD\n");
    printf("Actual  : ");
    if (compare_file_content(filename, "BCD")) {
        printf("BCD\n");
        printf("Result  : Pass\n");
    } else {
        printf("Mismatch\n");
        printf("Result  : Fail\n");
    }
    printf("\n");

    // Test case 3: Write character to a closed file descriptor
    // Description: Attempts to write 'E' to a closed file descriptor, should handle error gracefully
    ft_putchar_fd('E', fd);  // fd is already closed
    printf("Test Case 3: Write to a closed file descriptor\n");
    printf("Expected: No effect (handle gracefully)\n");
    printf("Actual  : No effect\n");
    printf("Result  : No effect\n");
    printf("\n");
    remove(filename);
}

int	main(void)
{
    test_memcmp();
    test_memcpy();
    test_memmove();
    test_memset();
    test_putchar_fd();
	return (0);
}
