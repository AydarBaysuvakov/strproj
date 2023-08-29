/// @brief Returns a pointer to a null-terminated byte string, which is a duplicate of the string pointed to by src. The space for the new string is obtained as if the malloc was invoked. The returned pointer must be passed to free to avoid a memory leak.
/// @param src pointer to the null-terminated byte string to duplicate.
/// @return A pointer to the newly allocated string, or a null pointer if an error occurred.
char *strdup_( const char *src );
