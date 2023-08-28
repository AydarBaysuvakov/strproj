/// @brief Appends at most count characters from the character array pointed to by src, stopping if the null character is found, to the end of the null-terminated byte string pointed to by dest. The character src[0] replaces the null terminator at the end of dest. The terminating null character is always appended in the end (so the maximum number of bytes the function may write is count+1).
/// @param dest pointer to the null-terminated byte string to append to.
/// @param src pointer to the character array to copy from.
/// @param count maximum number of characters to copy.
/// @return a copy of dest
char *strncat_( char *dest, const char *src, size_t count );
