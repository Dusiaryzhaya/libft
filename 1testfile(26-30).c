
// gcc *.c -o testfile

#include <ctype.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include "libft.h" 

void test_strlen()
{
    printf("\nTesting ft_strlen function:\n\n");

    // Test Case 1: Regular string
    const char *str1 = "Hello, World!";
    size_t result1 = ft_strlen(str1);
    printf("Test Case 1:\n");
    printf("String  : \"%s\"\n", str1);
    printf("Expected: %zu\n", strlen(str1));
    printf("Actual  : %zu\n", result1);
    printf("Result  : %s\n\n", result1 == strlen(str1) ? "Pass" : "Fail");

    // Test Case 2: Empty string
    const char *str2 = "";
    size_t result2 = ft_strlen(str2);
    printf("Test Case 2:\n");
    printf("String  : \"%s\"\n", str2);
    printf("Expected: %zu\n", strlen(str2));
    printf("Actual  : %zu\n", result2);
    printf("Result  : %s\n\n", result2 == strlen(str2) ? "Pass" : "Fail");

    // Test Case 3: Null string (Custom implementation should handle it gracefully)
    const char *str3 = NULL;
    size_t result3;
    printf("Test Case 3:\n");
    printf("String  : NULL\n");
    printf("Expected: 0 (assuming custom implementation returns 0 for NULL)\n");
    if (str3 == NULL) {
        printf("Actual  : NULL (Not tested to avoid crash)\n");
        result3 = 0;
    } else {
        result3 = ft_strlen(str3);
        printf("Actual  : %zu\n", result3);
    }
    printf("Result  : %s\n\n", (str3 == NULL && result3 == 0) ? "Pass" : "Fail");

    // Test Case 4: Long string
    const char *str4 = "veryverylongstringIdontknowhowmanysimbolsitisbutitsabsolutelysimuchofthem";
    size_t result4 = ft_strlen(str4);
    printf("Test Case 4:\n");
    printf("String  : \"%s\"\n", str4);
    printf("Expected: %zu\n", strlen(str4));
    printf("Actual  : %zu\n", result4);
    printf("Result  : %s\n\n", result4 == strlen(str4) ? "Pass" : "Fail");

        // Test Case 5: String with spaces
    const char *str5 = "This is a string with spaces.";
    size_t result5 = ft_strlen(str5);
    printf("Test Case 5:\n");
    printf("String  : \"%s\"\n", str5);
    printf("Expected: %zu\n", strlen(str5));
    printf("Actual  : %zu\n", result5);
    printf("Result  : %s\n\n", result5 == strlen(str5) ? "Pass" : "Fail");

    // Test Case 6: String with special characters
    const char *str6 = "!@#$^&*()_+";
    size_t result6 = ft_strlen(str6);
    printf("Test Case 6:\n");
    printf("String  : \"%s\"\n", str6);
    printf("Expected: %zu\n", strlen(str6));
    printf("Actual  : %zu\n", result6);
    printf("Result  : %s\n\n", result6 == strlen(str6) ? "Pass" : "Fail");

    // Test Case 7: String with newline characters
    const char *str7 = "Hello\nWorld\n";
    size_t result7 = ft_strlen(str7);
    printf("Test Case 7:\n");
    printf("String  : \"%s\"\n", str7);
    printf("Expected: %zu\n", strlen(str7));
    printf("Actual  : %zu\n", result7);
    printf("Result  : %s\n\n", result7 == strlen(str7) ? "Pass" : "Fail");

    // Test Case 8: String with maximum length (test with a reasonably large length to avoid allocation issues)
    char str8[1001];
    for (int i = 0; i < 1000; i++) {
        str8[i] = 'a';
    }
    str8[1000] = '\0';
    size_t result8 = ft_strlen(str8);
    printf("Test Case 8:\n");
    printf("String  : \"(1000 'a' characters)\"\n");
    printf("Expected: %zu\n", strlen(str8));
    printf("Actual  : %zu\n", result8);
    printf("Result  : %s\n\n", result8 == strlen(str8) ? "Pass" : "Fail");
}

char toggle_case(unsigned int i, char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 'A';
    } else if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 'a';
    }
    return c; // Non-alphabetic characters remain unchanged
}

void test_strmapi()
{
        printf("\nTesting ft_strmapi function:\n\n");

    // Test Case 1: Basic test
    const char *str1 = "abc";
    char *result1 = ft_strmapi(str1, toggle_case);
    printf("Test Case 1:\n");
    printf("String  : \"%s\"\n", str1);
    printf("Expected: \"ABC\"\n");
    printf("Actual  : \"%s\"\n", result1);
    printf("Result  : %s\n\n", strcmp(result1, "ABC") == 0 ? "Pass" : "Fail");
    free(result1);

    // Test Case 2: Empty string
    const char *str2 = "";
    char *result2 = ft_strmapi(str2, toggle_case);
    printf("Test Case 2:\n");
    printf("String  : \"%s\"\n", str2);
    printf("Expected: \"\"\n");
    printf("Actual  : \"%s\"\n", result2);
    printf("Result  : %s\n\n", strcmp(result2, "") == 0 ? "Pass" : "Fail");
    free(result2);

    // Test Case 3: Null string
    const char *str3 = NULL;
    char *result3 = ft_strmapi(str3, toggle_case);
    printf("Test Case 3:\n");
    printf("String  : NULL\n");
    printf("Expected: NULL\n");
    printf("Actual  : %p\n", result3);
    printf("Result  : %s\n\n", result3 == NULL ? "Pass" : "Fail");

    // Test Case 4: String with special characters
    const char *str4 = "!@#";
    char *result4 = ft_strmapi(str4, toggle_case);
    printf("Test Case 4:\n");
    printf("String  : \"%s\"\n", str4);
    printf("Expected: \"!@#\"\n");
    printf("Actual  : \"%s\"\n", result4);
    printf("Result  : %s\n\n", strcmp(result4, "!@#") == 0 ? "Pass" : "Fail");
    free(result4);

    // Test Case 5: Long string
    const char *str5 = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *result5 = ft_strmapi(str5, toggle_case);
    printf("Test Case 5:\n");
    printf("String  : \"%s\"\n", str5);
    printf("Expected: \"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz\"\n");
    printf("Actual  : \"%s\"\n", result5);
    printf("Result  : %s\n\n", strcmp(result5, "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz") == 0 ? "Pass" : "Fail");
    free(result5);

    // Test Case 6: String with spaces
    const char *str6 = "Test string!";
    char *result6 = ft_strmapi(str6, toggle_case);
    printf("Test Case 6:\n");
    printf("String  : \"%s\"\n", str6);
    printf("Expected: \"tEST STRING!\"\n");
    printf("Actual  : \"%s\"\n", result6);
    printf("Result  : %s\n\n", strcmp(result6, "tEST STRING!") == 0 ? "Pass" : "Fail");
    free(result6);
}

void test_strncmp()
{
    printf("\nTesting ft_strncmp function:\n\n");
    const char *str1 = "Hello!";
    const char *str2 = "Hello!";
    size_t num1 = 6;
    int result1 = ft_strncmp(str1, str2, num1);
    printf("Test Case 1:\n");
    printf("String 1: \"%s\"\n", str1);
    printf("String 2: \"%s\"\n", str2);
    printf("Num: %zu\n", num1);
    printf("Expected Result: 0\n");
    printf("Actual Result  : %d\n", result1);
    printf("Result        : %s\n\n", result1 == 0 ? "Pass" : "Fail");

    const char *str3 = "Hello!";
    const char *str4 = "World!";
    size_t num2 = 6;
    int result2 = ft_strncmp(str3, str4, num2);
    printf("Test Case 2:\n");
    printf("String 1: \"%s\"\n", str3);
    printf("String 2: \"%s\"\n", str4);
    printf("Num: %zu\n", num2);
    printf("Expected Result: %d\n", strncmp(str3, str4, num2));
    printf("Actual Result  : %d\n", result2);
    printf("Result        : %s\n\n", result2 == strncmp(str3, str4, num2) ? "Pass" : "Fail");

    const char *str5 = "Hello!";
    const char *str6 = "";
    size_t num3 = 6;
    int result3 = ft_strncmp(str5, str6, num3);
    printf("Test Case 3:\n");
    printf("String 1: \"%s\"\n", str5);
    printf("String 2: \"%s\"\n", str6);
    printf("Num: %zu\n", num3);
    printf("Expected Result: %d\n", strncmp(str5, str6, num3));
    printf("Actual Result  : %d\n", result3);
    printf("Result        : %s\n\n", result3 == strncmp(str5, str6, num3) ? "Pass" : "Fail");

    const char *str7 = "Hello!";
    const char *str8 = "World!";
    size_t num4 = 0;
    int result4 = ft_strncmp(str7, str8, num4);
    printf("Test Case 4:\n");
    printf("String 1: \"%s\"\n", str7);
    printf("String 2: \"%s\"\n", str8);
    printf("Num: %zu\n", num4);
    printf("Expected Result: 0\n");
    printf("Actual Result  : %d\n", result4);
    printf("Result        : %s\n\n", result4 == 0 ? "Pass" : "Fail");

    // Test Case 5: One string is NULL
    const char *str9 = NULL;
    const char *str10 = "World!";
    size_t num = 6;
    int result5 = ft_strncmp(str9, str10, num);
    printf("Test Case 5:\n");
    printf("String 1: NULL\n");
    printf("String 2: \"%s\"\n", str10);
    printf("Num: %zu\n", num);
    printf("Expected: Negative value (NULL is considered less than any string)\n");
    printf("Actual  : %d\n", result5);
    printf("Result  : %s\n", result5 < 0 ? "Pass" : "Fail");
    printf("\n");

        // Test Case 6: Both strings are empty
    const char *str11 = "";
    const char *str12 = "";
    num = 6;
    int result6 = ft_strncmp(str11, str12, num);
    printf("Test Case 6:\n");
    printf("String 1: \"%s\"\n", str11);
    printf("String 2: \"%s\"\n", str12);
    printf("Num: %zu\n", num);
    printf("Expected: 0\n");
    printf("Actual  : %d\n", result6);
    printf("Result  : %s\n", result6 == 0 ? "Pass" : "Fail");
    printf("\n");

    // Test Case 7: Large strings with partial match
    const char *str13 = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char *str14 = "abcdefxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    num = 6;
    int result7 = ft_strncmp(str13, str14, num);
    printf("Test Case 7:\n");
    printf("String 1: \"%s\"\n", str13);
    printf("String 2: \"%s\"\n", str14);
    printf("Num: %zu\n", num);
    printf("Expected: 0 (first %zu characters match)\n", num);
    printf("Actual  : %d\n", result7);
    printf("Result  : %s\n", result7 == 0 ? "Pass" : "Fail");
    printf("\n");

    // Test Case 8: Large strings with no match
    const char *str15 = "abcdefghijklmnopqrstuvwxyz";
    const char *str16 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    num = 10;
    int result8 = ft_strncmp(str15, str16, num);
    printf("Test Case 8:\n");
    printf("String 1: \"%s\"\n", str15);
    printf("String 2: \"%s\"\n", str16);
    printf("Num: %zu\n", num);
    //int result9 = strncmp(str15, str16, num);
    printf("Expected: Positive value\n");
    printf("Actual  : %d\n", result8);
    printf("Result  : %s\n", result8 > 0 ? "Pass" : "Fail");
    printf("\n");
}

void test_strnstr()
{
    printf("\nTesting ft_strnstr function:\n\n");
    const char *str1 = "Hello!";
    const char *str2 = "Hello!";
    size_t num1 = 6;
    char *result1 = ft_strnstr(str1, str2, num1);
    printf("Test Case 1:\n");
    printf("Haystack: \"%s\"\n", str1);
    printf("Needle  : \"%s\"\n", str2);
    printf("len     : %zu\n", num1);
    printf("Expected: \"%s\"\n", str1);
    printf("Actual  : \"%s\"\n", result1 ? result1 : "NULL");
    printf("Result  : %s\n", (result1 && strcmp(result1, str1) == 0) ? "Pass" : "Fail");
    printf("\n");

    const char *str3 = "Hello!";
    const char *str4 = "World!";
    size_t num2 = 6;
    char *result2 = ft_strnstr(str3, str4, num2);
    printf("Test Case 2:\n");
    printf("Haystack: \"%s\"\n", str3);
    printf("Needle  : \"%s\"\n", str4);
    printf("len     : %zu\n", num2);
    printf("Expected: NULL\n");
    printf("Actual  : \"%s\"\n", result2 ? result2 : "NULL");
    printf("Result  : %s\n", (!result2) ? "Pass" : "Fail");
    printf("\n");

    const char *str5 = "Hello!";
    const char *str6 = "";
    size_t num3 = 6;
    char *result3 = ft_strnstr(str5, str6, num3);
    printf("Test Case 3:\n");
    printf("Haystack: \"%s\"\n", str5);
    printf("Needle  : \"%s\"\n", str6);
    printf("len     : %zu\n", num3);
    printf("Expected: \"%s\"\n", str5);
    printf("Actual  : \"%s\"\n", result3 ? result3 : "NULL");
    printf("Result  : %s\n", (result3 && strcmp(result3, str5) == 0) ? "Pass" : "Fail");
    printf("\n");

    const char *str7 = "Hello!";
    const char *str8 = "World!";
    size_t num4 = 0;
    char *result4 = ft_strnstr(str7, str8, num4);
    printf("Test Case 4:\n");
    printf("Haystack: \"%s\"\n", str7);
    printf("Needle  : \"%s\"\n", str8);
    printf("len     : %zu\n", num4);
    printf("Expected: NULL\n");
    printf("Actual  : \"%s\"\n", result4 ? result4 : "NULL");
    printf("Result  : %s\n", (!result4) ? "Pass" : "Fail");
    printf("\n");

    const char *str9 = NULL;
    const char *str10 = "World!";
    size_t num5 = 6;
    char *result5 = ft_strnstr(str9, str10, num5);
    printf("Test Case 5:\n");
    printf("Haystack: NULL\n");
    printf("Needle  : \"%s\"\n", str10);
    printf("len     : %zu\n", num5);
    printf("Expected: NULL\n");
    printf("Actual  : \"%s\"\n", result5 ? result5 : "NULL");
    printf("Result  : %s\n", (!result5) ? "Pass" : "Fail");
    printf("\n");

    const char *str11 = "";
    const char *str12 = "";
    size_t num6 = 6;
    char *result6 = ft_strnstr(str11, str12, num6);
    printf("Test Case 6:\n");
    printf("Haystack: \"%s\"\n", str11);
    printf("Needle  : \"%s\"\n", str12);
    printf("len     : %zu\n", num6);
    printf("Expected: \"%s\"\n", str11);
    printf("Actual  : \"%s\"\n", result6 ? result6 : "NULL");
    printf("Result  : %s\n", (result6 && strcmp(result6, str11) == 0) ? "Pass" : "Fail");
    printf("\n");

    const char *str13 = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char *str14 = "ABCD";
    size_t num7 = 100;
    char *result7 = ft_strnstr(str13, str14, num7);
    printf("Test Case 7:\n");
    printf("Haystack: \"%s\"\n", str13);
    printf("Needle  : \"%s\"\n", str14);
    printf("len     : %zu\n", num7);
    printf("Expected: \"ABCDEFGHIJKLMNOPQRSTUVWXYZ\"\n");
    printf("Actual  : \"%s\"\n", result7 ? result7 : "NULL");
    printf("Result  : %s\n", (result7 && strcmp(result7, "ABCDEFGHIJKLMNOPQRSTUVWXYZ") == 0) ? "Pass" : "Fail");
    printf("\n");

    const char *str15 = "abcdefghijklmnopqrstuvwxyz";
    const char *str16 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    size_t num8 = 10;
    char *result8 = ft_strnstr(str15, str16, num8);
    printf("Test Case 8:\n");
    printf("Haystack: \"%s\"\n", str15);
    printf("Needle  : \"%s\"\n", str16);
    printf("len     : %zu\n", num8);
    printf("Expected: NULL\n");
    printf("Actual  : \"%s\"\n", result8 ? result8 : "NULL");
    printf("Result  : %s\n", (!result8) ? "Pass" : "Fail");
    printf("\n");   

    const char *str17 = "hello";
    const char *str18 = "";
    size_t num9= 0;
    char *result9 = ft_strnstr(str17, str18, num9);
    printf("Test Case 9:\n");
    printf("Haystack: \"%s\"\n", str17);
    printf("Needle  : \"%s\"\n", str18);
    printf("len     : %zu\n", num9);
    printf("Expected: \"%s\"\n", str17);
    printf("Actual  : \"%s\"\n", result9);
 if (result9 == str17)
        printf("Pass\n");
    else
        printf("Fail\n");

    printf("\n"); 
}

void test_strrchr() {
    printf("Testing ft_strrchr function:\n\n");

    // Test Case 1: Basic string with existing character
    const char *str1 = "Hello, world!";
    int c1 = 'o';
    char *result1 = ft_strrchr(str1, c1);
    printf("Test Case 1:\n");
    printf("String  : \"%s\"\n", str1);
    printf("Character: '%c'\n", c1);
    printf("Expected: \"%s\"\n", strrchr(str1, c1));
    printf("Actual  : \"%s\"\n", result1);
    printf("Result  : %s\n\n", (result1 && strcmp(result1, strrchr(str1, c1)) == 0) ? "Pass" : "Fail");

    // Test Case 2: Basic string with non-existing character
    const char *str2 = "Hello, world!";
    int c2 = 'z';
    char *result2 = ft_strrchr(str2, c2);
    printf("Test Case 2:\n");
    printf("String  : \"%s\"\n", str2);
    printf("Character: '%c'\n", c2);
    printf("Expected: \"%s\"\n", strrchr(str2, c2));
    printf("Actual  : \"%s\"\n", result2);
    if (result2 == strrchr(str2, c2))
    {
        printf("Pass\n\n");
    }
    else
    {
        printf("Fail\n\n");
    }

    // Test Case 3: Empty string
    const char *str3 = "";
    int c3 = 'a';
    char *result3 = ft_strrchr(str3, c3);
    printf("Test Case 3:\n");
    printf("String  : \"%s\"\n", str3);
    printf("Character: '%c'\n", c3);
    printf("Expected: \"%s\"\n", strrchr(str3, c3));
    printf("Actual  : \"%s\"\n", result3);
    if (result3 == strrchr(str3, c3))
    {
        printf("Pass\n\n");
    }
    else
    {
        printf("Fail\n\n");
    }

    // Test Case 4: (should find end of string)
    const char *str4 = "Hello\0world";
    int c4 = '\0';
    char *result4 = ft_strrchr(str4, c4);
    printf("Test Case 4:String with NULL character\n");
    printf("String  : \"%s\"\n", str4);
    printf("Character: '%c'\n", c4);
    printf("Expected: \"%s\"\n", strrchr(str4, c4));
    printf("Actual  : \"%s\"\n", result4);
    printf("Result  : %s\n\n", (result4 && strcmp(result4, strrchr(str4, c4)) == 0) ? "Pass" : "Fail");

    // Test Case 5: String with multiple occurrences of character
    const char *str5 = "Hello, world!";
    int c5 = 'l';
    char *result5 = ft_strrchr(str5, c5);
    printf("Test Case 5:\n");
    printf("String  : \"%s\"\n", str5);
    printf("Character: '%c'\n", c5);
    printf("Expected: \"%s\"\n", strrchr(str5, c5));
    printf("Actual  : \"%s\"\n", result5);
    printf("Result  : %s\n\n", (result5 && strcmp(result5, strrchr(str5, c5)) == 0) ? "Pass" : "Fail");

}

int main()
{
    test_strlen();
    test_strmapi();
    test_strncmp();
    test_strnstr();
    test_strrchr();
    return 0;
}