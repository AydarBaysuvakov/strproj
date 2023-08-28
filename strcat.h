/// @brief Appends a copy of the null-terminated byte string pointed to by src to the end of the null-terminated byte string pointed to by dest. The character src[0] replaces the null terminator at the end of dest. The resulting byte string is null-terminated.
/// @param dest pointer to the null-terminated byte string to append to.
/// @param src pointer to the null-terminated byte string to copy from
/// @return a copy of dest
char *strcat_( char *dest, const char *src );
