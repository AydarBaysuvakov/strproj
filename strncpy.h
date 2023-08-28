/// @brief Copies at most count characters of the character array pointed to by src (including the terminating null character, but not any of the characters that follow the null character) to character array pointed to by dest.
/// @param dest pointer to the character array to copy to
/// @param src pointer to the character array to copy from
/// @param count maximum number of characters to copy
/// @return a copy of dest
char *strncpy_( char *dest, const char *src, size_t count );
