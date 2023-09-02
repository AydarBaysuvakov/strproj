enum TestFeedback
    {
    TEST_FAILED  = 0,
    TEST_ACEPTED = 1
    };

TestFeedback test_strchr(const char* str, int ch);

TestFeedback test_strlen(const char* str);

TestFeedback test_strcpy(const char *src);

TestFeedback test_strncpy(const char *src, size_t count);

TestFeedback test_strcat(const char *dest_example, const char *src);

TestFeedback test_strncat(const char *dest_example, const char *src, size_t count);

TestFeedback test_strdup(const char *str);

TestFeedback test_fgets(int count, const char *file);

TestFeedback test_getline(int n, const char *file);

TestFeedback test_strstr(const char *str, const char *substr);

int TestAll();
