#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "myStrLib.h"
#include "colour.h"
#include "test.h"

TestFeedback test_strlen(const char* str)
    {
    assert(str != NULL);

    int len = strlen_(str), lenRef = strlen(str);

    if (len != lenRef)
        {
        ColouredPrintf(RED, "STR: %s\nERROR: len = %d\nEXCEPTED:  len = %d\n\n", str, len, lenRef);
        return TEST_FAILED;
        }
    else
        {
        ColouredPrintf(GREEN, "OK\n");
        return TEST_ACEPTED;
        }
    }

TestFeedback test_strchr(const char* str, int ch)
    {
    assert(str != NULL);

    const char *ptr = strchr_(str, ch);
    const char *ptrRef = strchr(str, ch);

    if (ptr != ptrRef)
        {
        ColouredPrintf(RED, "STR: %s\tCHAR: %c\nERROR: str = %d\nEXCEPTED: str = %d\n\n", str, ch, ptr, ptrRef);
        return TEST_FAILED;
        }
    else
        {
        ColouredPrintf(GREEN, "OK\n");
        return TEST_ACEPTED;
        }
    }

TestFeedback test_strcpy(const char *src)
    {
    assert(src != NULL);

    int len = strlen(src);
    char dest[len + 1] = "";
    char destRef[len + 1] = "";

    if (strcmp(strcpy_(dest, src), strcpy(destRef, src)))
        {
        ColouredPrintf(RED, "ERROR: dest = %s\nEXCEPTED: dest = %s\n\n", dest, destRef);
        return TEST_FAILED;
        }
    else
        {
        ColouredPrintf(GREEN, "OK\n");
        return TEST_ACEPTED;
        }
    }

TestFeedback test_strncpy(const char *src, size_t count)
    {
    assert(src != NULL);

    char dest[count] = "";
    char destRef[count] = "";

    if (strcmp(strncpy_(dest, src, count), strncpy(destRef, src, count)))
        {
        ColouredPrintf(RED, "ERROR: dest = %s\nEXCEPTED: dest = %s\n\n", dest, destRef);
        return TEST_FAILED;
        }
    else
        {
        ColouredPrintf(GREEN, "OK\n");
        return TEST_ACEPTED;
        }
    }

TestFeedback test_strcat(const char *dest_example, const char *src)
    {
    assert(src != NULL);
    assert(dest_example != NULL);

    int len = strlen(src) + strlen(dest_example);
    char dest[len + 1] = "";
    char destRef[len + 1] = "";
    strcpy(dest, dest_example);
    strcpy(destRef, dest_example);

    if (strcmp(strcat_(dest, src), strcat(destRef, src)))
        {
        ColouredPrintf(RED, "ERROR: dest = %s\nEXCEPTED: dest = %s\n\n", dest, destRef);
        return TEST_FAILED;
        }
    else
        {
        ColouredPrintf(GREEN, "OK\n");
        return TEST_ACEPTED;
        }
    }

TestFeedback test_strncat(const char *dest_example, const char *src, size_t count)
    {
    assert(src != NULL);
    assert(dest_example != NULL);

    int len = strlen(dest_example);
    char dest[len + count + 1] = "";
    char destRef[len + count + 1] = "";
    strcpy(dest, dest_example);
    strcpy(destRef, dest_example);

    if (strcmp(strncat_(dest, src, count), strncat(destRef, src, count)))
        {
        ColouredPrintf(RED, "ERROR: dest = %s\nEXCEPTED: dest = %s\n\n", dest, destRef);
        return TEST_FAILED;
        }
    else
        {
        ColouredPrintf(GREEN, "OK\n");
        return TEST_ACEPTED;
        }
    }

TestFeedback test_strdup(const char *str)
    {
    assert(str != NULL);

    char *dup = strdup_(str), *dupRef = strdup(str);

    if (strcmp(dup, dupRef))
        {
        ColouredPrintf(RED, "ERROR: dup = %s\nEXCEPTED: dup = %s\n\n", dup, dupRef);
        return TEST_FAILED;
        }
    else
        {
        ColouredPrintf(GREEN, "OK\n");
        return TEST_ACEPTED;
        }
    }

TestFeedback test_strstr(const char *str, const char *substr)
    {
    assert(str != NULL);
    assert(substr != NULL);

    const char *res = strstr_(str, substr), *resRef = strstr(str, substr);

    if ((res == NULL && res == resRef) || !strcmp(res, resRef))
        {
        ColouredPrintf(GREEN, "OK\n");
        return TEST_ACEPTED;
        }
    else
        {
        ColouredPrintf(RED, "ERROR: res = %s\nEXCEPTED: res = %s\n\n", res, resRef);
        return TEST_FAILED;
        }
    }

TestFeedback test_fgets(int count, const char* file)
    {
    assert(file != NULL);

    FILE *fp;
    fp = fopen(file, "r");

    char res[count + 1] = "";
    char resRef[count + 1] = "";
    fgets_(res, count, fp);

    fp = freopen(file, "r", fp);
    fgets(resRef, count, fp);

    if (!strcmp(res, resRef))
        {
        ColouredPrintf(GREEN, "OK\n");
        return TEST_ACEPTED;
        }
    else
        {
        ColouredPrintf(RED, "ERROR: res = %s\nEXCEPTED: res = %s\n\n", res, resRef);
        return TEST_FAILED;
        }
    }

TestFeedback test_getline(int n, const char* file)
    {
    assert(file != NULL);

    FILE *fp;
    fp = fopen(file, "r");
    size_t count = n, countRef = n;
    char *res = (char*) calloc(n, sizeof(char));
    char *resRef = (char*) calloc(n, sizeof(char));

    if (!n)
        {
        res = nullptr;
        resRef = nullptr;
        }

    int len = getline_(&res, &count, fp);
    fp = freopen(file, "r", fp);
    int lenRef = getline(&resRef, &countRef, fp);

    if (!strcmp(res, resRef) && (len == lenRef))
        {
        ColouredPrintf(GREEN, "OK\n");
        return TEST_ACEPTED;
        }
    else
        {
        ColouredPrintf(RED, "ERROR: res = %s, count = %d, len = %d\nEXCEPTED: res = %s, count = %d, len = %d\n\n",
        res, count, len, resRef, countRef, lenRef);
        return TEST_FAILED;
        }
    }

int TestAll()
    {
    // #define
    // RUN_TEST(test_strlen, "...");

    // Чтобы не писать сообщения
    // ls --verbose
    //PrintfVerbose()



    int nTestAcepted = 0;

    // strlen
    nTestAcepted += test_strlen("Hello world!");
    nTestAcepted += test_strlen("");
    nTestAcepted += test_strlen("    ");
    nTestAcepted += test_strlen("absd121\0gfdhgfd");

    // strchr
    nTestAcepted += test_strchr("Hello world!", 'H');
    nTestAcepted += test_strchr("Hello world!", 'w');
    nTestAcepted += test_strchr("Hello world!", ' ');
    nTestAcepted += test_strchr("Hello world!", 'k');

    // strcpy
    nTestAcepted += test_strcpy("Hello world!");
    nTestAcepted += test_strcpy("");
    nTestAcepted += test_strcpy("    ");
    nTestAcepted += test_strcpy("absd121\0gfdhgfd");

    // strncpy
    nTestAcepted += test_strncpy("Hello world!", 8);
    nTestAcepted += test_strncpy("Hello world!", 40);
    nTestAcepted += test_strncpy("", 0);
    nTestAcepted += test_strncpy("", 5);
    nTestAcepted += test_strncpy("    ", 2);
    nTestAcepted += test_strncpy("    ", 4);
    nTestAcepted += test_strncpy("    ", 6);
    nTestAcepted += test_strncpy("absd121\0gfdhgfd", 5);
    nTestAcepted += test_strncpy("absd121\0gfdhgfd", 10);
    nTestAcepted += test_strncpy("absd121\0gfdhgfd", 20);

    // strcat
    nTestAcepted += test_strcat("Hello ", "world!");
    nTestAcepted += test_strcat("", "");
    nTestAcepted += test_strcat("    ", "Hi!");
    nTestAcepted += test_strcat("absd121\0gfdhgfd", "asafd");

    // strncat
    nTestAcepted += test_strncat("Hello ", "world!", 3);
    nTestAcepted += test_strncat("Hello ", "world!", 30);
    nTestAcepted += test_strncat("", "", 0);
    nTestAcepted += test_strncat("", "", 5);
    nTestAcepted += test_strncat("  ", "    ", 2);
    nTestAcepted += test_strncat("  ", "    ", 4);
    nTestAcepted += test_strncat("  ", "    ", 6);

    // strdup
    nTestAcepted += test_strdup("Hello world!");
    nTestAcepted += test_strdup("");
    nTestAcepted += test_strdup("    ");
    nTestAcepted += test_strdup("absd121\0gfdhgfd");

    // strstr
    nTestAcepted += test_strstr("Hello world!", "world");
    nTestAcepted += test_strstr("Hello world!", "Hello");
    nTestAcepted += test_strstr("Hello world!", "o");
    nTestAcepted += test_strstr("Hello world!", "!");
    nTestAcepted += test_strstr("Hello world!", "");
    nTestAcepted += test_strstr("Hello world!", "bye");
    nTestAcepted += test_strstr("Hello world!", "j");
    nTestAcepted += test_strstr("aaaaaaaaaaaaaa", "aaaaaaaa");
    nTestAcepted += test_strstr("aaaaabbbbbbbbbbb", "bbbbb");
    nTestAcepted += test_strstr("aaabbbccc", "bbbb");
    nTestAcepted += test_strstr("chachachack", "chack");

    // fgets
    nTestAcepted += test_fgets(10, "testfile.txt");
    nTestAcepted += test_fgets(20, "testfile.txt");

    // getline
    nTestAcepted += test_getline(10, "testfile.txt");
    nTestAcepted += test_getline(0, "testfile.txt");

    ColouredPrintf(YELLOW, "%d tests acepted\n", nTestAcepted);

    return nTestAcepted;
    }
