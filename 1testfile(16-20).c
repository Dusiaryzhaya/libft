
// gcc *.c -o testfile

#include <ctype.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include "libft.h" 

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

void test_putendl_fd() {
    write(1, "\n", 1);
    printf("Testing putendl_fd function:\n");
    write(1, "\n", 1);
    const char *filename = "test_output.txt";
    int fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
    if (fd < 0) {
        perror("open");
        return;
    }

    // Test case 1: Write a simple string
    // Description: Writes the string "Hello, world!" followed by a newline to the file
    ft_putendl_fd("Hello, world!", fd);
    close(fd);
    printf("Test Case 1: Write a simple string \"Hello, world!\"\n");
    printf("Expected: Hello, world!\n");
    printf("Actual  : ");
    if (compare_file_content(filename, "Hello, world!\n")) {
        printf("Hello, world!\n");
        printf("Result  : Pass\n");
    } else {
        printf("Mismatch\n");
        printf("Result  : Fail\n");
    }
    printf("\n");

    // Test case 2: Write an empty string
    // Description: Writes an empty string followed by a newline to the file
    fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
    if (fd < 0) {
        perror("open");
        return;
    }
    ft_putendl_fd("", fd);
    close(fd);
    printf("Test Case 2: Write an empty string\n");
    printf("Expected: \\n\n");
    printf("Actual  : ");
    if (compare_file_content(filename, "\n")) {
        printf("\\n\n");
        printf("Result  : Pass\n");
    } else {
        printf("Mismatch\n");
        printf("Result  : Fail\n");
    }
    printf("\n");

    // Test case 3: Write a string with special characters
    // Description: Writes the string "Special!@#$%^&*()" followed by a newline to the file
    fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
    if (fd < 0) {
        perror("open");
        return;
    }
    ft_putendl_fd("Special!@#$^&*()", fd);
    close(fd);
    printf("Test Case 3: Write a string with special characters \"Special!@#$^&*()\"\n");
    printf("Expected: Special!@#$^&*()\n");
    printf("Actual  : ");
    if (compare_file_content(filename, "Special!@#$^&*()\n")) {
        printf("Special!@#$^&*()\n");
        printf("Result  : Pass\n");
    } else {
        printf("Mismatch\n");
        printf("Result  : Fail\n");
    }
    printf("\n");
    remove(filename);
}

void test_putnbr_fd() {
    write(1, "\n", 1);
    printf("Testing putnbr_fd function:\n");
    write(1, "\n", 1);
    const char *filename = "test_output.txt";
    int fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
    if (fd < 0) {
        perror("open");
        return;
    }

    // Test case 1: Write a positive integer
    // Description: Writes the integer 12345 to the file
    ft_putnbr_fd(12345, fd);
    close(fd);
    printf("Test Case 1: Write a positive integer 12345\n");
    printf("Expected: 12345\n");
    printf("Actual  : ");
    if (compare_file_content(filename, "12345")) {
        printf("12345\n");
        printf("Result  : Pass\n");
    } else {
        printf("Mismatch\n");
        printf("Result  : Fail\n");
    }
    printf("\n");

    // Test case 2: Write a negative integer
    // Description: Writes the integer -12345 to the file
    fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
    if (fd < 0) {
        perror("open");
        return;
    }
    ft_putnbr_fd(-12345, fd);
    close(fd);
    printf("Test Case 2: Write a negative integer -12345\n");
    printf("Expected: -12345\n");
    printf("Actual  : ");
    if (compare_file_content(filename, "-12345")) {
        printf("-12345\n");
        printf("Result  : Pass\n");
    } else {
        printf("Mismatch\n");
        printf("Result  : Fail\n");
    }
    printf("\n");

    // Test case 3: Write zero
    // Description: Writes the integer 0 to the file
    fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
    if (fd < 0) {
        perror("open");
        return;
    }
    ft_putnbr_fd(0, fd);
    close(fd);
    printf("Test Case 3: Write zero\n");
    printf("Expected: 0\n");
    printf("Actual  : ");
    if (compare_file_content(filename, "0")) {
        printf("0\n");
        printf("Result  : Pass\n");
    } else {
        printf("Mismatch\n");
        printf("Result  : Fail\n");
    }
    printf("\n");

    // Test case 4: Write the minimum integer value
    // Description: Writes the integer -2147483648 to the file
    fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
    if (fd < 0) {
        perror("open");
        return;
    }
    ft_putnbr_fd(-2147483648, fd);
    close(fd);
    printf("Test Case 4: Write the minimum integer value -2147483648\n");
    printf("Expected: -2147483648\n");
    printf("Actual  : ");
    if (compare_file_content(filename, "-2147483648")) {
        printf("-2147483648\n");
        printf("Result  : Pass\n");
    } else {
        printf("Mismatch\n");
        printf("Result  : Fail\n");
    }
    printf("\n");
    remove(filename);
}

void test_putstr_fd() {
    write(1, "\n", 1);
    printf("Testing putstr_fd function:\n");
    write(1, "\n", 1);
    const char *filename = "test_output.txt";
    int fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
    if (fd < 0) {
        perror("open");
        return;
    }

    // Test case 1: Write a simple string
    // Description: Writes the string "Hello, world!" followed by a newline to the file
    ft_putstr_fd("Hello, world!", fd);
    close(fd);
    printf("Test Case 1: Write a simple string \"Hello, world!\"\n");
    printf("Expected: Hello, world!\n");
    printf("Actual  : ");
    if (compare_file_content(filename, "Hello, world!")) {
        printf("Hello, world!\n");
        printf("Result  : Pass\n");
    } else {
        printf("Mismatch\n");
        printf("Result  : Fail\n");
    }
    printf("\n");

    // Test case 2: Write an empty string
    // Description: Writes an empty string followed by a newline to the file
    fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
    if (fd < 0) {
        perror("open");
        return;
    }
    ft_putstr_fd("", fd);
    close(fd);
    printf("Test Case 2: Write an empty string\n");
    printf("Expected: \n");
    printf("Actual  : ");
    if (compare_file_content(filename, "")) {
        printf("\n");
        printf("Result  : Pass\n");
    } else {
        printf("Mismatch\n");
        printf("Result  : Fail\n");
    }
    printf("\n");

    // Test case 3: Write a string with special characters
    // Description: Writes the string "Special!@#$%^&*()" followed by a newline to the file
    fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
    if (fd < 0) {
        perror("open");
        return;
    }
    ft_putstr_fd("Special!@#$^&*()", fd);
    close(fd);
    printf("Test Case 3: Write a string with special characters \"Special!@#$^&*()\"\n");
    printf("Expected: Special!@#$^&*()\n");
    printf("Actual  : ");
    if (compare_file_content(filename, "Special!@#$^&*()")) {
        printf("Special!@#$^&*()\n");
        printf("Result  : Pass\n");
    } else {
        printf("Mismatch\n");
        printf("Result  : Fail\n");
    }
    printf("\n");
    remove(filename);
}

void print_split_result(char **result) {
    if (!result) {
        printf("NULL\n");
        return;
    }
    while (*result) {
        printf("\"%s\", ", *result);
        result++;
    }
    printf("NULL\n");
}

// Function to free the result of ft_split
void free_split_result(char **result) {
    if (!result)
        return;
    for (size_t i = 0; result[i]; i++) {
        free(result[i]);
    }
    free(result);
}


void test_split() {
    write(1, "\n", 1);
    printf("Testing split function:\n");
    write(1, "\n", 1);
    // Test case 1: Splitting a normal string
    // Description: Splits the string "Hello world this is C" by spaces
    char **result = ft_split("Hello world this is C", ' ');
    printf("Test Case 1: Split \"Hello world this is C\" by ' '\n");
    printf("Expected: \"Hello\", \"world\", \"this\", \"is\", \"C\", NULL\n");
    printf("Actual  : ");
    print_split_result(result);
    free_split_result(result);
    printf("Result  : %s\n", result ? "Pass" : "Fail");
    printf("\n");

    // Test case 2: Splitting a string with multiple delimiters
    // Description: Splits the string "one,,two,three,,four" by ','
    result = ft_split("one,,two,three,,four", ',');
    printf("Test Case 2: Split \"one,,two,three,,four\" by ','\n");
    printf("Expected: \"one\", \"two\", \"three\", \"four\", NULL\n");
    printf("Actual  : ");
    print_split_result(result);
    free_split_result(result);
    printf("Result  : %s\n", result ? "Pass" : "Fail");
    printf("\n");

    // Test case 3: Splitting a string with leading and trailing delimiters
    // Description: Splits the string ",one,two,three," by ','
    result = ft_split(",one,two,three,", ',');
    printf("Test Case 3: Split \",one,two,three,\" by ','\n");
    printf("Expected: \"one\", \"two\", \"three\", NULL\n");
    printf("Actual  : ");
    print_split_result(result);
    free_split_result(result);
    printf("Result  : %s\n", result ? "Pass" : "Fail");
    printf("\n");

    // Test case 4: Splitting an empty string
    // Description: Splits an empty string by ','
    result = ft_split("", ',');
    printf("Test Case 4: Split \"\" by ','\n");
    printf("Expected: NULL\n");
    printf("Actual  : ");
    if (!result || result[0] == NULL) {
        printf("NULL\n");
        printf("Result  : Pass\n");
    } else {
        print_split_result(result);
        printf("Result  : Fail\n");
    }
    free_split_result(result);
    printf("\n");


    // Test case 5: Splitting a string with no delimiters
    // Description: Splits the string "nodelem" by ','
    result = ft_split("nodelem", ',');
    printf("Test Case 5: Split \"nodelem\" by ','\n");
    printf("Expected: \"nodelem\", NULL\n");
    printf("Actual  : ");
    print_split_result(result);
    free_split_result(result);
    printf("Result  : %s\n", result ? "Pass" : "Fail");
    printf("\n");

    // Test case 6: NULL input
    // Description: Handles a NULL input
    result = ft_split(NULL, ',');
    printf("Test Case 6: NULL input\n");
    printf("Expected: NULL\n");
    printf("Actual  : ");
    print_split_result(result);
    printf("Result  : %s\n", !result ? "Pass" : "Fail");
    printf("\n");
        // Test case 7: Splitting a long string with multiple delimiters
    // Description: Splits a long string "a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z" by ','
    const char *long_str = "a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z";
    result = ft_split(long_str, ',');
    printf("Test Case 7: Split \"%s\" by ','\n", long_str);
    printf("Expected: \"a\", \"b\", \"c\", ..., \"z\", NULL\n");
    printf("Actual  : ");
    print_split_result(result);
    printf("Result  : %s\n\n", result ? "Pass" : "Fail");
    free_split_result(result);
}

void test_strchr() {
    write(1, "\n", 1);
    printf("Testing strchr function:\n");
    write(1, "\n", 1);
    // Test case 1: Character found in the middle
    // Description: Finds the first occurrence of 'o' in "Hello, world!"
    const char *str1 = "Hello, world!";
    char c1 = 'o';
    char *result = ft_strchr(str1, c1);
    printf("Test Case 1: Find 'o' in \"Hello, world!\"\n");
    printf("Expected: %s\n", "o, world!");
    printf("Actual  : %s\n", result);
    printf("Result  : %s\n\n", result == str1 + 4 ? "Pass" : "Fail");

    // Test case 2: Character found at the beginning
    // Description: Finds the first occurrence of 'H' in "Hello, world!"
    const char *str2 = "Hello, world!";
    char c2 = 'H';
    result = ft_strchr(str2, c2);
    printf("Test Case 2: Find 'H' in \"Hello, world!\"\n");
    printf("Expected: %s\n", "Hello, world!");
    printf("Actual  : %s\n", result);
    printf("Result  : %s\n\n", result == str2 ? "Pass" : "Fail");

    // Test case 3: Character found at the end
    // Description: Finds the first occurrence of '!' in "Hello, world!"
    const char *str3 = "Hello, world!";
    char c3 = '!';
    result = ft_strchr(str3, c3);
    printf("Test Case 3: Find '!' in \"Hello, world!\"\n");
    printf("Expected: %s\n", "!");
    printf("Actual  : %s\n", result);
    printf("Result  : %s\n\n", result == str3 + 12 ? "Pass" : "Fail");

    // Test case 4: Character not found
    // Description: Tries to find 'x' in "Hello, world!"
    const char *str4 = "Hello, world!";
    char c4 = 'x';
    result = ft_strchr(str4, c4);
    printf("Test Case 4: Find 'x' in \"Hello, world!\"\n");
    printf("Expected: %p\n", NULL);
    printf("Actual  : %p\n", result);
    printf("Result  : %s\n\n", result == NULL ? "Pass" : "Fail");

    // Test case 5: Null terminator
    // Description: Finds the null terminator in "Hello, world!"
    const char *str5 = "Hello, world!";
    char c5 = '\0';
    result = ft_strchr(str5, c5);
    printf("Test Case 5: Find '\\0' in \"Hello, world!\"\n");
    printf("Expected: %s\n", "");
    printf("Actual  : %s\n", result);
    printf("Result  : %s\n\n", result == str5 + 13 ? "Pass" : "Fail");

    // Test case 6: Empty string
    // Description: Finds any character in an empty string
    const char *str6 = "";
    char c6 = 'a';
    result = ft_strchr(str6, c6);
    printf("Test Case 6: Find 'a' in \"\"\n");
    printf("Expected: %p\n", NULL);
    printf("Actual  : %p\n", result);
    printf("Result  : %s\n\n", result == NULL ? "Pass" : "Fail");

    // Test case 7: Find null terminator in an empty string
    // Description: Finds the null terminator in an empty string
    char c7 = '\0';
    result = ft_strchr(str6, c7);
    printf("Test Case 7: Find '\\0' in \"\"\n");
    printf("Expected: %s\n", "");
    printf("Actual  : %s\n", result);
    printf("Result  : %s\n\n", result == str6 ? "Pass" : "Fail");
}

int	main(void)
{
	test_putendl_fd();
	test_putnbr_fd();
	test_putstr_fd();
    test_split();
	test_strchr();
	return (0);
}